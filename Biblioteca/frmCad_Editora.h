#ifndef FRMCAD_EDITORA_H
#define FRMCAD_EDITORA_H

#include <QDialog>
#include <QMessageBox>
#include "Editora.h"
#include "PersistenciaEditora.h"

#include <QDesktopWidget>
#include <QStyle>

namespace Ui {
class frmCad_Editora;
}

class frmCad_Editora : public QDialog
{
    Q_OBJECT

public:
    explicit frmCad_Editora(QWidget *parent = 0);
    ~frmCad_Editora();

private slots:
    void on_concluirPushButton_clicked();

//    void on_editarPushButton_clicked();

private:
    Ui::frmCad_Editora *ui;
};

#endif // FRMCAD_EDITORA_H
