#ifndef ITRANSFORMARDADOS_H
#define ITRANSFORMARDADOS_H
#include <QString>

class ITransformaDados
{
public:
  virtual void montarObjeto(QString &str) = 0;
  virtual QString desmontarObjeto() const = 0;
  virtual ~ITransformaDados() { }

};


#endif // ITRANSFORMADADOSAUTOR_H
