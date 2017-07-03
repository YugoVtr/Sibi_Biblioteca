#include "ArtigoAutor.h"
#include <QString>
#include <QStringList>
namespace Mumu
{

ArtigoAutor::ArtigoAutor(int codigoAutor, int codigoArtigo)
{
    this->codigoAutor = codigoAutor;
    this->codigoArtigo = codigoArtigo;
    QString x(QString::number(codigoArtigo));
    x +=  ";";
    x += QString::number(codigoAutor);
    montarObjeto(x);
}

ArtigoAutor::ArtigoAutor(std::string &str)
{
    QString x(QString::fromStdString(str));
    montarObjeto(x);
}

void ArtigoAutor::montarObjeto(QString &str)
{
    QStringList aux = str.split(';');
    if(aux.length() != 2)
        throw QString ("Erro ao montar objeto Autor, (Linha do arquivo invalida!)");
    this->codigoArtigo = aux[0].toInt();
    this->codigoAutor = aux[1].toInt();
}

QString ArtigoAutor::desmontarObjeto() const
{
    QString saida = QString::number(codigoArtigo);
    saida += ";";
    saida += QString::number(codigoAutor);
    return saida;
}

}
