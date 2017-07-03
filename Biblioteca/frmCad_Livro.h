#ifndef FRMCAD_LIVRO_H
#define FRMCAD_LIVRO_H

#include <QDialog>
#include <QMessageBox>
#include "PersistenciaAutor.h"
#include "PersistenciaLivro.h"
#include "PersistenciaEditora.h"
#include "PersistenciaLivroAutor.h"
#include "PersistenciaLivroEditora.h"
#include <QDesktopWidget>
#include <QStyle>

namespace Ui {
class frmCad_Livro;
}

class frmCad_Livro : public QDialog
{
    Q_OBJECT

public:
    explicit frmCad_Livro(QWidget *parent = 0);
    ~frmCad_Livro();
    void iniciarComboBoxAutor()const;
    void iniciarComboBoxEditora()const;

private slots:
    void on_concluirPushButton_clicked();

    void on_incluirAutorPushButton_clicked();

//    void on_alterarPushButton_clicked();

    void on_incluirEditoraPushButton_clicked();

private:
    Ui::frmCad_Livro *ui;
    QList<Mumu::Autor> autores;
    QList<Biblioteca::Editora> editoras;
};

#endif // FRMCAD_LIVRO_H
