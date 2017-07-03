#ifndef FRMCONSULTAARTIGO_H
#define FRMCONSULTAARTIGO_H

#include <QMainWindow>
#include <Artigo.h>
#include <PersistenciaArtigo.h>
#include <Autor.h>
#include <PersistenciaAutor.h>
#include <ArtigoAutor.h>
#include <PersistenciaArtigoAutor.h>
#include <QDialog>
#include <QDesktopWidget>
#include <QStyle>
using namespace Mumu;


namespace Ui {
class frmConsultaArtigo;
}

class frmConsultaArtigo : public QDialog
{
    Q_OBJECT

public:
    explicit frmConsultaArtigo(QWidget *parent = 0);
    ~frmConsultaArtigo();

private slots:
     void on_tableWidgetArtigo_itemSelectionChanged();
private:
    Ui::frmConsultaArtigo *ui;
    Artigo artigo;
    PersistenciaArtigo persistirArtigo;
    Autor autor;
    PersistenciaAutor persistirAutor;
    ArtigoAutor artigoAutor;
    PersistenciaArtigoAutor persistirArtigoAutor;
    QList<Autor> *listaAutor;
};

#endif // FRMCONSULTAARTIGO_H

