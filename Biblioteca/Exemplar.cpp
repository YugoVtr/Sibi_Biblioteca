#include "Exemplar.h"
#include "QStringList"

namespace Biblioteca
{

Exemplar::Exemplar() :
    codigo(0),
    status(0),
    circulavel(0),
    numeroDoExemplar(0),
    descricao("")
{

}

Exemplar::Exemplar(int codigo, bool status, bool circulavel, int numeroDoExemplar,QString descricao) :
    codigo(codigo),
    status(status),
    circulavel(circulavel),
    numeroDoExemplar(numeroDoExemplar),
    descricao(descricao)
{

}

void Exemplar::montarObjeto(QString &str)
{
    QStringList list = str.split(';');
    if(list.size()!=5) throw QString("Linha imcompleta,item do exemplar");
    codigo = list[0].toInt();
    status = list[1].toInt();
    circulavel = list[2].toInt();
    numeroDoExemplar = list[3].toInt();
    descricao = list[4];
}

QString Exemplar::desmontarObjeto() const
{
    QString saida = QString::number(codigo);
    saida += ";";
    saida += QString::number(status);
    saida += ";";
    saida += QString::number(circulavel);
    saida += ";";
    saida += QString::number(numeroDoExemplar);
    saida += ";";
    saida += descricao;
    return saida;
}

}
