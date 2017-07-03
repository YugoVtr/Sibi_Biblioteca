#include "PersistirReserva.h"
#include <fstream>

namespace Mumu
{
PersistirReserva::PersistirReserva()
{
}

QString PersistirReserva::getNomeDoArquivoNoDisco() const
{
    return nomeDoArquivoNoDisco;
}

void PersistirReserva::setNomeDoArquivoNoDisco(const QString &value)
{
    nomeDoArquivoNoDisco = value;
}


void PersistirReserva::incluir(Mumu::Reserva &objeto) const
{
    std::ofstream arquivo(this->nomeDoArquivoNoDisco.toStdString().c_str(),std::ios_base::out|std::ios_base::app);
    if(!arquivo) throw QString ("Erro ao abrir o arquivo - Metodo incluir(Reserva Persistencia) 1");
    arquivo.seekp(0,std::ios_base::beg);
    arquivo << objeto.desmontarObjeto().toStdString() + "\n";
    arquivo.close();
}

void PersistirReserva::alterar(Reserva &objeto) const
{
    std::fstream arquivo(this->nomeDoArquivoNoDisco.toStdString().c_str());

    if(!arquivo) throw QString ("Erro ao abrir o arquivo para alteracao 1!- Metodo alterar(Reserva Persistencia)");
    Biblioteca::Exemplar ex = objeto.getItemReservadoExemplar();
    if(consultar(objeto.getItemReservadoExemplar().getCodigo()) == "0") throw QString ("Item nao encontrado");

    arquivo.seekp(0,std::ios_base::beg);

    std::string linha;
    QString saida = "";

    while(std::getline(arquivo,linha))
    {
        if(Reserva(linha).getItemReservadoExemplar().getCodigo() != objeto.getItemReservadoExemplar().getCodigo())
            saida += QString::fromStdString(linha) + "\n";
    }

    arquivo.close();
    arquivo.open(this->nomeDoArquivoNoDisco.toStdString().c_str(),std::ios_base::out);
    if(!arquivo) throw QString ("Erro ao abrir o arquivo para alteracao 1!- Metodo alterar(Multa Persistencia)");
    arquivo.clear();

    arquivo << saida.toStdString();
    arquivo << objeto.desmontarObjeto().toStdString() + "\n";
    arquivo.flush();
    arquivo.close();

}

//LISTA
QList<Reserva> *PersistirReserva::listagem() const
{
    std::ifstream arquivo(this->nomeDoArquivoNoDisco.toStdString().c_str());

    if(!arquivo)throw QString ("Erro ao abrir o arquivo - Metodo listagem(Reserva Persistencia)");

    QList<Reserva> *lista = new QList<Reserva>();
    std::string linha = "";

    while(std::getline(arquivo,linha))
        lista->push_back(Reserva(linha));

    arquivo.close();

    return lista;
}

QString PersistirReserva::consultar(int codigoExemplar) const
{
    std::ifstream arquivo;
    arquivo.open(this->nomeDoArquivoNoDisco.toStdString().c_str());
    std::string linha;
    while(std::getline(arquivo,linha))
        if(Reserva(linha).getItemReservadoExemplar().getCodigo() == codigoExemplar)
            return QString::fromStdString(linha);
    return "0";
}

}
