#include "Video.h"
#include <QStringList>
namespace Mumu
{

  Video::Video(int codigo, int ano, int tempo, QString titulo, QString genero, QString produtora)
  {
    setCodigo(codigo);
    setAnoDeProducao(ano);
    setTempoDeDuracao(tempo);
    this->titulo = titulo;
    this->genero = genero;
    this->produtora = produtora;
  }

  void Video::setCodigo(int codigo)
  {
    if(codigo <= 0)
      throw QString ("Codigo menor ou igual a zero!");
    this->codigo = codigo;
  }

  void Video::setAnoDeProducao(int ano)
  {
    if(ano <= 0)
      throw QString ("O ano deve ser um numero positivo");
    this->anoDeProducao = ano;
  }

  void Video::setTempoDeDuracao(int tempo)
  {
    if(tempo <= 0)
      throw QString ("O tempo deve ser no minimo um minuto");
    this->tempoDeDuracao = tempo;
  }

  void Video::montarObjeto(QString &str)
  {
    QStringList aux = str.split(';');
    if(aux.length() != 6)
      throw QString ("Erro ao montar objeto Video, (Linha do arquivo invalida!)");
    setCodigo(aux[0].toInt());
    anoDeProducao   = aux[1].toInt();
    tempoDeDuracao = aux[2].toFloat();
    titulo             = aux[3];
    genero            = aux[4];
    produtora         = aux[5];
  }

  QString Video::desmontarObjeto() const
  {
    QString saida(QString::number(codigo));
    saida += ";";
    saida += QString::number(anoDeProducao);
    saida += ";";
    saida +=  QString::number(tempoDeDuracao);
    saida += ";";
    saida += titulo;
    saida += ";";
    saida += genero;
    saida += ";";
    saida += produtora;
    return saida;
  }

}
