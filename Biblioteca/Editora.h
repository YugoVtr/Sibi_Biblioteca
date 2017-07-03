#ifndef EDITORA_H
#define EDITORA_H

#include <QString>
#include <QStringList>
#include "ITransformarDados.h"

namespace Biblioteca
{

class Editora : public ITransformaDados
{
public:
    Editora();
    Editora(int codigo,QString nome,QString cidade,QString estado);

    void setCodigo(int codigo);
    void setNome(const QString &nome) {this->nome = nome;}
    void setCidade(const QString &cidade) {this->cidade = cidade;}
    void setEstado(const QString &estado) {this->estado = estado;}

    int getCodigo() const {return codigo;}
    QString getNome() const {return nome;}
    QString getCidade() const {return cidade;}
    QString getEstado() const {return estado;}

    void montarObjeto(QString &str);
    QString desmontarObjeto() const;
private:
    int codigo;
    QString nome;
    QString cidade;
    QString estado;
};

}

#endif // EDITORA_H
