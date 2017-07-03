#include "PersistenciaVideo.h"
#include <fstream>

namespace Mumu
{

  void PersistenciaVideo::incluir(Video &objeto) const
  {
    std::ofstream arquivo(this->nomeDoArquivoNoDisco.toStdString().c_str(),std::ios_base::out|std::ios_base::app);
    if(!arquivo) throw QString ("Erro ao abrir o arquivo - Metodo incluir(Video Persistencia) 1");
    if(consultar(objeto.getCodigo()) != "0") throw QString ("Codigo existente");
    arquivo.seekp(0,std::ios_base::beg);
    arquivo << objeto.desmontarObjeto().toStdString() + "\n";
    arquivo.close();
  }

  void PersistenciaVideo::alterar(Video &objeto) const
  {
    std::fstream arquivo(this->nomeDoArquivoNoDisco.toStdString().c_str());

    if(!arquivo) throw QString ("Erro ao abrir o arquivo para alteracao 1!- Metodo alterar(Video Persistencia)");
    if(consultar(objeto.getCodigo()) == "0") throw QString ("Codigo nao encontrado!");

    arquivo.seekp(0,std::ios_base::beg);

    std::string linha;
    QString saida = "";

    while(std::getline(arquivo,linha))
      if(Video(linha).getCodigo() != objeto.getCodigo()) saida += QString::fromStdString(linha) + "\n";

    arquivo.close();
    arquivo.open(this->nomeDoArquivoNoDisco.toStdString().c_str(),std::ios_base::out);
    if(!arquivo) throw QString ("Erro ao abrir o arquivo para alteracao 1!- Metodo alterar(Autor Persistencia)");
    arquivo.clear();

    arquivo << saida.toStdString();
    std::string aux = QString::number(objeto.getCodigo()).toStdString() + ";" + QString::number(objeto.getAnoDeProducao()).toStdString() + ";";
    aux            += QString::number(objeto.getTempoDeDuracao()).toStdString() + ";";
    aux            += objeto.getTitulo().toStdString() + ";" + objeto.getGenero().toStdString() + ";" + objeto.getProdutora().toStdString() + "\n";
    arquivo << aux;
    arquivo.flush();
    arquivo.close();
  }

  void PersistenciaVideo::alterar(int codigo, int ano, int tempo, QString titulo, QString genero, QString produtora)
  {
    Video x(codigo,ano,tempo,titulo,genero,produtora);
    alterar(x);
  }

  QString PersistenciaVideo::consultar(const int codigo) const
  {
    std::ifstream arquivo;
    arquivo.open(this->nomeDoArquivoNoDisco.toStdString().c_str());
    std::string linha;
    while(std::getline(arquivo,linha))
      if(Video(linha).getCodigo() == codigo)
        return QString::fromStdString(linha);
    return "0";
  }

  //LISTA
  QList<Video> *PersistenciaVideo::listagem() const
  {
    std::ifstream arquivo(this->nomeDoArquivoNoDisco.toStdString().c_str());

    if(!arquivo)throw QString ("Erro ao abrir o arquivo - Metodo listagem(Video Persistencia)");

    QList<Video> *lista = new QList<Video>();
    std::string linha;

    while(std::getline(arquivo,linha))
      lista->push_back(Video(linha));

    arquivo.close();

    return lista;
  }
}
