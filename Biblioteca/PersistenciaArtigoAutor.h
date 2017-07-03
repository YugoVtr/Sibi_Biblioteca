#ifndef ARTIGOAUTORPERSISTENCIA_H
#define ARTIGOAUTORPERSISTENCIA_H
#include<QString>
#include <ArtigoAutor.h>
#include <Crud.h>
#include <QList>
namespace Mumu
{
class PersistenciaArtigoAutor : public Vitor::Crud<ArtigoAutor>
{
private:
    QString nomeDoArquivoNoDisco;
public:
    PersistenciaArtigoAutor( ){ }
    ~PersistenciaArtigoAutor( ){ }

    inline void setNomeDoArquivoNoDisco(QString nomeDoArquivoNoDisco){this->nomeDoArquivoNoDisco = nomeDoArquivoNoDisco;}
    inline QString getNomeDoArquivoNoDisco() {return this->nomeDoArquivoNoDisco;}

    PersistenciaArtigoAutor(QString nomeDoArquivoNoDisco){this->nomeDoArquivoNoDisco = nomeDoArquivoNoDisco;}

    void incluir(ArtigoAutor &objeto)const;
    void alterar(QList<ArtigoAutor> *lista)const;
    void alterar(ArtigoAutor &objeto)const {objeto.setCodigoArtigo(0);}
    QString consultar(const int codigo)const;
    QList<ArtigoAutor> *listagem() const;
    QList<ArtigoAutor> *listagem(int codigo) const;
};

}

#endif // ARTIGOAUTORPERSISTENCIA_H
