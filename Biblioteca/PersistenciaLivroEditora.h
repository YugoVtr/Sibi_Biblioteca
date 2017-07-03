#ifndef LIVROEDITORAPERSISTENCIA_H
#define LIVROEDITORAPERSISTENCIA_H

#include "LivroEditora.h"
#include "Crud.h"
#include <fstream>
#include <QStack>

namespace Biblioteca
{

class PersistenciaLivroEditora : public Vitor::Crud<LivroEditora>
{
    QString nomeDoArquivoNoDisco;
public:
    PersistenciaLivroEditora(QString nomeDoArquivoNoDisco);
    void incluir(LivroEditora &objeto)const;
    void alterar(QList<LivroEditora> list)const;
    void alterar(LivroEditora &objeto)const {objeto.setCodigoLivro(0);}
    QList<LivroEditora> *listagem()const;
    QList<LivroEditora> *listagem(int codigo)const;
    QString consultar(int codigo);
};

}

#endif // LIVROEDITORAPERSISTENCIA_H
