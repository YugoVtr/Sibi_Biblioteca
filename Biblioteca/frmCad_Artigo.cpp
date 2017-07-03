#include<frmConsultaArtigo.h>
#include "frmCad_Artigo.h"
#include "ui_frmCad_Artigo.h"
#include <QMessageBox>
#include <Artigo.h>
#include <PersistenciaArtigo.h>
#include <QInputDialog>
#include <Autor.h>
#include <PersistenciaAutor.h>
#include <frmCad_Autor.h>
#include <QString>
#include <QStringList>
#include <QTime>
#include <QRegExp>
#include "PersistenciaExemplar.h"


frmCad_Artigo::frmCad_Artigo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmCad_Artigo)
{
    ui->setupUi(this);
    try
    {
        persistirArtigo.setNomeDoArquivoNoDisco("../Arquivos/arquivoArtigo.txt");
        persistirAutor.setNomeDoArquivoNoDisco("../Arquivos/arquivoAutor.txt");
        persistirArtigoAutor.setNomeDoArquivoNoDisco("../Arquivos/arquivoLinkArtigoAutor.txt");

        //Deixa a lateral das linhas invisiveis
        ui->tableWidget->verticalHeader()->setVisible(false);

        this->setWindowFlags(Qt::WindowMinimizeButtonHint);
        this->setWindowFlags(Qt::WindowCloseButtonHint);

        //exibe os autores na combobox
        exibeAutores();

        QRegExp reg("[0-9]*");
        QRegExpValidator *validar = new QRegExpValidator(reg);
        ui->LineEditAnoPublicacao->setValidator(validar);
        ui->LineEditCodigoAutor->setValidator(validar);

        this->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,this->size(),qApp->desktop()->availableGeometry()));
    }
    catch(QString &erro){QMessageBox::information(this,"Titulo",erro);}

}

frmCad_Artigo::~frmCad_Artigo()
{
    delete ui->LineEditCodigoAutor->validator();
    delete ui->LineEditAnoPublicacao->validator();
    delete ui;
}

void frmCad_Artigo::on_pushButtonSair_clicked()
{
    if(QMessageBox::question(this,"Autor","Deseja sair?",
                             QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes)
        this->close();
}

void frmCad_Artigo::limpar()
{
    ui->LineEditArea->clear();
    ui->LineEditTitulo->clear();
    ui->LineEditAnoPublicacao->clear();
    if(ui->tableWidget->rowCount())
    {
        for(int i=0; i< ui->tableWidget->rowCount(); i++)
            delete ui->tableWidget->item(i,0);
        ui->tableWidget->setRowCount(0);
    }
}

void frmCad_Artigo::on_LineEditCodigoAutor_returnPressed()
{
    try
    {
        if(ui->LineEditCodigoAutor->text().toInt() > 0)
        {
            QString str = persistirAutor.consultar(ui->LineEditCodigoAutor->text().toInt());
            if(str != "0")                                                      //retorna a posicao do autor
                ui->comboBoxNomeAutores->setCurrentIndex(listaAutores->indexOf(Mumu::Autor(str) ) );
            else
                ui->LineEditCodigoAutor->clear();
        }
    }
    catch(QString &erro){QMessageBox::information(this,"CADASTRO DE AUTOR",erro);}
}

void frmCad_Artigo::on_pushButtonInserirAutor_clicked()
{
    try
    {
        if(persistirAutor.consultar(ui->LineEditCodigoAutor->text().toInt()) != "0")
        {
            on_LineEditCodigoAutor_returnPressed();
            int proximaLinha = ui->tableWidget->currentRow() + 1;

            for(int i  = 0; i < ui->tableWidget->rowCount(); i++)
                if(ui->LineEditCodigoAutor->text() == ui->tableWidget->item(i,0)->text())
                    throw QString ("Esse autor ja existe neste artigo!");

            ui->tableWidget->insertRow(proximaLinha);
            //seta os itens
            ui->tableWidget->setItem(proximaLinha,0, new QTableWidgetItem(ui->LineEditCodigoAutor->text( ) ) );
            ui->tableWidget->setItem(proximaLinha,1,new QTableWidgetItem(ui->comboBoxNomeAutores->currentText() ) );

            //alinha os textos dos itens
            ui->tableWidget->item(proximaLinha,0)->setTextAlignment(Qt::AlignRight);
            ui->tableWidget->item(proximaLinha,1)->setTextAlignment(Qt::AlignLeft);

            //muda a font dos itens
            ui->tableWidget->item(proximaLinha,0)->setFont(QFont("Bold"));
            ui->tableWidget->item(proximaLinha,1)->setFont(QFont("Bold"));

            //Seleciona toda linha da GRID
            ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        }
    }
    catch(QString &erro){QMessageBox::information(this,"CADASTRO DE ARTIGO",erro);}
}

void frmCad_Artigo::on_toolButtonChamarTelaCadAutor_clicked()
{
    try
    {
        janelaAutor.exec();
        ui->comboBoxNomeAutores->clear();
        exibeAutores();
    }
    catch(std::bad_alloc& ){QMessageBox::information(this,"CADASTRO DE ARTIGO","Nao a memoria suficiente para executar essa acao!"
                                                                               "\n DESTRUA SEU PC");}
    catch(...){QMessageBox::critical(this,"CADASTRO DE ARTIGO","Erro inesperado!!");}
}

void frmCad_Artigo::on_pushButtonLimpar_clicked()
{
    limpar();
}

void frmCad_Artigo::on_pushButtonRetirarAutor_clicked()
{
    for(int i  = 0; i < ui->tableWidget->rowCount(); i++)
        if(ui->LineEditCodigoAutor->text() == ui->tableWidget->item(i,0)->text())
            ui->tableWidget->removeRow(i);
}


void frmCad_Artigo::on_pushButtonConsultar_clicked()
{
    frmConsultaArtigo janela;
    janela.exec();
}

void frmCad_Artigo::on_comboBoxNomeAutores_currentIndexChanged(int index)
{
    if(index > 0)
        ui->LineEditCodigoAutor->setText(QString::number(listaAutores->at(index).getCodigo( ) ) );
}

void frmCad_Artigo::exibeAutores()
{
    try
    {
        listaAutores =  persistirAutor.listagem();
        if(listaAutores->size() > 0)
            for(int i = 0; i < listaAutores->size(); i++)
                ui->comboBoxNomeAutores->addItem(listaAutores->at(i).getNome());
    }
    catch(QString &erro){QMessageBox::information(this,"Titulo",erro);}
}




void frmCad_Artigo::on_pushButtonGravar_clicked()
{
    try
    {
        //verifica se existe algum autor no artigo
        if(ui->tableWidget->rowCount() <= 0)
            throw QString ("E obrigatrio ter no minimo um autor no artigo");

        //Primeira gravacao
        //cria o artigo
        Mumu::Artigo artigo;
        artigo.setCodigo(Vitor::Codigo().gerarCodigo());
        artigo.setArea(ui->LineEditArea->text());
        artigo.setTitulo(ui->LineEditTitulo->text());
        artigo.setAnoPublicacao(ui->LineEditAnoPublicacao->text().toInt());
        if(persistirArtigo.consultar(artigo.getCodigo()) == "0")
        {
            Mumu::ArtigoAutor artigoAutor;

            QString des = QString::number(artigo.getCodigo());
            des += " ";
            des += artigo.getTitulo();
            des += " ";
            des += artigo.getArea();
            des += " ";
            des += QString::number(artigo.getAnoPublicacao())+" ";

            //insere todas as linkagens do artigo com os autores
            int i;
            for(i = 0; i < ui->tableWidget->rowCount(); i++)
            {
                artigoAutor.setCodigoArtigo(artigo.getCodigo());
                artigoAutor.setCodigoAutor(ui->tableWidget->item(i,0)->text().toInt());
                persistirArtigoAutor.incluir(artigoAutor);
                if(i<=2) des += ui->tableWidget->item(i,1)->text()+" ";
            }
            persistirArtigo.incluir(artigo);
            if(i>2) des += " at al";


            Biblioteca::PersistenciaExemplar exemplarPer("../Arquivos/arquivoExemplar.txt");

            Biblioteca::Exemplar exemplar;
            exemplar.setCodigo(Vitor::Codigo().gerarCodigo());
            exemplar.setNumeroDoExemplar(1);
            exemplar.setCirculavel(1);
            exemplar.setStatus(1);
            exemplar.setDescricao(des);
            exemplarPer.incluir(exemplar);
        }
        //alteracao
        else
        {
            throw QString("Artigo já existe");
        }
        QMessageBox::information(this,"Artigo","Dados gravados!");
        limpar( );
    }
    catch(QString &erro) {QMessageBox::information(this,"CADASTRO DE AUTOR",erro);}
}

