#include "frmConsultaEndereco.h"
#include "ui_frmConsultaEndereco.h"

frmConsultaEndereco::frmConsultaEndereco(long long cpf) :
    QDialog(0),
    ui(new Ui::frmConsultaEndereco)
{
    ui->setupUi(this);
    ui->label->setVisible(false);
    Vitor::PersistenciaEndereco enderecos("../Arquivos/enderecos.txt");
    QList<Vitor::Endereco> lista = enderecos.buscarDados(cpf);
    if(lista.isEmpty()) {ui->label->setVisible(true);}
    else
    {
        ui->tableWidget_Enderecos->setRowCount(lista.size());
        for(int linha=0;linha<=lista.size();linha++)
        {
            ui->tableWidget_Enderecos->setItem(linha,0,new QTableWidgetItem(lista.front().getLogradouro()));
            ui->tableWidget_Enderecos->setItem(linha,1,new QTableWidgetItem(QString::number(lista.front().getNumero())));
            ui->tableWidget_Enderecos->setItem(linha,2,new QTableWidgetItem(lista.front().getBairro()));
            ui->tableWidget_Enderecos->setItem(linha,3,new QTableWidgetItem(QString::number(lista.front().getCep())));
            ui->tableWidget_Enderecos->setItem(linha,4,new QTableWidgetItem(lista.front().getCidade()));
            ui->tableWidget_Enderecos->setItem(linha,5,new QTableWidgetItem(lista.front().getEstado()));
            lista.pop_front();
        }
        alinhamento(ui->tableWidget_Enderecos,ui->tableWidget_Enderecos->rowCount(),ui->tableWidget_Enderecos->columnCount());
    }
}

frmConsultaEndereco::~frmConsultaEndereco()
{
    limparGrid();
    delete ui;
}

void frmConsultaEndereco::limparGrid()const
{
    for(int linha=0;linha<ui->tableWidget_Enderecos->rowCount();linha++)
        for(int coluna=0;coluna<ui->tableWidget_Enderecos->columnCount();coluna++)
            delete ui->tableWidget_Enderecos->item(linha,coluna);
    ui->tableWidget_Enderecos->setRowCount(0);
}

void frmConsultaEndereco::alinhamento(QTableWidget *lista,int linhas,int colunas)const
{
    try
    {
        for(int linha=0; linha<linhas;linha++)
            for(int coluna=0; coluna<colunas;coluna++)
                lista->item(linha,coluna)->setTextAlignment(Qt::AlignCenter);
    }catch(...){}
}

void frmConsultaEndereco::on_pushButton_Fechar_clicked()
{
    this->close();
}
