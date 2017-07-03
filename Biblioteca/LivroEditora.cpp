#include "LivroEditora.h"

namespace Biblioteca
{

LivroEditora::LivroEditora(int codigoLivro, int codigoEditora) :
    codigoLivro(codigoLivro),
    codigoEditora(codigoEditora)
{
}

LivroEditora::LivroEditora() :
    codigoLivro(0),
    codigoEditora(0)
{
}

void LivroEditora::montarObjeto(QString &str)
{
    QStringList lista = str.split(';');
    if(lista.size()!=2) throw QString("Linha imcompleta,Montar objeto Livro Editora");
    codigoLivro = lista[0].toInt();
    codigoEditora = lista[1].toInt();
}

QString LivroEditora::desmontarObjeto() const
{
    QString saida = QString::number(codigoLivro);
    saida += ";";
    saida += QString::number(codigoEditora);
    return saida;
}

}
