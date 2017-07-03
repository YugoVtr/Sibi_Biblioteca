#include "frmConsultaArtigo.h"
#include "ui_frmConsultaArtigo.h"
#include <QMessageBox>

frmConsultaArtigo::frmConsultaArtigo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmConsultaArtigo)
{
    ui->setupUi(this);
    try
    {
        this->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,this->size(),qApp->desktop()->availableGeometry()));
        persistirArtigo.setNomeDoArquivoNoDisco("../Arquivos/arquivoArtigo.txt");
        persistirAutor.setNomeDoArquivoNoDisco("../Arquivos/arquivoAutor.txt");
        persistirArtigoAutor.setNomeDoArquivoNoDisco("../Arquivos/arquivoLinkArtigoAutor.txt");
        QList<Artigo> *listaArtigo = persistirArtigo.listagem();
        for(int i = 0; i < listaArtigo->size(); i++)
        {
            ui->tableWidgetArtigo->insertRow(i);
            artigo = listaArtigo->operator [](i);
            ui->tableWidgetArtigo->setItem(i,0, new QTableWidgetItem(QString::number(artigo.getCodigo())));
            ui->tableWidgetArtigo->setItem(i,3,new QTableWidgetItem(artigo.getTitulo()));
            ui->tableWidgetArtigo->setItem(i,1,new QTableWidgetItem(artigo.getArea()));
            ui->tableWidgetArtigo->setItem(i,2,new QTableWidgetItem(QString::number(artigo.getAnoPublicacao())));

            //alinha os textos dos itens
            ui->tableWidgetArtigo->item(i,0)->setTextAlignment(Qt::AlignRight);
            ui->tableWidgetArtigo->item(i,1)->setTextAlignment(Qt::AlignLeft);

            //muda a font dos itens
            ui->tableWidgetArtigo->item(i,0)->setFont(QFont("Bold"));
            ui->tableWidgetArtigo->item(i,1)->setFont(QFont("Bold"));

            //Deixa a lateral das linhas invisiveis
            ui->tableWidgetArtigo->verticalHeader()->setVisible(false);

            //Seleciona toda linha da GRID
            ui->tableWidgetArtigo->setSelectionBehavior(QAbstractItemView::SelectRows);
            //Seleciona toda linha da GRID
            ui->tableWidgetArtigo->setSelectionBehavior(QAbstractItemView::SelectRows);
        }
    }
    catch(QString &erro){QMessageBox::information(this,"CONSULTAR ARTIGO",erro);}
}

frmConsultaArtigo::~frmConsultaArtigo()
{
    delete ui;
}

void frmConsultaArtigo::on_tableWidgetArtigo_itemSelectionChanged()
{
    try
    {

        if(ui->tableWidgetArtigo_2->rowCount())
        {
            for(int i=0; i< ui->tableWidgetArtigo_2->rowCount(); i++)
                delete ui->tableWidgetArtigo_2->item(i,0);
            ui->tableWidgetArtigo_2->setRowCount(0);
        }
        int codigoArtigo = ui->tableWidgetArtigo->item(ui->tableWidgetArtigo->currentItem()->row(),0)->text().toInt() ;
        QList<ArtigoAutor> *listaArtigoAutor = persistirArtigoAutor.listagem(codigoArtigo);
        for(int i = 0; i < listaArtigoAutor->size(); i++)
        {
            Mumu::ArtigoAutor artigoautor = listaArtigoAutor->at(i);
            QString saida = persistirAutor.consultar(artigoautor.getCodigoAutor());
            QStringList listaQString = saida.split(';');
            if(listaQString.size() != 2)
                throw QString ("Erro ao montar objeto autor frm");

            ui->tableWidgetArtigo_2->insertRow(i);
            //seta os itens
            ui->tableWidgetArtigo_2->setItem(i,0, new QTableWidgetItem(listaQString[0] ) );
            ui->tableWidgetArtigo_2->setItem(i,1,new QTableWidgetItem(listaQString[1] ) );


            //alinha os textos dos itens
            ui->tableWidgetArtigo_2->item(i,0)->setTextAlignment(Qt::AlignRight);
            ui->tableWidgetArtigo_2->item(i,1)->setTextAlignment(Qt::AlignLeft);

            //muda a font dos itens
            ui->tableWidgetArtigo_2->item(i,0)->setFont(QFont("Bold"));
            ui->tableWidgetArtigo_2->item(i,1)->setFont(QFont("Bold"));

            //Deixa a lateral das linhas invisiveis
            ui->tableWidgetArtigo_2->verticalHeader()->setVisible(false);

            //Seleciona toda linha da GRID
            ui->tableWidgetArtigo_2->setSelectionBehavior(QAbstractItemView::SelectRows);
        }
    }
    catch(QString &erro){QMessageBox::information(this,"CADASTRO DE ARTIGO",erro);}

}
