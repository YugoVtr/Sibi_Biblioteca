#ifndef FRMCONSULTAREVISTA_H
#define FRMCONSULTAREVISTA_H

#include <QDialog>
#include "PersistenciaRevista.h"
#include "PersistenciaEditora.h"
#include <QDesktopWidget>
#include <QStyle>

namespace Ui {
class frmConsultaRevista;
}

class frmConsultaRevista : public QDialog
{
    Q_OBJECT

public:
    explicit frmConsultaRevista(QWidget *parent = 0);
    ~frmConsultaRevista();
    void inicializar()const;

private slots:
    void on_tableWidgetRevista_cellClicked(int row, int column);
    void limparGrid()const;

private:
    Ui::frmConsultaRevista *ui;
    QList<Biblioteca::Revista> *revistas;
};

#endif // FRMCONSULTAREVISTA_H
