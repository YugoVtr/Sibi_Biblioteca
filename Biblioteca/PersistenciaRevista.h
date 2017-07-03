#ifndef REVISTAPERSISTENCIA_H
#define REVISTAPERSISTENCIA_H

#include "Revista.h"
#include "Crud.h"
#include <fstream>
#include <QStack>

namespace Biblioteca
{

class PersistenciaRevista : public Vitor::Crud<Revista>
{
    QString nomeDoArquivoNoDisco;
public:
    PersistenciaRevista(QString nomeDoArquivoNoDisco);

    void incluir(Revista &objeto)const;
    void alterar(Revista &objeto)const;
    QList<Revista> *listagem()const;
    QString consultar(int codigo)const;
};

}

#endif // REVISTAPERSISTENCIA_H
