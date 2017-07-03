#include "frmCosultaAutor.h"
#include "ui_frmCosultaAutor.h"
#include <QMessageBox>

frmCosultaAutor::frmCosultaAutor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmCosultaAutor)
{
    ui->setupUi(this);
    try{
        this->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,this->size(),qApp->desktop()->availableGeometry()));
        Mumu::PersistenciaAutor persistir("../Arquivos/arquivoAutor.txt");
        QList<Mumu::Autor> *lista = persistir.listagem();
        ui->autorTableWidget->setRowCount(lista->size());
        for(int i=0;i<lista->size();i++)
        {
            Mumu::Autor aux = lista->at(i);
            ui->autorTableWidget->setItem(i,0,new QTableWidgetItem(QString::number(aux.getCodigo())));
            ui->autorTableWidget->setItem(i,1,new QTableWidgetItem(aux.getNome()));
        }
    } catch(QString &erro) {
        QMessageBox::critical(this,"Erro",erro);
    }
}

frmCosultaAutor::~frmCosultaAutor()
{
    delete ui;
}
