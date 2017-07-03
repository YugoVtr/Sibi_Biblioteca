#include "frmConsultaAcervo.h"
#include "ui_frmConsultaAcervo.h"
#include "PersistenciaLivro.h"
#include "PersistenciaRevista.h"
#include "PersistenciaArtigo.h"
#include "PersistenciaVideo.h"
#include "PersistenciaEditora.h"
#include "PersistenciaAutor.h"

frmConsultaAcervo::frmConsultaAcervo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmConsultaAcervo)
{
    ui->setupUi(this);
    Biblioteca::PersistenciaLivro livroPersistencia("../Arquivos/arquivoLivro.txt");
    Biblioteca::PersistenciaRevista revistaPersistencia("../Arquivos/arquivoRevista.txt");
    Mumu::PersistenciaArtigo artigoPersistencia("../Arquivos/arquivoArtigo.txt");
    Mumu::PersistenciaVideo videoPersistencia("../Arquivos/arquivoVideo.txt");
    Mumu::PersistenciaAutor autorPersistencia("../Arquivos/arquivoAutor.txt");
    Biblioteca::PersistenciaEditora editoraPersistencia("../Arquivos/arquivoEditora.txt");
}

frmConsultaAcervo::~frmConsultaAcervo()
{
    delete ui;
}

void frmConsultaAcervo::on_pesquisarPushButton_clicked()
{
    int pos = ui->filtroDePesquisaComboBox->currentIndex();
    switch(pos)
    {
    case 0:
        consultarTitulo();
        break;
    case 1:
        consultarAutor();
        break;
    case 2:
        consultarEditora();
        break;
    case 3:
        consultarISBN();
        break;
    }
}

void frmConsultaAcervo::consultarTitulo() const
{
    Biblioteca::PersistenciaLivro livroPersistencia("../Arquivos/arquivoLivro.txt");
    Biblioteca::PersistenciaRevista revistaPersistencia("../Arquivos/arquivoRevista.txt");
    Mumu::PersistenciaArtigo artigoPersistencia("../Arquivos/arquivoArtigo.txt");
    Mumu::PersistenciaVideo videoPersistencia("../Arquivos/arquivoVideo.txt");

    limpar();

    QList<Biblioteca::Livro> *listaLivro = livroPersistencia.listagem();
    int i;
    int l=0;
    for(i=0;i<listaLivro->size();i++)
    {
        if(listaLivro->at(i).getTitulo()==ui->pesquisarLineEdit->text())
        {
            ui->tableWidget->insertRow(l);
            ui->tableWidget->setItem(l,1,new QTableWidgetItem(listaLivro->at(i).getTitulo()));
            ui->tableWidget->setItem
                    (l,0,new QTableWidgetItem(QString::number(listaLivro->at(i).getCodigo())));
            l++;
        }
    }

    QList<Biblioteca::Revista> *listaRevista = revistaPersistencia.listagem();
    for(i=0;i<listaRevista->size();i++)
    {
        if(listaRevista->at(i).getTitulo()==ui->pesquisarLineEdit->text())
        {
            ui->tableWidget->insertRow(l);
            ui->tableWidget->setItem(l,1,new QTableWidgetItem(listaRevista->at(i).getTitulo()));
            ui->tableWidget->setItem
                    (l,0,new QTableWidgetItem(QString::number(listaRevista->at(i).getCodigo())));
            l++;
        }
    }

    QList<Mumu::Artigo> *listaArtigo = artigoPersistencia.listagem();
    for(i=0;i<listaRevista->size();i++)
    {
        if(listaArtigo->at(i).getTitulo()==ui->pesquisarLineEdit->text())
        {
            ui->tableWidget->insertRow(l);
            ui->tableWidget->setItem(l,1,new QTableWidgetItem(listaArtigo->at(i).getTitulo()));
            ui->tableWidget->setItem
                    (l,0,new QTableWidgetItem(QString::number(listaArtigo->at(i).getCodigo())));
            l++;
        }
    }

    QList<Mumu::Video> *listaVideo = videoPersistencia.listagem();
    for(i=0;i<listaVideo->size();i++)
    {
        if(listaVideo->at(i).getTitulo()==ui->pesquisarLineEdit->text())
        {
            ui->tableWidget->insertRow(l);
            ui->tableWidget->setItem(l,1,new QTableWidgetItem(listaVideo->at(i).getTitulo()));
            ui->tableWidget->setItem
                    (l,0,new QTableWidgetItem(QString::number(listaVideo->at(i).getCodigo())));
            l++;
        }
    }
}

void frmConsultaAcervo::consultarEditora()const
{
    Biblioteca::PersistenciaEditora editoraPersistencia("../Arquivos/arquivoEditora.txt");

    QList<Biblioteca::Editora> *listaEditora = editoraPersistencia.listagem();
    limpar();
    for(int i=0,l=0;i<listaEditora->size();i++)
    {
        if(listaEditora->at(i).getNome()==ui->pesquisarLineEdit->text())
        {
            ui->tableWidget->insertRow(l);
            ui->tableWidget->setItem(l,0,new QTableWidgetItem(QString::number(listaEditora->at(i).getCodigo())));
            ui->tableWidget->setItem(l,1,new QTableWidgetItem(listaEditora->at(i).getNome()));
            l++;
        }
    }
}

void frmConsultaAcervo::consultarAutor()const
{
    Mumu::PersistenciaAutor autorPersistencia("../Arquivos/arquivoAutor.txt");
    QList<Mumu::Autor> *listaAutor = autorPersistencia.listagem();
    limpar();
    for(int i=0,l=0;i<listaAutor->size();i++)
    {
        if(listaAutor->at(i).getNome()==ui->pesquisarLineEdit->text())
        {
            ui->tableWidget->insertRow(l);
            ui->tableWidget->setItem(l,0,new QTableWidgetItem(QString::number(listaAutor->at(i).getCodigo())));
            ui->tableWidget->setItem(l,1,new QTableWidgetItem(listaAutor->at(i).getNome()));
            l++;
        }
    }
}

void frmConsultaAcervo::consultarISBN()const
{
    Biblioteca::PersistenciaLivro livroPersistencia("../Arquivos/arquivoLivro.txt");
    Biblioteca::PersistenciaRevista revistaPersistencia("../Arquivos/arquivoRevista.txt");

    QList<Biblioteca::Livro> *listaLivro = livroPersistencia.listagem();
    limpar();
    int l=0;
    for(int i=0;i<listaLivro->size();i++)
    {
        if(listaLivro->at(i).getIsbn()==ui->pesquisarLineEdit->text().toLong())
        {
            ui->tableWidget->insertRow(l);
            ui->tableWidget->setItem(l,0,new QTableWidgetItem(QString::number(listaLivro->at(i).getCodigo())));
            ui->tableWidget->setItem(l,1,new QTableWidgetItem(listaLivro->at(i).getTitulo()));
            l++;
        }
    }

    QList<Biblioteca::Revista> *listaRevista = revistaPersistencia.listagem();
    for(int i=0;i<listaRevista->size();i++)
    {
        if(listaRevista->at(i).getIsbn()==ui->pesquisarLineEdit->text().toLong())
        {
            ui->tableWidget->insertRow(l);
            ui->tableWidget->setItem(l,0,new QTableWidgetItem(QString::number(listaRevista->at(i).getCodigo())));
            ui->tableWidget->setItem(l,1,new QTableWidgetItem(listaRevista->at(i).getTitulo()));
            l++;
        }
    }

}

void frmConsultaAcervo::limpar() const
{
    for(int i=0;i<ui->tableWidget->rowCount();i++)
    {
        delete ui->tableWidget->item(i,0);
        delete ui->tableWidget->item(i,1);
    }
    ui->tableWidget->setRowCount(0);
}
