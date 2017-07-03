#ifndef MULTAPERSISTENCIA_H
#define MULTAPERSISTENCIA_H
#include <Multa.h>
#include<Crud.h>

namespace Mumu
{
class PersistenciaMulta : public Vitor::Crud<Multa>
{
private:
    QString nomeDoArquivoEmDisco;
public:
    PersistenciaMulta();

    void setNomeDoArquivoEmDisco(QString nomeDoArquivoEmDisco) {this->nomeDoArquivoEmDisco = nomeDoArquivoEmDisco;}

    QString getNomeDoArquivoEmDisco(){return nomeDoArquivoEmDisco;}

    void incluir(Multa &objeto) const;
    void alterar(Multa &objeto) const;
    QString consultar(int codigo)const;
    QList<Multa> *listagem() const;
    QList<Multa> listagemPorUsuario(long long cpf) const;
};
}

#endif // MULTAPERSISTENCIA_H
