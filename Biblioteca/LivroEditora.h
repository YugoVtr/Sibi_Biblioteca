#ifndef LIVROEDITORA_H
#define LIVROEDITORA_H

#include "ITransformarDados.h"
#include <QStringList>

namespace Biblioteca
{

class LivroEditora : public ITransformaDados
{
    int codigoLivro;
    int codigoEditora;
public:
    LivroEditora(int codigoLivro,int codigoEditora);
    LivroEditora();

    void setCodigoLivro(long value) {codigoLivro=value;}
    void setCodigoEditora(long value) {codigoEditora=value;}

    long getCodigoLivro()const{return codigoLivro;}
    int getCodigoEditora()const{return codigoEditora;}

    void montarObjeto(QString &str);
    QString desmontarObjeto()const;
};

}

#endif // LIVROEDITORA_H
