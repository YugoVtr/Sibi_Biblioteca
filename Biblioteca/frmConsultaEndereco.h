#ifndef FRMCONSULTAENDERECO_H
#define FRMCONSULTAENDERECO_H

#include <QDialog>
#include "frmConsultaUsuario.h"
#include "QTableWidget"
#include "PersistenciaEndereco.h"

namespace Ui {
class frmConsultaEndereco;
}

class frmConsultaEndereco : public QDialog
{
    Q_OBJECT

public:
    explicit frmConsultaEndereco(long long cpf);
    void limparGrid()const;
    void alinhamento(QTableWidget *lista, int linhas, int colunas)const;
    ~frmConsultaEndereco();

private slots:
    void on_pushButton_Fechar_clicked();

private:
    Ui::frmConsultaEndereco *ui;
};

#endif // FRMCONSULTAENDERECO_H
