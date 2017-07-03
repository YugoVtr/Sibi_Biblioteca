#ifndef USUARIO_H
#define USUARIO_H
#include "QString"
#include "ITransformarDados.h"
#include "PersistenciaTelefone.h"
#include "PersistenciaEndereco.h"
#include "Exemplar.h"
#include "PersistenciaEmprestimo.h"
#include "Codigo.h"
#include "PersistenciaMulta.h"

namespace Vitor
{
    enum TipoDoCliente {Undefined=0,bibliotecario=1, professor=2, aluno=3 };

    class Usuario : public ITransformaDados
    {

    private:
        long long cpf;
        QString nome;
        TipoDoCliente tipo;
        QString email;
        QList<Telefone> telefone;
        QList<Endereco> endereco;

    public:
        Usuario();
        Usuario(long long cpf,QString nome,TipoDoCliente tipo,QString email);
        void montarObjeto(QString &str);
        QString desmontarObjeto()const;

        long long getCpf()const {return cpf;}
        QString getNome()const {return nome;}
        void setNome(QString &value){ nome = value; }
        TipoDoCliente getTipo(){return tipo;}
        QString getEmail()const { return email; }
        void setEmail(QString &value) { email = value;}
        QList<Telefone> getTelefone() const{ return telefone; }
        void setTelefone(const QList<Telefone> &value){telefone = value; }
        QList<Endereco> getEndereco() const{return endereco; }
        void setEndereco(const QList<Endereco> &value){ endereco = value; }

        bool operator ==(const Usuario &objeto)const{return this->cpf==objeto.cpf;}
        bool operator !=(const Usuario &objeto)const{return this->cpf!=objeto.cpf;}
        bool validar(long long numero)const;

        void realizarEmprestimo(Usuario &user,Biblioteca::Exemplar &item);
        void realizarDevolucao(Biblioteca::Exemplar &item);
        void gerarMulta(long long cpf, float valor);
    };
}
#endif // USUARIO_H
