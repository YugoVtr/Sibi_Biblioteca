#ifndef REVISTA_H
#define REVISTA_H

#include <QString>
#include <QStringList>
#include "ITransformarDados.h"

namespace Biblioteca
{

class Revista : public ITransformaDados
{
    int codigo;
    long isbn;
    QString titulo;
    int ano;
    int codigoEditora;
public:
    Revista();
    Revista(int codigo,long isbn,QString titulo,int ano,int codigoEditora);

    void setCodigo(int value) {codigo= value;}
    void setIsbn(long value) {isbn=value;}
    void setTitulo(QString value) {titulo=value;}
    void setAno(int value) {ano=value;}
    void setCodigoEditora(int value) {codigoEditora = value;}

    int getCodigo()const {return codigo;}
    long getIsbn()const {return isbn;}
    QString getTitulo()const {return titulo;}
    int getAno()const {return ano;}
    int getCodigoEditora()const {return codigoEditora;}

    void montarObjeto(QString &str);
    QString desmontarObjeto()const;
};

}

#endif // REVISTA_H
