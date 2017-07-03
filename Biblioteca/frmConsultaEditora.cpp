#include "frmConsultaEditora.h"
#include "ui_frmConsultaEditora.h"
#include <QMessageBox>

frmConsultaEditora::frmConsultaEditora(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmConsultaEditora)
{
    try{
        ui->setupUi(this);
        Biblioteca::PersistenciaEditora persistencia("../Arquivos/arquivoEditora.txt");
        QList<Biblioteca::Editora> *lista = persistencia.listagem();
        ui->editoraTableWidget->setRowCount(lista->size());
        for(int i=0;i<lista->size();i++)
        {
            Biblioteca::Editora aux = lista->at(i);
            ui->editoraTableWidget->setItem(i,0,new QTableWidgetItem(QString::number(aux.getCodigo())));
            ui->editoraTableWidget->setItem(i,1,new QTableWidgetItem(aux.getCidade()));
            ui->editoraTableWidget->setItem(i,2,new QTableWidgetItem(aux.getEstado()));
            ui->editoraTableWidget->setItem(i,3,new QTableWidgetItem(aux.getNome()));
            this->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,this->size(),qApp->desktop()->availableGeometry()));
        }
    }catch(QString &erro) {
        QMessageBox::critical(this,"Erro",erro);
    }
}

frmConsultaEditora::~frmConsultaEditora()
{
    delete ui;
}
