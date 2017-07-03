#include "frmConsultaVideo.h"
#include "ui_frmConsultaVideo.h"
#include <QMessageBox>

frmConsultaVideo::frmConsultaVideo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmConsultaVideo)
{
    ui->setupUi(this);

    try
    {
        this->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,this->size(),qApp->desktop()->availableGeometry()));
        //coloca apenas o btn de saida no frm
        this->setWindowFlags(Qt::WindowCloseButtonHint);
        Mumu::PersistenciaVideo video("../Arquivos/arquivoVideo.txt");
        QList<Mumu::Video> *list = video.listagem();
        for(int i = 0; i < 6; i++,ui->tableWidget->setColumnHidden(i,false));
        for(int i = 0; i < list->size(); i++)
        {
            Mumu::Video videoAux = list->operator [](i);
            //insere as linhas
            ui->tableWidget->insertRow(i);


            //seta os itens
            ui->tableWidget->setItem(i,0, new QTableWidgetItem(QString::number(videoAux.getCodigo())));
            ui->tableWidget->setItem(i,1, new QTableWidgetItem(QString::number(videoAux.getAnoDeProducao())));
            ui->tableWidget->setItem(i,2, new QTableWidgetItem(QString::number(videoAux.getTempoDeDuracao())));
            ui->tableWidget->setItem(i,3, new QTableWidgetItem(videoAux.getTitulo()));
            ui->tableWidget->setItem(i,4, new QTableWidgetItem(videoAux.getGenero()));
            ui->tableWidget->setItem(i,5, new QTableWidgetItem(videoAux.getProdutora()));

            //alinha os textos dos itens
            ui->tableWidget->item(i,0)->setTextAlignment(Qt::AlignRight);
            ui->tableWidget->item(i,1)->setTextAlignment(Qt::AlignLeft);
            ui->tableWidget->item(i,2)->setTextAlignment(Qt::AlignLeft);
            ui->tableWidget->item(i,3)->setTextAlignment(Qt::AlignLeft);
            ui->tableWidget->item(i,4)->setTextAlignment(Qt::AlignLeft);
            ui->tableWidget->item(i,5)->setTextAlignment(Qt::AlignLeft);

            //muda a font dos itens
            ui->tableWidget->item(i,0)->setFont(QFont("Bold"));
            ui->tableWidget->item(i,1)->setFont(QFont("Bold"));
            ui->tableWidget->item(i,2)->setFont(QFont("Bold"));
            ui->tableWidget->item(i,3)->setFont(QFont("Bold"));
            ui->tableWidget->item(i,4)->setFont(QFont("Bold"));
            ui->tableWidget->item(i,5)->setFont(QFont("Bold"));

            //Deixa a lateral das linhas invisiveis
            ui->tableWidget->verticalHeader()->setVisible(false);

            //Seleciona toda linha da GRID
            ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

            /*
         *Alinhamento de acordo com o conteudo do itens**
        ui->tableWidget->resizeColumnsToContents();
        ui->tableWidget->resizeRowsToContents();
       */
        }
    }
    catch(QString &erro){QMessageBox::information(this,"Titulo",erro);}
}


frmConsultaVideo::~frmConsultaVideo()
{
    delete ui;
}
