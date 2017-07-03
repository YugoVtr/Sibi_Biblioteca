#include "frmConsultaExemplar.h"
#include "ui_frmConsultaExemplar.h"
#include "PersistenciaExemplar.h"

frmConsultaExemplar::frmConsultaExemplar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmConsultaExemplar)
{
    ui->setupUi(this);
    Biblioteca::PersistenciaExemplar exemplarPer("../Arquivos/arquivoExemplar.txt");
    QList<Biblioteca::Exemplar> *lista = exemplarPer.listagem();
    int tam = lista->size();
    ui->exemplarTableWidget->setRowCount(tam);
    for(int i=0;i<tam;i++)
    {
        ui->exemplarTableWidget->setItem
                (i,0,new QTableWidgetItem(QString::number(lista->at(i).getCodigo())));
        if(lista->at(i).getStatus())
            ui->exemplarTableWidget->setItem(i,1,new QTableWidgetItem("Disponivel"));
        else
            ui->exemplarTableWidget->setItem(i,1,new QTableWidgetItem("Indisponivel"));
        if(lista->at(i).getCirculavel())
            ui->exemplarTableWidget->setItem(i,2,new QTableWidgetItem("Circulavel"));
        else
            ui->exemplarTableWidget->setItem(i,2,new QTableWidgetItem("Fixo"));
        ui->exemplarTableWidget->setItem
                (i,3,new QTableWidgetItem(QString::number(lista->at(i).getNumeroDoExemplar())));
        ui->exemplarTableWidget->setItem(i,4,new QTableWidgetItem(lista->at(i).getDescricao()));
    }
}

frmConsultaExemplar::~frmConsultaExemplar()
{
    delete ui;
}
