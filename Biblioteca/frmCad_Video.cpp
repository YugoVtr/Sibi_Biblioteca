#include "frmCad_Video.h"
#include "ui_frmCad_Video.h"
#include <QMessageBox>
#include <Video.h>
#include <QStringList>
#include <frmConsultaVideo.h>
#include <QRegExp>
#include "PersistenciaExemplar.h"

frmCad_Video::frmCad_Video(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmCad_Video)
{
    ui->setupUi(this);
    persistir.setNomeDoArquivoNoDisco("../Arquivos/arquivoVideo.txt");
    //coloca apenas o btn de saida no frm
    this->setWindowFlags(Qt::WindowCloseButtonHint);
    QRegExp reg("[0-9]*");
    QRegExpValidator *validar = new QRegExpValidator(reg);
    ui->LineEditTempoDuracao->setValidator(validar);
    ui->LineEditAnoProducao->setValidator(validar);
    this->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,this->size(),qApp->desktop()->availableGeometry()));
}

frmCad_Video::~frmCad_Video()
{
    delete ui->LineEditAnoProducao->validator();
    delete ui->LineEditTempoDuracao->validator();
    delete ui;
}

void frmCad_Video::on_pushButtonGravar_clicked()
{
    try
    {
        Mumu::Video video;
        video.setAnoDeProducao(ui->LineEditAnoProducao->text().toInt());
        video.setCodigo(Vitor::Codigo().gerarCodigo());
        video.setGenero(ui->LineEditGenero->text());
        video.setProdutora(ui->LineEditProdutora->text());
        video.setTempoDeDuracao(ui->LineEditTempoDuracao->text().toInt());
        video.setTitulo(ui->LineEditTitulo->text());
        persistir.incluir(video);

        QString des = QString::number(video.getCodigo())+" ";
        des += QString::number(video.getAnoDeProducao())+" ";
        des += QString::number(video.getTempoDeDuracao())+" ";
        des += video.getTitulo()+" ";
        des += video.getGenero()+" ";
        des += video.getProdutora();


        Biblioteca::PersistenciaExemplar exemplarPer("../Arquivos/arquivoExemplar.txt");

        Biblioteca::Exemplar exemplar;
        exemplar.setCodigo(Vitor::Codigo().gerarCodigo());
        exemplar.setNumeroDoExemplar(1);
        exemplar.setCirculavel(1);
        exemplar.setStatus(1);
        exemplar.setDescricao(des);
        exemplarPer.incluir(exemplar);
//        int qtdExemplar;
//        for(int i=1;i<qtdExemplares;i++)
//        {
//            Biblioteca::Exemplar aux(Vitor::Codigo().gerarCodigo(),1,1,i+1,des);
//            exemplarPer.incluir(aux);
//        }


        QMessageBox::information(this,"Video","Dados gravados!");
        limpar();
    }catch(QString &erro){
        QMessageBox::information(this,"Autor",erro);
    }
}


void frmCad_Video::on_pushButtonSair_clicked()
{
    if(QMessageBox::question(this,"Autor","Deseja sair?",
                             QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes)
        this->close();
}

void frmCad_Video::limpar()
{
    ui->LineEditAnoProducao->clear();
    ui->LineEditAnoProducao->clear();
    ui->LineEditProdutora->clear();
    ui->LineEditTempoDuracao->clear();
    ui->LineEditTitulo->clear();
    ui->LineEditGenero->clear();
}


void frmCad_Video::on_pushButtonLimpar_clicked()
{
        if(QMessageBox::information(this,"Cadastro Autor","Deseja limpar os dados ?",QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel) == QMessageBox::Yes)
            limpar();
}

void frmCad_Video::on_pushButtonConsultar_clicked()
{
    frmConsultaVideo janela;
    janela.setModal(true);
    janela.exec();
}
