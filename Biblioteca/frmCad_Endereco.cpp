#include "frmCad_Endereco.h"
#include "ui_frmCad_Endereco.h"

frmCad_Endereco::frmCad_Endereco(long long cpf, QList<Vitor::Endereco> *value) :
    QDialog(0),
    ui(new Ui::frmCad_Endereco),
    cpf(cpf),
    value(value)
{
    ui->setupUi(this);
    this->setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            this->size(),
            qApp->desktop()->availableGeometry()
        )
    );
    this->setFixedSize(this->width(),this->height());

    QRegExp cep("[0-9]*");
    QRegExpValidator *CEP = new QRegExpValidator(cep,ui->cEPLineEdit);
    ui->cEPLineEdit->setValidator(CEP);

    QRegExp numero("[0-9]*");
    QRegExpValidator *NUMERO = new QRegExpValidator(numero,ui->numeroLineEdit);
    ui->numeroLineEdit->setValidator(NUMERO);
}

frmCad_Endereco::~frmCad_Endereco()
{
    delete ui->cEPLineEdit->validator();
    delete ui->numeroLineEdit->validator();
    delete ui;
}

void frmCad_Endereco::on_pushButton_Cancel_clicked()
{
    this->close();
}

void frmCad_Endereco::on_pushButton_OK_clicked()
{
    try
    {
        QString logradouro = ui->logradouroLineEdit->text();
        int numero = ui->numeroLineEdit->text().toInt();
        QString bairro = ui->bairroLineEdit->text();
        int cep = ui->cEPLineEdit->text().toInt();
        QString cidade = ui->cidadeLineEdit->text();
        QString uf = ui->uFComboBox->currentText();

        Vitor::Codigo valor;
        Vitor::Endereco endereco(cpf,valor.gerarCodigo(),logradouro,numero,bairro,cep,cidade,uf);
        value->push_back(endereco);
        this->close();
    } catch (QString &erro) {QMessageBox::critical(this,"ERRO",erro); }
}
