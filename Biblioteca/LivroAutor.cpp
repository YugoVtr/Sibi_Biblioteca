#include "LivroAutor.h"

namespace Biblioteca
{

LivroAutor::LivroAutor() :
    codigoAutor(0),
    codigo(0)
{

}

LivroAutor::LivroAutor(int codigoAutor, int codigoLivro) :
    codigoAutor(codigoAutor),
    codigo(codigoLivro)
{

}

void LivroAutor::montarObjeto(QString &str)
{
    QStringList lista = str.split(';');
    if(lista.size() != 2) throw QString("Linha incompleta, Livro autor");
    codigo = lista[0].toLong();
    codigoAutor = lista[1].toInt();
}

QString LivroAutor::desmontarObjeto() const
{
    QString saida = QString::number(codigo);
    saida += ";";
    saida += QString::number(codigoAutor);
    return saida;
}

}
