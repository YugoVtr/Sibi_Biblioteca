#include "PersistenciaExemplar.h"

namespace Biblioteca
{

PersistenciaExemplar::PersistenciaExemplar(QString nomeDoArquivoNoDisco) :
    nomeDoArquivoNoDisco(nomeDoArquivoNoDisco)
{

}

void PersistenciaExemplar::incluir(Exemplar &objeto) const
{
    std::ofstream arq;
    arq.open(nomeDoArquivoNoDisco.toStdString().c_str(),std::ios_base::out|std::ios_base::app);
    if(!arq.is_open()) throw QString("Erro ao abrir aquivo,Exemplar persistencia");
    if(consultar(objeto.getCodigo())!="0") throw QString("Exemplar ja existe, persistencia");
    arq << objeto.desmontarObjeto().toStdString() + "\n";
    arq.close();
}

void PersistenciaExemplar::alterar(Exemplar &objeto) const
{
    //if(consultar(objeto.getCodigo())=="0") throw QString ("Codigo nao encontrado!");
    std::ifstream arquivo;
    arquivo.open(this->nomeDoArquivoNoDisco.toStdString().c_str());
    //if(!arquivo.is_open()) throw QString ("Erro ao abrir o arquivo alteracao, Exemplar alterar");

    std::string linha;
    QString saida = "";

    while(std::getline(arquivo,linha))
    {
        QString linhaAux = QString::fromStdString(linha);
        Exemplar aux;
        aux.montarObjeto(linhaAux);
        if(aux.getCodigo() != objeto.getCodigo()) saida += linhaAux + "\n";
    }

    arquivo.close();
    std::ofstream arqSaida;
    arqSaida.open(this->nomeDoArquivoNoDisco.toStdString().c_str());
    //if(!arqSaida.is_open()) throw QString ("Erro ao abrir o arquivo alteracao,Exemplar alterar");

    arqSaida << saida.toStdString();
    arqSaida << objeto.desmontarObjeto().toStdString() + "\n" ;
    arqSaida.close();
}


//LISTA
QList<Exemplar> *PersistenciaExemplar::listagem() const
{
    std::ifstream arquivo(this->nomeDoArquivoNoDisco.toStdString().c_str());

    if(!arquivo.is_open())throw QString ("Erro ao abrir o arquivo alteracao, Exemplar listagem");

    QList<Exemplar> *lista = new QList<Exemplar>();
    std::string linha;

    while(std::getline(arquivo,linha))
    {
        QString linhaAux = QString::fromStdString(linha);
        Exemplar aux;
        aux.montarObjeto(linhaAux);
        lista->push_back(aux);
    }

    arquivo.close();

    return lista;
}

QString PersistenciaExemplar::consultar(int codigo) const
{
    std::ifstream arquivo;
    arquivo.open(this->nomeDoArquivoNoDisco.toStdString().c_str());
    std::string linha;
    while(std::getline(arquivo,linha))
    {
        QString linhaAux = QString::fromStdString(linha);
        Exemplar aux;
        aux.montarObjeto(linhaAux);
        if(aux.getCodigo()==codigo)
            return linhaAux;
    }
    return "0";
}

}
