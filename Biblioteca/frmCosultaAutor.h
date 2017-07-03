#ifndef FRMCOSULTAAUTOR_H
#define FRMCOSULTAAUTOR_H

#include <QDialog>
#include "PersistenciaAutor.h"
#include <QDesktopWidget>
#include <QStyle>

namespace Ui {
class frmCosultaAutor;
}

class frmCosultaAutor : public QDialog
{
    Q_OBJECT

public:
    explicit frmCosultaAutor(QWidget *parent = 0);
    ~frmCosultaAutor();

private:
    Ui::frmCosultaAutor *ui;
};

#endif // FRMCOSULTAAUTOR_H
