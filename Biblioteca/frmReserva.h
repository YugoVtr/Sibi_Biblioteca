#ifndef FRMRESERVA_H
#define FRMRESERVA_H
#include<PersistirReserva.h>
#include<Reserva.h>
#include<Usuario.h>
#include<PersistenciaUsuario.h>
#include <Exemplar.h>
#include <PersistenciaExemplar.h>

#include <QWidget>

namespace Ui {
class frmReserva;
}

class frmReserva : public QWidget
{
    Q_OBJECT

public:

    explicit frmReserva(QWidget *parent = 0);
    ~frmReserva();

private slots:
    void on_pushButtonSair_clicked();

    void on_pushButtonReservar_clicked();
private:
    Ui::frmReserva *ui;
    QList<Vitor::Usuario> *listaUsuario;
    QList<Biblioteca::Exemplar> *listaExemplar;

};

#endif // FRMRESERVA_H
