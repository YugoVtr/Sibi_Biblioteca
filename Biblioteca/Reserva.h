#ifndef RESERVA_H
#define RESERVA_H
#include <QString>
#include<ITransformarDados.h>
#include <QDate>
#include <Usuario.h>
#include<Exemplar.h>
#include <PersistenciaExemplar.h>
#include <Usuario.h>


namespace Mumu
{

class Reserva : public ITransformaDados
{
private:
    Biblioteca :: Exemplar itemReservadoExemplar;
    QDate diaReservadoQdate;
    Vitor::Usuario clienteReservaUsuario;
public:
    Reserva()  { }
    Reserva(QString a) {montarObjeto(a);}
    Reserva(std::string a) { QString x(QString::fromStdString(a)); montarObjeto(x); }
    Reserva(Biblioteca::Exemplar itemReservadoExemplar,QDate diaReservadoQdate, Vitor::Usuario clienteReservaUsuario)
    {
        this->itemReservadoExemplar = itemReservadoExemplar;
        this->diaReservadoQdate = diaReservadoQdate;
        this->clienteReservaUsuario = clienteReservaUsuario;
    }
    void montarObjeto(QString &str);
    QString desmontarObjeto()const;

    bool operator ==(Biblioteca::Exemplar a){return a.getCodigo() == itemReservadoExemplar.getCodigo();}
    bool operator !=(Biblioteca::Exemplar a){return a.getCodigo() != itemReservadoExemplar.getCodigo();}
    Biblioteca::Exemplar getItemReservadoExemplar() const;
    void setItemReservadoExemplar(const Biblioteca::Exemplar &value);
    QDate getDiaReservadoQdate() const;
    void setDiaReservadoQdate(const QDate &value);
    Vitor::Usuario getClienteReservaUsuario() const;
    void setClienteReservaUsuario(const Vitor::Usuario &value);
};
}

#endif // RESERVA_H
