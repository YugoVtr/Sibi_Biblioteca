#ifndef FRMCONSULTAUSUARIO_H
#define FRMCONSULTAUSUARIO_H

#include <QMainWindow>
#include "frmCad_Usuario.h"
#include "QApplication"
#include <QDesktopWidget>
#include <QStyle>
#include "QTableWidget"
#include "frmConsultaTelefone.h"
#include "frmConsultaEndereco.h"
#include "QDate"
#include "frmJanelaPrincipal.h"

namespace Ui {
class frmConsultaUsuario;
}

class frmConsultaUsuario : public QMainWindow
{
    Q_OBJECT

public:
    explicit frmConsultaUsuario(QWidget *parent = 0);
    void limparGrid()const;
    void alinhamento(QTableWidget *lista, int linhas, int colunas)const;
    ~frmConsultaUsuario();

private slots:

    void on_action_Novo_Cadastro_triggered();

    void on_actionSair_triggered(){this->close();}

    void on_actionLimpar_triggered(){limparGrid();}

    void on_action_Consultar_Cadastros_triggered();

    void on_tableWidget_Usuarios_cellClicked(int row, int column);

    void on_pushButton_AlterarCadastro_clicked();

private:
    Ui::frmConsultaUsuario *ui;
};

#endif // FRMCONSULTAUSUARIO_H
