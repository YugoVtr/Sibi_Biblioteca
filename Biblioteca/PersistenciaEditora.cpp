#include "PersistenciaEditora.h"

namespace Biblioteca
{

void PersistenciaEditora::incluir(Editora &objeto) const
{
    std::ofstream arquivo;
    arquivo.open(nomeDoArquivoNoDisco.toStdString().c_str(),std::ios_base::out|std::ios_base::app);
    if(!arquivo.is_open())
        throw QString("Erro ao abrir arquivo,incluir Persistencia Editora");
    arquivo << objeto.desmontarObjeto().toStdString()+"\n";
    arquivo.close();
}

void PersistenciaEditora::alterar(Editora &objeto) const
{
    std::fstream arquivo;
    arquivo.open(nomeDoArquivoNoDisco.toStdString().c_str());
    if(!arquivo.is_open())
        throw QString("Erro ao abrir arquivo,alterar Persistencia Editora");
    bool encontrou = false;
    std::string linha;

    //crio uma pilha de EDITORAS
    QStack<Editora> pilha;
    getline(arquivo,linha);
    while(!arquivo.eof())
    {
        Editora aux;
        QString linhaAux = QString::fromStdString(linha);
        aux.montarObjeto(linhaAux);
        //se nao for o codigo que procuro armazeno na minha PILHA para manter a ordem de cadastro
        if(aux.getCodigo()!=objeto.getCodigo())
            pilha.push_back(aux);
        else
           encontrou = true;
        getline(arquivo,linha);
    }
    if(!encontrou) throw QString("Impossivel aterar persistencia,Editora não encontrada");
    arquivo.close();
    std::ofstream arquivoSaida;
    arquivoSaida.open(nomeDoArquivoNoDisco.toStdString().c_str());
    if(!arquivoSaida.is_open())
        throw QString("Erro ao abrir arquivo,alterar Persistencia Editora");
    //Devolvo todos os elementos da minha pilha para meu arquivo e vou dando POP
    while(!pilha.empty())
    {
        Editora aux = pilha.top();
        arquivoSaida << aux.desmontarObjeto().toStdString()+"\n";
        pilha.pop();
    }
    arquivoSaida << objeto.desmontarObjeto().toStdString()+"\n";
    arquivoSaida.close();
}

//pego todas as EDITORAS no meu arquivo e devolvo elas em forma de uma LISTA
QList<Editora> *PersistenciaEditora::listagem() const
{
    QList<Editora> *saida = new QList<Editora>();
    std::ifstream arquivo;
    arquivo.open(nomeDoArquivoNoDisco.toStdString().c_str());
    if(!arquivo.is_open())
        throw QString("Erro ao abrir o arquivo,listagem Persistencia Editora");
    std::string linha;
    getline(arquivo,linha);
    while(!arquivo.eof())
    {
        QString linhaAux = QString::fromStdString(linha);
        Editora aux;
        try{
            aux.montarObjeto(linhaAux);
        }catch (QString &erro){
            throw erro;
        }

        saida->push_back(aux);
        getline(arquivo,linha);
    }
    return saida;
}

QString PersistenciaEditora::consultar(int codigo) const
{
    std::ifstream arquivo;
    arquivo.open(nomeDoArquivoNoDisco.toStdString().c_str());
    if(!arquivo.is_open())
        return "0";
    std::string linha;
    getline(arquivo,linha);
    while(!arquivo.eof())
    {
        QString linhaAux = QString::fromStdString(linha);
        Editora aux;
        aux.montarObjeto(linhaAux);
        if(aux.getCodigo() == codigo) return linhaAux;
        getline(arquivo,linha);
    }
    return "0";
}

}
