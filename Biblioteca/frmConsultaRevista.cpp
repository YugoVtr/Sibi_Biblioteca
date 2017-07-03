#include "frmConsultaRevista.h"
#include "ui_frmConsultaRevista.h"
#include <QMessageBox>

frmConsultaRevista::frmConsultaRevista(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmConsultaRevista)
{
    ui->setupUi(this);
    try{
        Biblioteca::PersistenciaRevista revistaPersistencia("../Arquivos/arquivoRevista.txt");
        revistas = revistaPersistencia.listagem();
        inicializar();
        this->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,this->size(),qApp->desktop()->availableGeometry()));
    } catch(QString &erro) {
        QMessageBox::critical(this,"Erro",erro);
    }
}

frmConsultaRevista::~frmConsultaRevista()
{
    delete ui;
}

void frmConsultaRevista::inicializar() const
{
    int tam = revistas->size();
    ui->tableWidgetRevista->setRowCount(tam);
    for(int i=0;i<tam;i++)
    {
        ui->tableWidgetRevista->setItem(i,0,new QTableWidgetItem(QString::number
                                                                 (revistas->at(i).getIsbn())));
        ui->tableWidgetRevista->setItem(i,1,new QTableWidgetItem(QString::number
                                                                 (revistas->at(i).getAno())));
        ui->tableWidgetRevista->setItem(i,2,new QTableWidgetItem(revistas->at(i).getTitulo()));
    }
}

void frmConsultaRevista::on_tableWidgetRevista_cellClicked(int row, int column)
{
    limparGrid();
    Biblioteca::PersistenciaEditora editoraPersistencia("../Arquivos/arquivoEditora.txt");
    ui->tableWidgetEditora->setRowCount(1);
    int cod  = revistas->at(row).getCodigoEditora();
    QStringList aux = editoraPersistencia.consultar(cod).split(';');
    if(aux.size() != 4) throw QString("Linha incompleta");

    ui->tableWidgetEditora->setItem(0,0,new QTableWidgetItem(aux[0]));
    ui->tableWidgetEditora->setItem(0,1,new QTableWidgetItem(aux[2]));
    ui->tableWidgetEditora->setItem(0,2,new QTableWidgetItem(aux[3]));
    ui->tableWidgetEditora->setItem(0,3,new QTableWidgetItem(aux[1]));
}

void frmConsultaRevista::limparGrid() const
{
    int tam = ui->tableWidgetEditora->rowCount();
    for(int i=0;i<tam;i++)
    {
        delete ui->tableWidgetEditora->item(i,0);
        delete ui->tableWidgetEditora->item(i,1);
        delete ui->tableWidgetEditora->item(i,2);
        delete ui->tableWidgetEditora->item(i,3);
    }
    ui->tableWidgetEditora->setRowCount(0);
}
