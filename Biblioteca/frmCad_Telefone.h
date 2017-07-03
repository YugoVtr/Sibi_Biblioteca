#ifndef FRMCAD_TELEFONE_H
#define FRMCAD_TELEFONE_H

#include <QDialog>
#include "QValidator"
#include <QDesktopWidget>
#include <QStyle>
#include "QMessageBox"
#include "PersistenciaTelefone.h"

namespace Ui {
class frmCad_Telefone;
}

class frmCad_Telefone : public QDialog
{
    Q_OBJECT

public:
    explicit frmCad_Telefone(long long cpf, QList<Vitor::Telefone> *value);
    ~frmCad_Telefone();

private slots:
    void on_pushButton_Cancel_clicked();

    void on_pushButton_OK_clicked();

private:
    Ui::frmCad_Telefone *ui;
    long long cpf;
    QList<Vitor::Telefone> *value;
};

#endif // FRMCAD_TELEFONE_H
