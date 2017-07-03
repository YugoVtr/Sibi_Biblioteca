#include "frmCad_Autor.h"
#include "ui_frmCad_Autor.h"

frmCad_Autor::frmCad_Autor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmCad_Autor)
{
    ui->setupUi(this);
    this->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,this->size(),qApp->desktop()->availableGeometry()));
}

frmCad_Autor::~frmCad_Autor()
{
    delete ui;
}

void frmCad_Autor::on_concluirPushButton_clicked()
{
    try{
        QString arq = "../Arquivos/arquivoAutor.txt";
        Mumu::PersistenciaAutor persistir(arq);
        Vitor::Codigo obj;
        int codigo = obj.gerarCodigo();
        if(persistir.consultar(codigo)!="0")
            throw QString("Autor ja existente,Cadastro Autor");
        QString nome = ui->nomeLineEdit->text();
        Mumu::Autor aux(codigo,nome);
        persistir.incluir(aux);
        QMessageBox::information(this,"Cadastro","Cadastrado com sucesso");
        this->close();
    } catch(QString &erro) {
        QMessageBox::about(this,"Erro",erro);
    }
}

//void frmCad_Autor::on_editarPushButton_clicked()
//{
//    try{
//        QString arq = "../Arquivos/arquivoAutor.txt";
//        Mumu::AutorPersistencia persistir(arq);
//        int codigo = 0;
//        if(persistir.consultar(codigo)=="0")
//            throw QString("Autor não existente,Editar Autor");
//        QString nome = ui->nomeLineEdit->text();
//        Mumu::Autor aux(codigo,nome);
//        persistir.alterar(aux);
//        QMessageBox::information(this,"Editar","Editado com sucesso");
//        this->close();
//    } catch(QString &erro) {
//        QMessageBox::about(this,"Erro",erro);
//    }
//}
