#ifndef FRMCONSULTAEDITORA_H
#define FRMCONSULTAEDITORA_H

#include <QDialog>
#include "PersistenciaEditora.h"
#include <QDesktopWidget>
#include <QStyle>

namespace Ui {
class frmConsultaEditora;
}

class frmConsultaEditora : public QDialog
{
    Q_OBJECT

public:
    explicit frmConsultaEditora(QWidget *parent = 0);
    ~frmConsultaEditora();

private:
    Ui::frmConsultaEditora *ui;
};

#endif // FRMCONSULTAEDITORA_H
