#ifndef TELEFONE_H
#define TELEFONE_H
#include<QString>
#include<ITransformarDados.h>
#include<QStringList>

namespace Vitor
{
    class Telefone : public ITransformaDados
    {
        private:
            long long cpf;
            int id;
            int DDI;
            int DDD;
            int numero;

        public:
            Telefone(long long cpf,int id, int DDI, int DDD, int numero);
            Telefone(long long cpf,int id);

            void montarObjeto(QString &str);
            QString desmontarObjeto()const;

            long long getCpf() const{return this->cpf;}
            int getId()const{return this->id;}
            inline int getDDI() const { return DDI;}
            inline void setDDI(int value) {DDI = value; }
            inline int getDDD() const { return DDD; }
            inline void setDDD(int value) {DDD = value; }
            inline int getNumero() const {return numero; }
            inline void setNumero(int value) {numero = value;}
            QString obterNumero()const;

            bool operator ==(const Telefone &objeto)const{return this->id==objeto.id;}
            bool operator !=(const Telefone &objeto)const{return this->id!=objeto.id;}
    };
}
#endif // TELEFONE_H
