#include "Revista.h"

namespace Biblioteca
{

Revista::Revista()
{

}

Revista::Revista(int codigo, long isbn, QString titulo, int ano, int codigoEditora) :
    codigo(codigo),
    isbn(isbn),
    titulo(titulo),
    ano(ano),
    codigoEditora(codigoEditora)
{
}

void Revista::montarObjeto(QString &str)
{
    QStringList lista = str.split(';');
    if(lista.size()!=5) throw QString("Linha incompleta, Revista montar objeto");
    codigo = lista[0].toInt();
    isbn = lista[1].toLong();
    titulo = lista[2];
    ano = lista[3].toInt();
    codigoEditora = lista[4].toInt();
}

QString Revista::desmontarObjeto() const
{
    QString saida = QString::number(codigo);
    saida += ";";
    saida += QString::number(isbn);
    saida += ";";
    saida += titulo;
    saida += ";";
    saida += QString::number(ano);
    saida += ";";
    saida += QString::number(codigoEditora);
    return saida;
}

}
