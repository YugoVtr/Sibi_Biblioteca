#ifndef FRMCAD_USUARIO_H
#define FRMCAD_USUARIO_H

#include <QDialog>
#include <QDesktopWidget>
#include <QStyle>
#include "frmCad_Telefone.h"
#include "frmCad_Endereco.h"
#include "PersistenciaUsuario.h"
#include "QMessageBox"
#include "PersistenciaTelefone.h"

namespace Ui {
class frmCad_Usuario;
}

class frmCad_Usuario : public QDialog
{
    Q_OBJECT

public:
    explicit frmCad_Usuario(QWidget *parent = 0);
    ~frmCad_Usuario();

private slots:
    void on_pushButton_AdicionarTelefone_clicked();

    void on_pushButton_AdicionarEndereco_clicked();

    void on_pushButton_Cancelar_clicked();

    void on_pushButton_Cadastrar_clicked();

private:
    Ui::frmCad_Usuario *ui;
    QList<Vitor::Telefone> telefones;
    QList<Vitor::Endereco> enderecos;
};

#endif // FRMCAD_USUARIO_H
