#include "frmConsultaLivro.h"
#include "ui_frmConsultaLivro.h"
#include <QMessageBox>

frmConsultaLivro::frmConsultaLivro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmConsultaLivro)
{
    ui->setupUi(this);
    try {
        Biblioteca::PersistenciaLivro livroPersistencia("../Arquivos/arquivoLivro.txt");
        listaLivro = livroPersistencia.listagem();
        inicializar();
        this->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,this->size(),qApp->desktop()->availableGeometry()));
    } catch(QString &erro) {
        QMessageBox::critical(this,"Erro",erro);
    }
}

frmConsultaLivro::~frmConsultaLivro()
{
    delete ui;
}

void frmConsultaLivro::inicializar() const
{
    ui->tableWidget->setRowCount(listaLivro->size());
    for(int i=0;i<listaLivro->size();i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(listaLivro->at(i).getIsbn())));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(listaLivro->at(i).getAno())));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(listaLivro->at(i).getTitulo()));
    }
}

void frmConsultaLivro::limparGrid() const
{
    int tam = ui->tableWidgetAutor->rowCount();
    for(int i=0;i<tam;i++)
    {
        delete ui->tableWidgetAutor->item(i,0);
        delete ui->tableWidgetAutor->item(i,1);
    }
    ui->tableWidgetAutor->setRowCount(0);

    tam = ui->tableWidgetEditora->rowCount();
    for(int i=0;i<tam;i++)
    {
        delete ui->tableWidgetEditora->item(i,0);
        delete ui->tableWidgetEditora->item(i,1);
        delete ui->tableWidgetEditora->item(i,2);
        delete ui->tableWidgetEditora->item(i,3);
    }
    ui->tableWidgetEditora->setRowCount(0);
}



void frmConsultaLivro::on_tableWidget_cellClicked(int row, int column)
{
    try{
        limparGrid();
        int cod = listaLivro->at(row).getCodigo();


        Biblioteca::PersistenciaLivroAutor livroAutorpersistencia("../Arquivos/arquivoLinkLivroAutor.txt");
        Biblioteca::PersistenciaLivroEditora livroEditoraPersistencia("../Arquivos/arquivoLinkLivroEditora.txt");

        QList<Biblioteca::LivroAutor> *listaAutor = livroAutorpersistencia.listagem(cod);
        Mumu::PersistenciaAutor persistenciaAutor("../Arquivos/arquivoAutor.txt");

        QList<Biblioteca::LivroEditora> *listaEditora = livroEditoraPersistencia.listagem(cod);
        Biblioteca::PersistenciaEditora editoraPersistencia("../Arquivos/arquivoEditora.txt");


        ui->tableWidgetAutor->setRowCount(listaAutor->size());
        for(int i=0; i<listaAutor->size();i++)
        {
            int codAutor = listaAutor->at(i).getCodigoAutor();

            QStringList aux = persistenciaAutor.consultar(codAutor).split(';');
            if(aux.size()!=2) throw QString("Linha incompleta");

            ui->tableWidgetAutor->setItem(i,0,new QTableWidgetItem(aux[0]));
            ui->tableWidgetAutor->setItem(i,1,new QTableWidgetItem(aux[1]));
        }

        ui->tableWidgetEditora->setRowCount(listaEditora->size());
        for(int i=0; i<listaEditora->size();i++)
        {
            int codEditora = listaEditora->at(i).getCodigoEditora();

            QStringList aux = editoraPersistencia.consultar(codEditora).split(';');
            if(aux.size()!=4) throw QString("Linha incompleta");

            ui->tableWidgetEditora->setItem(i,0,new QTableWidgetItem(aux[0]));
            ui->tableWidgetEditora->setItem(i,1,new QTableWidgetItem(aux[3]));
            ui->tableWidgetEditora->setItem(i,2,new QTableWidgetItem(aux[2]));
            ui->tableWidgetEditora->setItem(i,3,new QTableWidgetItem(aux[1]));
        }

    }catch(QString &erro) {
        QMessageBox::about(this,"Erro",erro);
    }
}
