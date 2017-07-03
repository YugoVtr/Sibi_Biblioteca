#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H
#include "QDate"
#include "Multa.h"
#include "Exemplar.h"
#include <QString>
#include <ITransformarDados.h>
#include <QStringList>
#include "PersistenciaExemplar.h"


namespace Vitor
{
    class Emprestimo : public ITransformaDados
    {
    private:
        int id;
        long long cliente;
        Biblioteca::Exemplar exemplar;
        QDate dataDeEmprestimo;
        QDate dataDevolucao;
        int prazo;

    public:
        Emprestimo();
        Emprestimo(int id, long long cliente, Biblioteca::Exemplar exemplar, int prazo);
        bool isDevolvido();
        void emprestar();
        void devolver();

        void montarObjeto(QString &str);
        QString desmontarObjeto() const;

        bool operator ==(const Emprestimo &objeto)const{return this->id==objeto.id;}
        bool operator !=(const Emprestimo &objeto)const{return this->id!=objeto.id;}

        long long getCliente() const{ return cliente;}
        Biblioteca::Exemplar getExemplar() const{ return exemplar; }
        QDate getDataDeEmprestimo() const{ return dataDeEmprestimo; }
        QDate getDataDevolucao() const{ return dataDevolucao; }
        void setDataDevolucao(const QDate &value){dataDevolucao = value; }
        int getPrazo() const{ return prazo; }
    };
}
#endif // EMPRESTIMO_H
