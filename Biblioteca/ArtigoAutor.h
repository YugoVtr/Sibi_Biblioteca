#ifndef ARTIGOAUTOR_H
#define ARTIGOAUTOR_H
#include <ITransformarDados.h>

namespace Mumu
{
class ArtigoAutor : public ITransformaDados
{
private:
    int codigoAutor;
    int codigoArtigo;
public:
    ArtigoAutor( ) { }
    ArtigoAutor(int codigoAutor,int codigoArtigo );
    ArtigoAutor(QString &str){montarObjeto(str);}
    ArtigoAutor(std::string &str);
    ~ArtigoAutor( ){ }

    void setCodigoAutor(int codigo) {codigoAutor = codigo;}
    void setCodigoArtigo(int codigo) {codigoArtigo = codigo;}

    int getCodigoAutor()  {return codigoAutor;}
    int getCodigoArtigo() {return codigoArtigo;}

    void montarObjeto(QString &str) ;
    QString desmontarObjeto( )const;
};
}
#endif // ARTIGOAUTOR_H
