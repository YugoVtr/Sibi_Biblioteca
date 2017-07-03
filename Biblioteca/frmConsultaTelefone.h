#ifndef FRMCONSULTATELEFONE_H
#define FRMCONSULTATELEFONE_H

#include <QDialog>
#include "frmConsultaUsuario.h"
#include "QTableWidget"
#include "PersistenciaTelefone.h"

namespace Ui {
class frmConsultaTelefone;
}

class frmConsultaTelefone : public QDialog
{
    Q_OBJECT

public:
    explicit frmConsultaTelefone(long long cpf);
    void limparGrid()const;
    void alinhamento(QTableWidget *lista, int linhas, int colunas)const;
    ~frmConsultaTelefone();

private slots:
    void on_pushButton_Fechar_clicked();

private:
    Ui::frmConsultaTelefone *ui;
};

#endif // FRMCONSULTATELEFONE_H
