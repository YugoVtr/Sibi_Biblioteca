#ifndef EXEMPLAR_H
#define EXEMPLAR_H

#include "ITransformarDados.h"

namespace Biblioteca
{

class Exemplar : public ITransformaDados
{
public:
    Exemplar();
    Exemplar(int codigo, bool status, bool circulavel, int numeroDoExemplar, QString descricao);

    void setCodigo(int value) {codigo=value;}
    void setStatus(bool value) {status=value;}
    void setCirculavel(bool value) {circulavel = value;}
    void setNumeroDoExemplar(int value) {numeroDoExemplar = value;}
    void setDescricao(QString &value) {descricao = value;}

    int getCodigo() const {return codigo;}
    bool getStatus() const {return status;}
    bool getCirculavel() const {return circulavel;}
    int getNumeroDoExemplar() const {return numeroDoExemplar;}
    QString getDescricao()const {return descricao;}

    void montarObjeto(QString &str);
    QString desmontarObjeto()const;

private:
    int codigo;
    bool status;
    bool circulavel;
    int numeroDoExemplar;
    QString descricao;
};

}

#endif // EXEMPLAR_H
