#include "frmCad_Editora.h"
#include "ui_frmCad_Editora.h"

frmCad_Editora::frmCad_Editora(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmCad_Editora)
{
    ui->setupUi(this);

    this->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,this->size(),qApp->desktop()->availableGeometry()));
}

frmCad_Editora::~frmCad_Editora()
{
    delete ui;
}

void frmCad_Editora::on_concluirPushButton_clicked()
{
    try{
        QString arq = "../Arquivos/arquivoEditora.txt";
        Biblioteca::PersistenciaEditora persistir(arq);
        int codigo = Vitor::Codigo().gerarCodigo();
        if(persistir.consultar(codigo)!="0")
            throw QString("Editora ja existente,Cadastro Editora");
        QString nome = ui->nomeLineEdit->text();
        QString cidade = ui->cidadeLineEdit->text();
        QString estado = ui->estadoComboBox->currentText();
        Biblioteca::Editora aux(codigo,nome,cidade,estado);
        persistir.incluir(aux);
        QMessageBox::information(this,"Cadastrar","Cadastrado com sucesso");
        this->close();
    } catch(QString &erro) {
        QMessageBox::about(this,"Erro",erro);
    }
}

//void frmCad_Editora::on_editarPushButton_clicked()
//{
//    try{
//        QString arq = "../Arquivos/arquivoEditora.txt";
//        Biblioteca::EditoraPersistencia persistir(arq);
//        int codigo = ui->codigoLineEdit->text().toInt();
//        if(persistir.consultar(codigo)=="0")
//            throw QString("Editora nao existe, Cadastro Editora Editar");
//        QString nome = ui->nomeLineEdit->text();
//        QString cidade = ui->cidadeLineEdit->text();
//        QString estado = ui->estadoComboBox->currentText();
//        Biblioteca::Editora aux(codigo,nome,cidade,estado);
//        persistir.alterar(aux);
//        QMessageBox::information(this,"Editar","Editado com sucesso");
//        this->close();
//    } catch(QString &erro) {
//        QMessageBox::about(this,"Erro",erro);
//    }
//}
