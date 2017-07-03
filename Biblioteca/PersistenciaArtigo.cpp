#include "PersistenciaArtigo.h"
#include <fstream>

namespace Mumu
{

void PersistenciaArtigo::incluir(Artigo &objeto) const
{
    std::ofstream arquivo(this->nomeDoArquivoNoDisco.toStdString().c_str(),std::ios_base::out|std::ios_base::app);
    if(!arquivo) throw QString ("Erro ao abrir o arquivo - Metodo incluir(Artigo Persistencia) 1");
    arquivo.seekp(0,std::ios_base::beg);
    arquivo << objeto.desmontarObjeto().toStdString() + "\n";
    arquivo.close();
}

void PersistenciaArtigo::alterar(Artigo &objeto) const
{
    std::fstream arquivo(this->nomeDoArquivoNoDisco.toStdString().c_str());

    if(!arquivo) throw QString ("Erro ao abrir o arquivo para alteracao 1!- Metodo alterar(Artigo Persistencia)");
    if(consultar(objeto.getCodigo()) == "0") throw QString ("Codigo nao encontrado!");

    arquivo.seekp(0,std::ios_base::beg);

    std::string linha;
    QString saida = "";

    while(std::getline(arquivo,linha))
        if(Artigo(linha).getCodigo() != objeto.getCodigo()) saida += QString::fromStdString(linha) + "\n";

    arquivo.close();
    arquivo.open(this->nomeDoArquivoNoDisco.toStdString().c_str(),std::ios_base::out);
    if(!arquivo) throw QString ("Erro ao abrir o arquivo para alteracao 1!- Metodo alterar(Artigo Persistencia)");
    arquivo.clear();

    arquivo << saida.toStdString();
    arquivo << QString::number(objeto.getCodigo()).toStdString() + ";" + objeto.getTitulo().toStdString() + ";"
               + objeto.getArea().toStdString() + "\n";
    arquivo.flush();
    arquivo.close();
}

QString PersistenciaArtigo::consultar(const int codigo) const
{
    std::ifstream arquivo;
    arquivo.open(this->nomeDoArquivoNoDisco.toStdString().c_str());
    std::string linha;
    while(std::getline(arquivo,linha))
        if(Artigo(linha).getCodigo() == codigo)
            return QString::fromStdString(linha);
    return "0";
}

//retorna todos os ARTIGOS em uma lista
QList<Artigo> *PersistenciaArtigo::listagem() const
{
    std::ifstream arquivo(this->nomeDoArquivoNoDisco.toStdString().c_str());

    if(!arquivo)throw QString ("Erro ao abrir o arquivo - Metodo listagem(Autor Persistencia)");

    QList<Artigo> *lista = new QList<Artigo>();
    std::string linha;

    while(std::getline(arquivo,linha))
        lista->push_back(Artigo(linha));

    arquivo.close();

    return lista;
}

}
