#ifndef LIVROAUTOR_H
#define LIVROAUTOR_H

#include "ITransformarDados.h"
#include <QStringList>

namespace Biblioteca
{

class LivroAutor : public ITransformaDados
{
    int codigoAutor;
    int codigo;
public:
    LivroAutor();
    LivroAutor(int codigoAutor, int codigoLivro);

    int getCodigoAutor() const {return codigoAutor;}
    long getCodigoLivro() const {return codigo;}

    void setCodigoAutor(int value) {codigoAutor = value;}
    void setCodigoLivro(int value) {codigo = value;}

    void montarObjeto(QString &str);
    QString desmontarObjeto()const;
};

}

#endif // LIVROAUTOR_H
