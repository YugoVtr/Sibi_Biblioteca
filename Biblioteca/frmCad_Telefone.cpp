#include "frmCad_Telefone.h"
#include "ui_frmCad_Telefone.h"

frmCad_Telefone::frmCad_Telefone(long long cpf, QList<Vitor::Telefone> *value) :
    QDialog(0),
    ui(new Ui::frmCad_Telefone),
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

    QRegExp ddi("[0-9]*");
    QRegExpValidator *DDI = new QRegExpValidator(ddi,ui->dDILineEdit);
    ui->dDILineEdit->setValidator(DDI);

    QRegExp ddd("[0-9]*");
    QRegExpValidator *DDD = new QRegExpValidator(ddd,ui->dDDLineEdit);
    ui->dDDLineEdit->setValidator(DDD);

    QRegExp numero("[0-9]*");
    QRegExpValidator *NUMERO = new QRegExpValidator(numero,ui->numeroLineEdit);
    ui->numeroLineEdit->setValidator(NUMERO);
}

frmCad_Telefone::~frmCad_Telefone()
{
    delete ui->dDILineEdit->validator();
    delete ui->dDDLineEdit->validator();
    delete ui->numeroLineEdit->validator();
    delete ui;
}

void frmCad_Telefone::on_pushButton_Cancel_clicked()
{
    this->close();
}

void frmCad_Telefone::on_pushButton_OK_clicked()
{
    try
    {
        int ddi = ui->dDILineEdit->text().toInt();
        int ddd = ui->dDDLineEdit->text().toInt();
        int numero = ui->numeroLineEdit->text().toInt();
        Vitor::Codigo valor;
        Vitor::Telefone telefone(cpf,valor.gerarCodigo(),ddi,ddd,numero);
        value->push_back(telefone);
        this->close();
    } catch (QString &erro) {QMessageBox::critical(this,"ERRO",erro); }
}
