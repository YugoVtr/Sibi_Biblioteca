#ifndef AUTOR_H
#define AUTOR_H
#include <ITransformarDados.h>

namespace Mumu{

  class Autor : public ITransformaDados
  {
  private:
    int codigo;
    QString nome;
  public:
    inline Autor(){}
    inline Autor(QString &str){montarObjeto(str);}
    Autor(int codigo, QString nome){ this->nome = nome; setCodigo(codigo);}
    Autor(std::string &str) {QString x = QString::fromStdString(str); montarObjeto(x);}
    inline ~Autor() {}

    void setCodigo(int codigo);
    void setNome(QString nome) {this->nome = nome;}

    inline int getCodigo() const {return this->codigo;}
    inline QString getNome() const {return this->nome;}

    void montarObjeto(QString &str);
    QString desmontarObjeto() const;\

    bool operator ==(Autor b){return (codigo == b.codigo);}

   // void operator <(Autor a, Autor b){return (a.getCodigo() < b.getCodigo());}

  };
}


#endif // AUTOR_H
