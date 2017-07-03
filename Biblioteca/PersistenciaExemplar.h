#ifndef EXEMPLARPERSISTENCIA_H
#define EXEMPLARPERSISTENCIA_H


#include "Crud.h"
#include "Exemplar.h"
#include "fstream"

namespace Biblioteca
{

class PersistenciaExemplar : public Vitor::Crud<Exemplar>
{
    QString nomeDoArquivoNoDisco;
public:
    PersistenciaExemplar(QString nomeDoArquivoNoDisco);

    void incluir(Exemplar &objeto)const;
    void alterar(Exemplar &objeto)const;
    QList<Exemplar> *listagem()const;
    QString consultar(int codigo)const;
};

}

#endif // EXEMPLARPERSISTENCIA_H
