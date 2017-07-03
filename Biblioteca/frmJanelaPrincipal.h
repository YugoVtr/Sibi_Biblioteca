#ifndef FRMJANELAPRINCIPAL_H
#define FRMJANELAPRINCIPAL_H

#include <QMainWindow>
#include "frmCad_Editora.h"
#include "frmCad_Autor.h"
#include "frmCad_Livro.h"
#include "frmCad_Revista.h"
#include "frmCosultaAutor.h"
#include "frmConsultaEditora.h"
#include "frmConsultaLivro.h"
#include "frmConsultaRevista.h"
#include "frmCad_Artigo.h"
#include "frmCad_Video.h"
#include "frmConsultaArtigo.h"
#include "frmConsultaVideo.h"
#include "frmConsultaUsuario.h"
#include "frmConsultaAcervo.h"
#include "frmConsultaExemplar.h"
#include "Emprestimo.h"
#include <QDesktopWidget>
#include <QStyle>

namespace Ui {
class frmJanelaPrincipal;
}

class frmJanelaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit frmJanelaPrincipal(QWidget *parent = 0);
    ~frmJanelaPrincipal();

private slots:


    void on_actionCadastrar_triggered();

    void on_actionConsulta_triggered();

    void on_actionLivro_triggered();

    void on_actionRevista_triggered();

    void on_actionArtigo_triggered();

    void on_actionVideo_triggered();

    void on_actionLivro_2_triggered();

    void on_actionRevista_2_triggered();

    void on_actionArtigo_2_triggered();

    void on_actionVideo_2_triggered();

    void on_actionCadastro_triggered();

    void on_actionConsulta_2_triggered();

    void on_actionCadastro_2_triggered();

    void on_actionConsulta_3_triggered();

    void on_actionExemplar_triggered();

    void on_pushButton_OK_clicked();

    void on_pushButton_OK_Devolucao_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_Reserva_clicked();

private:
    Ui::frmJanelaPrincipal *ui;
    Vitor::Usuario adm;
};

#endif // FRMJANELAPRINCIPAL_H
