#include "Autor.h"
#include <QStringList>


namespace Mumu
{
  void Autor::setCodigo(int codigo)
  {
    if(codigo <= 0)
      throw QString ("Codigo menor ou igual a zero!");
    this->codigo = codigo;
  }

  void Autor::montarObjeto(QString &str)
  {
    QStringList aux = str.split(';');
    if(aux.length() != 2)
      throw QString ("Erro ao montar objeto Autor, (Linha do arquivo invalida!)");
    setCodigo(aux[0].toInt());
    nome = aux[1];
  }

  QString Autor::desmontarObjeto() const
  {
    QString saida = QString::number(codigo);
    saida += ";";
    saida += nome;
    return saida;
  }
}
