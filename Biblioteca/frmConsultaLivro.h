#ifndef FRMCONSULTALIVRO_H
#define FRMCONSULTALIVRO_H

#include <QDialog>
#include "PersistenciaLivroAutor.h"
#include "PersistenciaLivroEditora.h"
#include "PersistenciaLivro.h"
#include "PersistenciaAutor.h"
#include "PersistenciaEditora.h"
#include <QDesktopWidget>
#include <QStyle>

namespace Ui {
class frmConsultaLivro;
}

class frmConsultaLivro : public QDialog
{
    Q_OBJECT

public:
    explicit frmConsultaLivro(QWidget *parent = 0);
    ~frmConsultaLivro();
    void inicializar()const;
    void limparGrid()const;

private slots:

    void on_tableWidget_cellClicked(int row, int column);

private:
    Ui::frmConsultaLivro *ui;
    QList<Biblioteca::Livro> *listaLivro;
};

#endif // FRMCONSULTALIVRO_H
