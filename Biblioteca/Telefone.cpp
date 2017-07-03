#include "Telefone.h"
namespace Vitor
{
    Telefone::Telefone(long long cpf, int id, int DDI, int DDD, int numero):
        cpf(cpf),
        id(id),
        DDI(DDI),
        DDD(DDD),
        numero(numero)
    {
    }
    Telefone::Telefone(long long cpf, int id):
        cpf(cpf),
        id(id),
        DDI(0),
        DDD(0),
        numero(0)
    {
    }
    void Telefone::montarObjeto(QString &str)
    {
        try
        {
            QStringList strList = str.split(';');
            if(strList.size()!=5) throw QString("ERRO - montarObjeto - Telefone") ;
            cpf = strList[0].toLongLong();
            id = strList[1].toInt();
            DDI = strList[2].toInt();
            DDD = strList[3].toInt();
            numero = strList[4].toInt();
        } catch (QString &erro) {throw QString(erro);}
    }
    QString Telefone::desmontarObjeto()const
    {
        QString saida = QString::number(cpf);
        saida += ";";
        saida += QString::number(id);
        saida += ";";
        saida += QString::number(DDI);
        saida += ";";
        saida += QString::number(DDD);;
        saida += ";";
        saida += QString::number(numero);
        return saida;
    }

    QString Telefone::obterNumero() const
    {
        QString saida= "("+QString::number(DDI)+QString::number(DDD)+") "+QString::number(numero);
        return saida;
    }
}


