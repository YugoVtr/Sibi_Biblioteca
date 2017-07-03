#include "Reserva.h"
#include <QStringList>
#include<PersistenciaUsuario.h>
#include<PersistenciaExemplar.h>
#include<QString>
namespace Mumu{


Biblioteca::Exemplar Reserva::getItemReservadoExemplar() const
{
    return itemReservadoExemplar;
}

void Reserva::setItemReservadoExemplar(const Biblioteca::Exemplar &value)
{
    itemReservadoExemplar = value;
}

QDate Reserva::getDiaReservadoQdate() const
{
    return diaReservadoQdate;
}

void Reserva::setDiaReservadoQdate(const QDate &value)
{
    diaReservadoQdate = value;
}

Vitor::Usuario Reserva::getClienteReservaUsuario() const
{
    return clienteReservaUsuario;
}

void Reserva::setClienteReservaUsuario(const Vitor::Usuario &value)
{
    clienteReservaUsuario = value;
}

void Reserva::montarObjeto(QString &str)
{
    QStringList listaTodosAtributos = str.split(';');
    if(listaTodosAtributos.length() != 3) throw QString("Erro ao montar objeto Reserva metodo MontarObjeto 1");

    QStringList listaAtributoQDate = listaTodosAtributos[2].split('/');
   if(listaAtributoQDate.length() != 3) throw QString("Erro ao montar objeto Reserva metodo MontarObjeto 2");

   Vitor::PersistenciaUsuario persistirUsuario("../Arquivos/arquivoUsuario_Persistencia.txt");
   Biblioteca::PersistenciaExemplar persistirExemplar("../Arquivos/arquivoExemplarPersistencia.txt");

   QString exemplar = persistirExemplar.consultar(listaTodosAtributos[0].toInt());
   if(exemplar == "0")
       throw QString("erro ao procurar objeto exemplar Metodo montar objeto Reserva 1");
   this->itemReservadoExemplar.montarObjeto(exemplar);

   Vitor::Usuario usuario = persistirUsuario.consultar(listaTodosAtributos[1].toLongLong());

   this->diaReservadoQdate.setDate(listaAtributoQDate[0].toInt(),listaAtributoQDate[1].toInt(),listaAtributoQDate[2].toInt());
}

QString Reserva::desmontarObjeto() const
{
    QString saida  = QString::number(this->itemReservadoExemplar.getCodigo());
    saida += ";";
    saida += QString::number(this->clienteReservaUsuario.getCpf());
    saida += ";";
    saida +=  QString::number(this->diaReservadoQdate.year());
    saida += "/";
    saida += QString::number(this->diaReservadoQdate.month());
    saida += "/";
    saida += QString::number(this->diaReservadoQdate.day());
    return saida;
}
}
