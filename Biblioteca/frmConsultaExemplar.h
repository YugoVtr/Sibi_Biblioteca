#ifndef FRMCONSULTAEXEMPLAR_H
#define FRMCONSULTAEXEMPLAR_H

#include <QDialog>

namespace Ui {
class frmConsultaExemplar;
}

class frmConsultaExemplar : public QDialog
{
    Q_OBJECT

public:
    explicit frmConsultaExemplar(QWidget *parent = 0);
    ~frmConsultaExemplar();

private:
    Ui::frmConsultaExemplar *ui;
};

#endif // FRMCONSULTAEXEMPLAR_H
