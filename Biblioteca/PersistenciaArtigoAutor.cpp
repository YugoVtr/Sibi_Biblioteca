#include "PersistenciaArtigoAutor.h"
#include <fstream>

namespace Mumu
{

void PersistenciaArtigoAutor::incluir(ArtigoAutor &objeto) const
{
    std::ofstream arquivo(this->nomeDoArquivoNoDisco.toStdString().c_str(),std::ios_base::out|std::ios_base::app);
    if(!arquivo) throw QString ("Erro ao abrir o arquivo - Metodo incluir(Autor Persistencia) 1");
    arquivo.seekp(0,std::ios_base::beg);
    arquivo << objeto.desmontarObjeto().toStdString() + "\n";
    arquivo.close();
}

void PersistenciaArtigoAutor::alterar(QList<ArtigoAutor> *lista) const
{
    std::fstream arquivo;
    arquivo.open(this->nomeDoArquivoNoDisco.toStdString().c_str());
    std::string linha;
    int i = 0;
    QString saida = "";

    //pega todos os elementos do arquivo com execao dos que estao na lista
    while(std::getline(arquivo,linha))
    {
        ArtigoAutor a(linha);
        ArtigoAutor b = lista->at(i);
        if(b.getCodigoArtigo() != a.getCodigoArtigo())
            saida += QString::fromStdString(linha) + "\n";
    }


    arquivo.close();
    arquivo.open(this->nomeDoArquivoNoDisco.toStdString().c_str(),std::ios_base::out);
    if(!arquivo) throw QString ("Erro ao abrir o arquivo para alteracao 1!- Metodo alterar(Artigo Persistencia)");
    arquivo.clear();
    arquivo << saida.toStdString();

    //insiro a lista
    for(int i = 0; i < lista->size(); i++)
    {
        ArtigoAutor a = lista->at(i);
        arquivo << QString::number(a.getCodigoArtigo()).toStdString() + ";" + QString::number(a.getCodigoAutor()).toStdString() + "\n";
    }

}

QString PersistenciaArtigoAutor::consultar(const int codigo) const
{
    std::ifstream arquivo;
    arquivo.open(this->nomeDoArquivoNoDisco.toStdString().c_str());
    std::string linha;
    while(std::getline(arquivo,linha))
        if(ArtigoAutor(linha).getCodigoArtigo() == codigo)
            return QString::fromStdString(linha);
    return "0";
}

QList<ArtigoAutor> *PersistenciaArtigoAutor::listagem() const
{
    std::ifstream arquivo;

    //crio uma lista de artigo/autor
    QList<ArtigoAutor> * lista = new QList<ArtigoAutor>();
    arquivo.open(this->nomeDoArquivoNoDisco.toStdString().c_str());
    std::string linha;

    //Pego todos as relações de artigo/autor do arquivo e armazeno na minha lista
    while(std::getline(arquivo,linha))
        lista->push_back(ArtigoAutor(linha));
    return lista;
}

QList<ArtigoAutor> *PersistenciaArtigoAutor::listagem(int codigo) const
{
    std::ifstream arquivo;
    //crio uma lista de artigo/autor
    QList<ArtigoAutor> * lista = new QList<ArtigoAutor>();
    arquivo.open(this->nomeDoArquivoNoDisco.toStdString().c_str());
    std::string linha;
    //pego todos as relações de artigo/autor de acordo com o codigo no meu arquivo e armazeno em uma lista
    while(std::getline(arquivo,linha))
    {
        if(linha[0] == QString::number(codigo)[0])
            lista->push_back(ArtigoAutor(linha));
    }
    return lista;
}

}
