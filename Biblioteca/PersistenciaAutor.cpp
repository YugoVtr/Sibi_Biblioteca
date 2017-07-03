#include "PersistenciaAutor.h"
#include <fstream>
#include <iostream>

namespace Mumu
{
QString PersistenciaAutor::consultar(const int codigo) const
{
    std::ifstream arquivo;
    arquivo.open(this->nomeDoArquivoNoDisco.toStdString().c_str());
    std::string linha;
    while(std::getline(arquivo,linha))
    {
        if(Autor(linha).getCodigo() == codigo)
            return QString::fromStdString(linha);
    }
    return "0";
}

void PersistenciaAutor::incluir(Autor &objeto) const
{
    std::ofstream arquivo(this->nomeDoArquivoNoDisco.toStdString().c_str(),std::ios_base::out|std::ios_base::app);
    if(!arquivo) throw QString ("Erro ao abrir o arquivo - Metodo incluir(Autor Persistencia) 1");
    if(consultar(objeto.getCodigo())!="0") throw QString ("Codigo existente");
    arquivo.seekp(0,std::ios_base::beg);
    arquivo << objeto.desmontarObjeto().toStdString() + "\n";
    arquivo.close();
}

void PersistenciaAutor::alterar(Autor &objeto) const
{
    std::fstream arquivo(this->nomeDoArquivoNoDisco.toStdString().c_str());

    if(!arquivo) throw QString ("Erro ao abrir o arquivo para alteracao 1!- Metodo alterar(Autor Persistencia)");
    if(consultar(objeto.getCodigo())=="0") throw QString ("Codigo nao encontrado!");

    arquivo.seekp(0,std::ios_base::beg);

    std::string linha;
    QString saida = "";

    while(std::getline(arquivo,linha))
        if(Autor(linha).getCodigo() != objeto.getCodigo()) saida += QString::fromStdString(linha) + "\n";

    arquivo.close();
    arquivo.open(this->nomeDoArquivoNoDisco.toStdString().c_str(),std::ios_base::out);
    if(!arquivo) throw QString ("Erro ao abrir o arquivo para alteracao 1!- Metodo alterar(Autor Persistencia)");
    arquivo.clear();

    arquivo << saida.toStdString();
    arquivo << QString::number(objeto.getCodigo()).toStdString() + ";" + objeto.getNome().toStdString() + "\n" ;
    arquivo.flush();
    arquivo.close();
}

//retorna todos os AUTORES em uma lista
QList<Autor> *PersistenciaAutor::listagem() const
{
    std::ifstream arquivo(this->nomeDoArquivoNoDisco.toStdString().c_str());

    if(!arquivo)throw QString ("Erro ao abrir o arquivo - Metodo listagem(Autor Persistencia)");

    QList<Autor> *lista = new QList<Autor>();
    std::string linha;

    while(std::getline(arquivo,linha))
        lista->push_back(Autor(linha));

    arquivo.close();

    return lista;
}
}
