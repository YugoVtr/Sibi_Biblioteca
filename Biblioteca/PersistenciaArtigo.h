#ifndef ARTIGOPERSISTENCIA_H
#define ARTIGOPERSISTENCIA_H
#include <QString>
#include <Crud.h>
#include <Artigo.h>
#include <QList>

namespace Mumu
{
class PersistenciaArtigo : public Vitor::Crud<Artigo>
{
private:
    QString nomeDoArquivoNoDisco;
public:
    PersistenciaArtigo() { }
    ~PersistenciaArtigo() { }

    PersistenciaArtigo(QString nomeDoArquivoNoDisco){this->nomeDoArquivoNoDisco = nomeDoArquivoNoDisco;}

    inline void setNomeDoArquivoNoDisco(QString nomeDoArquivoNoDisco){this->nomeDoArquivoNoDisco = nomeDoArquivoNoDisco;}

    inline QString getNomeDoArquivoNoDisco() {return this->nomeDoArquivoNoDisco;}


    void incluir(Artigo &objeto)const;
    void alterar(Artigo &objeto)const;
    QString consultar(const int codigo)const;
    QList<Artigo> *listagem() const;

};
}

#endif // ARTIGOPERSISTENCIA_H
