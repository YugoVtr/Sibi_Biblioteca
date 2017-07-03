#ifndef USUARIO_PERSISTENCIA_H
#define USUARIO_PERSISTENCIA_H
#include "Crud.h"
#include "Usuario.h"
#include "fstream"
#include "QFile"

namespace Vitor
{
    class PersistenciaUsuario : public Crud<Usuario>
    {
    private:
        QString nome_No_Disco;
        QList<Usuario> *dados;
    public:
        PersistenciaUsuario(QString nome_No_Disco):nome_No_Disco(nome_No_Disco),dados(0){carregarDados();}
        QString getNome_No_Diso()const {return nome_No_Disco;}
        void incluir(Usuario &objeto)const;
        void alterar(Usuario &objeto)const;
        void carregarDados();
        QList<Usuario>* listagem()const {return dados;}
        Usuario consultar(long long cpf) const;
    };
}


#endif // USUARIO_PERSISTENCIA_H
