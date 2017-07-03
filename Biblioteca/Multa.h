#ifndef MULTA_H
#define MULTA_H
#include<ITransformarDados.h>

namespace Mumu
{


class Multa : public ITransformaDados
{
private:
    long long cpf;
    float valor;
    bool status;
public:
    Multa();
    Multa(long long cpf, float valor, bool status);
    Multa(std::string str);

    void montarObjeto(QString &str);
    QString desmontarObjeto() const;

    void setValor(float value) {valor = value;}
    void setStatus(bool value) {status = value;}

    long long getCpf() const {return cpf;}
    float getValor() const{return valor;}
    bool getStatus() const {return status;}
};
}

#endif // MULTA_H
