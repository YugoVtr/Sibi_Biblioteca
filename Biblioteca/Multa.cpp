#include "Multa.h"
#include <QStringList>
namespace Mumu
{

Multa::Multa()
{

}

Multa::Multa(long long cpf, float valor, bool status):
    cpf(cpf),
    valor(valor),
    status(status)
{
}

Multa::Multa(std::string str)
{
    QString  x(QString::fromStdString(str));
    montarObjeto(x);
}

void Multa::montarObjeto(QString &str)
{
    QStringList aux = str.split(';');
    if(aux.size() != 3)
        throw QString ("Linha incompleta! Metodo(montar objeto) Multinha");
    cpf = aux.at(0).toLongLong();
    valor = aux.at(1).toFloat();
    int valorBoll = aux.at(2).toInt();
    status = valorBoll;
}

QString Multa::desmontarObjeto() const
{
    QString saida = QString::number(cpf);
    saida += ";";
    saida += QString::number(valor);
    saida += ";";
    saida += QString::number(status);
    return saida;
}
}
