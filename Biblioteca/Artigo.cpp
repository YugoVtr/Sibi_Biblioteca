#include "Artigo.h"
#include <QStringList>
#include <QString>
#include <fstream>
#include <PersistenciaAutor.h>

namespace Mumu
{
int Artigo::getAnoPublicacao() const
{
    return anoPublicacao;
}

void Artigo::setAnoPublicacao(int value)
{
    anoPublicacao = value;
}

Artigo::Artigo(int codigo, QString titulo, QString area, int anoPublicacao)
{
    setCodigo(codigo);
    this->titulo = titulo;
    Area = area;
    this->anoPublicacao = anoPublicacao;
}

Artigo::Artigo(std::string &str, QList<Autor> list)
{
    QString x(QString::fromStdString(str));
    montarObjeto(x,list);
}

Artigo::Artigo(std::string &str)
{
    QString  x(QString::fromStdString(str));
    montarObjeto(x);
}

void Mumu::Artigo::setCodigo(int codigo)
{
    if(codigo <= 0)
        throw QString ("Codigo menor ou igual a zero!");
    this->codigo = codigo;
}

void Artigo::montarObjeto(QString &str,QList<Autor> list)
{
    montarObjeto(str);
    this->listAutores = list;
}

void Artigo::montarObjeto(QString &str)
{
    QStringList aux = str.split(';');
    if(aux.size() != 4)
        throw QString ("Linha incompleta! Metodo(montar objeto) Artigo");
    setCodigo(aux[0].toInt());
    titulo = aux[1];
    Area = aux[2];
    anoPublicacao = aux[3].toInt();
}

QString Artigo::desmontarObjeto() const
{
    QString saida = QString::number(codigo);//codigo;titulo;Area\n
    saida += ";";
    saida += titulo;
    saida += ";";
    saida += Area;
    saida += ";";
    saida += QString::number(anoPublicacao);
    return saida;
}
}
