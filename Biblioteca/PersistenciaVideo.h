#ifndef VIDEOPERSISTENCIA_H
#define VIDEOPERSISTENCIA_H
#include <QString>
#include <Crud.h>
#include <Video.h>

namespace Mumu
{
class PersistenciaVideo : public Vitor::Crud<Video>
{
private:
    QString nomeDoArquivoNoDisco;
public:
    PersistenciaVideo() { }

    PersistenciaVideo(QString nomeDoArquivoNoDisco){this->nomeDoArquivoNoDisco = nomeDoArquivoNoDisco;}

    inline void setNomeDoArquivoNoDisco(QString nomeDoArquivoNoDisco){this->nomeDoArquivoNoDisco = nomeDoArquivoNoDisco;}

    inline QString getNomeDoArquivoNoDisco() {return this->nomeDoArquivoNoDisco;}

    void incluir(Video &objeto)const;
    void alterar(Video &objeto)const;
    void alterar(int codigo, int ano, int tempo,QString titulo, QString genero,QString produtora);
    QString consultar(const int codigo)const;
    QList<Video> *listagem() const;
};
}

#endif // VIDEOPERSISTENCIA_H
