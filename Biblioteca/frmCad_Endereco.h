#ifndef FRMCAD_ENDERECO_H
#define FRMCAD_ENDERECO_H

#include <QDialog>
#include "QValidator"
#include <QDesktopWidget>
#include <QStyle>
#include "QMessageBox"
#include "PersistenciaEndereco.h"

namespace Ui {
class frmCad_Endereco;
}

class frmCad_Endereco : public QDialog
{
    Q_OBJECT

public:
    explicit frmCad_Endereco(long long cpf, QList<Vitor::Endereco> *value);
    ~frmCad_Endereco();

private slots:
    void on_pushButton_Cancel_clicked();

    void on_pushButton_OK_clicked();

private:
    Ui::frmCad_Endereco *ui;
    long long cpf;
    QList<Vitor::Endereco> *value;
};

#endif // FRMCAD_ENDERECO_H
