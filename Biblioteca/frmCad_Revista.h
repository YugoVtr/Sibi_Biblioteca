#ifndef FRMCAD_REVISTA_H
#define FRMCAD_REVISTA_H

#include <QDialog>
#include <QMessageBox>
#include "PersistenciaEditora.h"
#include "PersistenciaRevista.h"
#include <QDesktopWidget>
#include <QStyle>

namespace Ui {
class frmCad_Revista;
}

class frmCad_Revista : public QDialog
{
    Q_OBJECT

public:
    explicit frmCad_Revista(QWidget *parent = 0);
    ~frmCad_Revista();

private slots:
    void on_concluirPushButton_clicked();

//    void on_alterarPushButton_clicked();

private:
    Ui::frmCad_Revista *ui;
};

#endif // FRMCAD_REVISTA_H
