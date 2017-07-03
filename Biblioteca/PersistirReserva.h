#ifndef PERSISTIRRESERVA_H
#define PERSISTIRRESERVA_H
#include<Reserva.h>
#include <Crud.h>

namespace Mumu
{
class PersistirReserva : public Vitor::Crud<Reserva>
{
private:
    QString nomeDoArquivoNoDisco;
public:
    PersistirReserva();

    void incluir(Reserva &objeto) const;
    void alterar(Reserva &objeto) const;
    QList<Reserva> *listagem() const;
    QString consultar(int codigoExemplar)const;

    void setNomeDoArquivoNoDisco(const QString &value);
    QString getNomeDoArquivoNoDisco() const;
};
}

#endif // PERSISTIRRESERVA_H
