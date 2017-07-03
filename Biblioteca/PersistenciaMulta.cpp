#include "PersistenciaMulta.h"
#include <fstream>
#include <QString>
#include <QStringList>

namespace Mumu
{

PersistenciaMulta::PersistenciaMulta():
    nomeDoArquivoEmDisco("")
{

}

void Mumu::PersistenciaMulta::incluir(Mumu::Multa &objeto) const
{
    std::ofstream arquivo(this->nomeDoArquivoEmDisco.toStdString().c_str(),std::ios_base::out|std::ios_base::app);
    if(!arquivo) throw QString ("Erro ao abrir o arquivo - Metodo incluir(Artigo Persistencia) 1");
    arquivo.seekp(0,std::ios_base::beg);
    arquivo << objeto.desmontarObjeto().toStdString() + "\n";
    arquivo.close();
}

void PersistenciaMulta::alterar(Multa &objeto) const
{
    std::fstream arquivo(this->nomeDoArquivoEmDisco.toStdString().c_str());

    if(!arquivo) throw QString ("Erro ao abrir o arquivo para alteracao 1!- Metodo alterar(Multa Persistencia)");
    if(consultar(objeto.getCpf()) == "0") throw QString ("Cpf nao encontrado!");

    arquivo.seekp(0,std::ios_base::beg);

    std::string linha;
    QString saida = "";

    while(std::getline(arquivo,linha))
        if(Multa(linha).getCpf() != objeto.getCpf()) saida += QString::fromStdString(linha) + "\n";

    arquivo.close();
    arquivo.open(this->nomeDoArquivoEmDisco.toStdString().c_str(),std::ios_base::out);
    if(!arquivo) throw QString ("Erro ao abrir o arquivo para alteracao 1!- Metodo alterar(Multa Persistencia)");
    arquivo.clear();

    arquivo << saida.toStdString();
    arquivo << objeto.desmontarObjeto().toStdString() + "\n";
    arquivo.flush();
    arquivo.close();

}

QString PersistenciaMulta::consultar(int codigo) const
{
    std::ifstream arquivo;
    arquivo.open(this->nomeDoArquivoEmDisco.toStdString().c_str());
    std::string linha;
    while(std::getline(arquivo,linha))
        if(Multa(linha).getCpf() == codigo)
            return QString::fromStdString(linha);
    return "0";
}

//LISTA
QList<Multa> *PersistenciaMulta::listagem() const
{
    std::ifstream arquivo(this->nomeDoArquivoEmDisco.toStdString().c_str());

    if(!arquivo)throw QString ("Erro ao abrir o arquivo - Metodo listagem(Multa Persistencia)");

    QList<Multa> *lista = new QList<Multa>();
    std::string linha = "";

    while(std::getline(arquivo,linha))
        lista->push_back(Multa(linha));

    arquivo.close();

    return lista;
}

//LISTA
QList<Multa> PersistenciaMulta::listagemPorUsuario(long long cpf) const
{
    QList<Multa> *listaArquivo = listagem();
    QList<Multa> listaUsuario;
    for(int i = 0; i < listaArquivo->size(); i++)
        if(listaArquivo->at(i).getCpf() == cpf)
            listaUsuario.push_front(listaArquivo->at(i));

    delete listaArquivo;
    if(listaUsuario.empty())
        throw QString ("Nao a multa para o cpf " + QString::number(cpf));

    return listaUsuario;
}
}


