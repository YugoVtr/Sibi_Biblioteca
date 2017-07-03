#include "Editora.h"

namespace Biblioteca
{

Editora::Editora() :
    codigo(0),
    nome(""),
    cidade(""),
    estado("")
{

}

Editora::Editora(int codigo, QString nome, QString cidade, QString estado) :
    nome(nome),
    cidade(cidade),
    estado(estado)
{
    setCodigo(codigo);
}

void Editora::setCodigo(int codigo)
{
    if(codigo<1) throw QString("Codigo inválido (codigo<0)");
    this->codigo = codigo;
}

void Editora::montarObjeto(QString &str)
{
    QStringList lista = str.split(';');
    if(lista.length()!=4) throw QString("Erro ao montar objeto Editora");
    codigo = lista[0].toInt();
    nome = lista[1];
    cidade = lista[2];
    estado = lista[3];
}

QString Editora::desmontarObjeto() const
{
    QString saida;
    saida+= QString::number(codigo);
    saida+= ";";
    saida+= nome;
    saida+= ";";
    saida+= cidade;
    saida+= ";";
    saida+= estado;
    return saida;
}

}
