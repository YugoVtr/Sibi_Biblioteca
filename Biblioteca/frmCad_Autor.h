#ifndef FRMCAD_AUTOR_H
#define FRMCAD_AUTOR_H

#include <QDialog>
#include "Autor.h"
#include "PersistenciaAutor.h"
#include <QMessageBox>
#include <QDesktopWidget>
#include <QStyle>

namespace Ui {
class frmCad_Autor;
}

class frmCad_Autor : public QDialog
{
    Q_OBJECT

public:
    explicit frmCad_Autor(QWidget *parent = 0);
    ~frmCad_Autor();

private slots:
    void on_concluirPushButton_clicked();

//    void on_editarPushButton_clicked();

private:
    Ui::frmCad_Autor *ui;
};

#endif // FRMCAD_AUTOR_H
