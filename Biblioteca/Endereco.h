#ifndef ENDERECO_H
#define ENDERECO_H
#include<QString>
#include<ITransformarDados.h>
#include<QStringList>

namespace Vitor
{
    class Endereco : public ITransformaDados
    {
        private:
            long long cpf;
            int id;
            QString logradouro;
            int numero;
            QString bairro;
            int cep;
            QString cidade;
            QString estado;

        public:
            Endereco(long long cpf, int id, QString logradouro, int numero, QString bairro, int cep, QString cidade, QString estado);
            Endereco(long long cpf, int id);

            void montarObjeto(QString &str);
            QString desmontarObjeto()const;

            inline long long getCpf()const {return cpf;}
            inline int getId()const {return id;}
            inline QString getLogradouro() const  {return logradouro; }
            inline void setLogradouro(const QString &value)  { logradouro = value;}
            inline int getNumero() const  { return numero; }
            inline void setNumero(int value)  { numero = value;}
            inline QString getBairro() const  { return bairro; }
            inline void setBairro(const QString &value)  { bairro = value; }
            inline int getCep() const  { return cep;  }
            inline void setCep(int value)  { cep = value; }
            inline QString getCidade() const  { return cidade; }
            inline void setCidade(const QString &value)  { cidade = value;}
            inline QString getEstado() const  { return estado;}
            inline void setEstado(const QString &value)  {estado = value; }
            QString obterEndereco()const;

            bool operator ==(const Endereco &objeto)const{return this->id==objeto.id;}
            bool operator !=(const Endereco &objeto)const{return this->id!=objeto.id;}
    };
}
#endif // ENDERECO_H
