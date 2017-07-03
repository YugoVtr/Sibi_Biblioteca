#include "Livro.h"

namespace Biblioteca
{

Livro::Livro() :
    codigo(0),
    isbn(0),
    titulo(""),
    ano(0)
{

}

Livro::Livro(int codigo, long isbn, QString &titulo, int ano) :
    codigo(codigo),
    isbn(isbn),
    titulo(titulo),
    ano(ano)
{
}

/*Livro::Livro(int codigo, long isbn, QString &titulo, int ano, QList<Mumu::Autor> list):
    codigo(codigo),
    isbn(isbn),
    titulo(titulo),
    ano(ano),
    listAutores(list)
{

}*/

void Livro::montarObjeto(QString &str, QList<Editora> list)
{
    montarObjeto(str);
    listEditoras = list;
}

void Livro::montarObjeto(QString &str, QList<Editora> listE, QList<Mumu::Autor> listA)
{
    montarObjeto(str);
    listEditoras = listE;
    listAutores = listA;
}

void Livro::montarObjeto(QString &str, QList<Mumu::Autor> list)
{
    montarObjeto(str);
    listAutores = list;
}

void Livro::montarObjeto(QString &str)
{
    QStringList lista = str.split(';');
    if(lista.size()!=4) throw QString("Objeto imcompleto,Montar objeto Livro");
    codigo = lista[0].toInt();
    isbn = lista[1].toLong();
    titulo = lista[2];
    ano = lista[3].toInt();
}

QString Livro::desmontarObjeto() const
{
    QString saida = QString::number(codigo);
    saida += ";";
    saida += QString::number(isbn);
    saida += ";";
    saida += titulo;
    saida += ";";
    saida += QString::number(ano);
    return saida;
}

}
