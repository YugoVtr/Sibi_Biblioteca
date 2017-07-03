#include "frmCad_Revista.h"
#include "ui_frmCad_Revista.h"
#include <QRegExp>
#include "PersistenciaExemplar.h"

frmCad_Revista::frmCad_Revista(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmCad_Revista)
{
    ui->setupUi(this);


    Biblioteca::PersistenciaEditora editoraPersistencia("../Arquivos/arquivoEditora.txt");
    QList<Biblioteca::Editora> *listaEditora = editoraPersistencia.listagem();
    ui->editoraComboBox->clear();
    while(!listaEditora->empty())
    {
        QString cod = QString::number(listaEditora->front().getCodigo());
        QString nome = listaEditora->front().getNome();
        QString cidade = listaEditora->front().getCidade();
        QString estado = listaEditora->front().getEstado();

        ui->editoraComboBox->addItem(cod+"/"+nome+"/"+cidade+"/"+estado);
        listaEditora->pop_front();
    }

    ui->anoSpinBox->setMaximum(2016);
    ui->anoSpinBox->setMinimum(1600);
    ui->anoSpinBox->setValue(2000);
    QRegExp reg("[0-9]*");
    QRegExpValidator *validar = new QRegExpValidator(reg);
    ui->isbnLineEdit->setValidator(validar);
    this->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,this->size(),qApp->desktop()->availableGeometry()));
}

frmCad_Revista::~frmCad_Revista()
{
    delete ui->isbnLineEdit->validator();
    delete ui;
}

void frmCad_Revista::on_concluirPushButton_clicked()
{
    try{
        QString arq = "../Arquivos/arquivoRevista.txt";
        Biblioteca::PersistenciaRevista persistencia(arq);
        int codigo = Vitor::Codigo().gerarCodigo();
        long isbn = ui->isbnLineEdit->text().toLong();
        if(persistencia.consultar(codigo) != "0")
            throw QString("Revista ja existente,Cadastro Revista");
        QString titulo = ui->tituloLineEdit->text();
        QStringList lista = ui->editoraComboBox->currentText().split('/');
        int ano = ui->anoSpinBox->value();
        int editora = lista.at(0).toInt();
        Biblioteca::Revista aux(codigo,isbn,titulo,ano,editora);
        persistencia.incluir(aux);

        QString des = QString::number(codigo)+" "+QString::number(isbn)+" ";
        des += titulo+" "+QString::number(ano)+" "+lista.at(1);

        int qtdExemplares = ui->exemplaresSpinBox->value();

        Biblioteca::PersistenciaExemplar exemplarPer("../Arquivos/arquivoExemplar.txt");

        Biblioteca::Exemplar exemplar;
        exemplar.setCodigo(Vitor::Codigo().gerarCodigo());
        exemplar.setNumeroDoExemplar(1);
        exemplar.setCirculavel(0);
        exemplar.setStatus(1);
        exemplar.setDescricao(des);
        exemplarPer.incluir(exemplar);
        for(int i=1;i<qtdExemplares;i++)
        {
            Biblioteca::Exemplar aux(Vitor::Codigo().gerarCodigo(),1,1,i+1,des);
            exemplarPer.incluir(aux);
        }


        QMessageBox::information(this,"Cadastro","Revista cadastrada com sucesso");
        this->close();
    } catch(QString &erro) {
        QMessageBox::about(this,"Erro",erro);
    }
}

//void frmCad_Revista::on_alterarPushButton_clicked()
//{
//    try{
//        long isbn = ui->isbnLineEdit->text().toLong();
//        Biblioteca::RevistaPersistencia persistencia("../Arquivos/arquivoRevista.txt");
//        if(persistencia.consultar(isbn)=="0") throw QString("Revista não existe");
//        QString titulo = ui->tituloLineEdit->text();
//        int ano = ui->anoSpinBox->value();

//        QStringList lista = ui->editoraComboBox->currentText().split('/');
//        int codigo = lista[0].toInt();

//        Biblioteca::Revista revista(isbn,titulo,ano,codigo);
//        persistencia.alterar(revista);

//        QMessageBox::information(this,"Alterar","Revista alterada com sucesso");
//        this->close();
//    } catch(QString &erro) {
//        QMessageBox::about(this,"Erro",erro);
//    }
//}
