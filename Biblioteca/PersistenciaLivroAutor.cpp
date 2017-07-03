#include "PersistenciaLivroAutor.h"

namespace Biblioteca
{

PersistenciaLivroAutor::PersistenciaLivroAutor(QString nomeDoArquivoNoDisco) :
    nomeDoArquivoNoDisco(nomeDoArquivoNoDisco)
{

}

void PersistenciaLivroAutor::incluir(LivroAutor &objeto) const
{
    std::ofstream arquivo;
    arquivo.open(nomeDoArquivoNoDisco.toStdString().c_str(),std::ios_base::out|std::ios_base::app);
    if(!arquivo.is_open())
        throw QString("Erro ao abrir arquivo,incluir Persistencia Livro Autor");
    arquivo << objeto.desmontarObjeto().toStdString()+"\n";
    arquivo.close();
}

void PersistenciaLivroAutor::alterar(QList<LivroAutor> list) const
{
    std::fstream arquivo;
    arquivo.open(nomeDoArquivoNoDisco.toStdString().c_str());
    if(!arquivo.is_open())
        throw QString("Erro ao abrir arquivo,alterar Persistencia Livro Autor");
    QString saida;
    std::string linha;
    getline(arquivo,linha);
    while(!arquivo.eof())
    {
        LivroAutor a;
        QString linhaAux = QString::fromStdString(linha);
        a.montarObjeto(linhaAux);
        LivroAutor b = list.front();
        if(a.getCodigoLivro() != b.getCodigoLivro())
            saida += QString::fromStdString(linha)+"\n";
        getline(arquivo,linha);
    }
    arquivo.close();
    arquivo.open(nomeDoArquivoNoDisco.toStdString().c_str(),std::ios_base::out|std::ios_base::trunc);
    arquivo << saida.toStdString();
    for(int i = 0; i < list.size(); i++)
    {
        LivroAutor a = list[i];
        arquivo << a.desmontarObjeto().toStdString() + "\n";
    }
}

//LISTA
QList<LivroAutor> *PersistenciaLivroAutor::listagem() const
{
    QList<LivroAutor> *saida = new QList<LivroAutor>();
    std::ifstream arquivo;
    arquivo.open(nomeDoArquivoNoDisco.toStdString().c_str());
    if(!arquivo.is_open())
        throw QString("Erro ao abrir o arquivo,listagem Peristencia Editora");
    std::string linha;
    getline(arquivo,linha);
    while(!arquivo.eof())
    {
        QString linhaAux = QString::fromStdString(linha);
        LivroAutor aux;
        try{
            aux.montarObjeto(linhaAux);
        }catch (QString &erro){
            throw erro;
        }
        //LISTA
        saida->push_back(aux);
        getline(arquivo,linha);
    }
    return saida;
}

//LISTA
QList<LivroAutor> *PersistenciaLivroAutor::listagem(int codigo) const
{
    QList<LivroAutor> *saida = new QList<LivroAutor>();
    std::ifstream arquivo;
    arquivo.open(nomeDoArquivoNoDisco.toStdString().c_str());
    if(!arquivo.is_open())
        throw QString("Erro ao abrir o arquivo,listagem Peristencia Editora");
    std::string linha;
    getline(arquivo,linha);
    while(!arquivo.eof())
    {
        QString linhaAux = QString::fromStdString(linha);
        LivroAutor aux;
        try{
            aux.montarObjeto(linhaAux);
            if(aux.getCodigoLivro() == codigo) saida->push_back(aux);
        }catch (QString &erro){
            throw erro;
        }
        getline(arquivo,linha);
    }
    return saida;
}

QString PersistenciaLivroAutor::consultar(int codigo)
{
    std::ifstream arquivo;
    arquivo.open(nomeDoArquivoNoDisco.toStdString().c_str());
    if(!arquivo.is_open())
        throw QString("Erro ao abrir o arquivo,listagem Peristencia Livro");
    std::string linha;
    getline(arquivo,linha);
    while(!arquivo.eof())
    {
        QString linhaAux = QString::fromStdString(linha);
        LivroAutor aux;
        aux.montarObjeto(linhaAux);
        if(aux.getCodigoLivro() == codigo) return linhaAux;
        getline(arquivo,linha);
    }
    return 0;
}

}
