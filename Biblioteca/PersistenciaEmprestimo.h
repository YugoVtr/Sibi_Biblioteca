#ifndef EMPRESTIMO_PERSISTENCIA_H
#define EMPRESTIMO_PERSISTENCIA_H
#include "Emprestimo.h"

namespace Vitor
{
    class PersistenciaEmprestimo : public Crud<Emprestimo>
    {
    private:
        QString nome_No_Disco;
        QList<Emprestimo> *dados;
    public:
        PersistenciaEmprestimo(QString nome_No_Disco):nome_No_Disco(nome_No_Disco),dados(0){carregarDados();}
        QString getNome_No_Diso()const {return nome_No_Disco;}
        void incluir(Emprestimo &objeto)const;
        void alterar(Emprestimo &objeto)const;
        QList<Emprestimo>* listagem()const{return dados;}
        QList<Emprestimo> buscarDados(long long cpf)const;
        void carregarDados();
        Emprestimo consultar(long long cpf) const;
        Emprestimo consultar(int codigo) const;
    };
}


#endif // EMPRESTIMO_PERSISTENCIA_H
