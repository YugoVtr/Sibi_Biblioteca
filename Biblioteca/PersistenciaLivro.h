#ifndef LIVROPERSISTENCIA_H
#define LIVROPERSISTENCIA_H

#include "Livro.h"
#include "Crud.h"
#include <fstream>
#include <QStack>

namespace Biblioteca
{

class PersistenciaLivro : public Vitor::Crud<Livro>
{
    QString nomeDoArquivoNoDisco;
public:
    PersistenciaLivro() : nomeDoArquivoNoDisco("") {}
    PersistenciaLivro(QString nomeDoArquivoNoDisco);

    void incluir(Livro &objeto)const;
    void alterar(Livro &objeto)const;
    QList<Livro> *listagem()const;
    QString consultar(long isbn)const;
};

}

#endif // LIVROPERSISTENCIA_H
