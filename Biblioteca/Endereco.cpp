#include "Endereco.h"
namespace Vitor
{
    Endereco::Endereco(long long cpf, int id, QString logradouro, int numero, QString bairro, int cep, QString cidade, QString estado):
        cpf(cpf),
        id(id),
        logradouro(logradouro),
        numero(numero),
        bairro(bairro),
        cep(cep),
        cidade(cidade),
        estado(estado)
    {
    }
    Endereco::Endereco(long long cpf, int id):
        cpf(cpf),
        id(id),
        logradouro(""),
        numero(0),
        bairro(""),
        cep(0),
        cidade(""),
        estado("")
    {
    }
    void Endereco::montarObjeto(QString &str)
    {
        try
        {
            QStringList strList = str.split(';');
            if(strList.size()!=8) throw QString("ERRO - montarObjeto - Endereco") ;
            cpf = strList[0].toLongLong();
            id = strList[1].toInt();
            logradouro = strList[2];
            numero = strList[3].toInt();
            bairro = strList[4];
            cep = strList[5].toInt();
            cidade = strList[6];
            estado = strList[7];

        } catch (QString &erro) {throw QString(erro);}
    }
    QString Endereco::desmontarObjeto()const
    {
        QString saida = QString::number(cpf);
        saida += ";";
        saida += QString::number(id);
        saida += ";";
        saida += logradouro;
        saida += ";";
        saida += QString::number(numero);
        saida += ";";
        saida += bairro;
        saida += ";";
        saida += QString::number(cep);
        saida += ";";
        saida += cidade;
        saida += ";";
        saida += estado;
        return saida;
    }

    QString Endereco::obterEndereco() const
    {
        QString saida =  " CEP: "+ QString::number(cep) + " - " + cidade + " - " +estado;
        return saida;
    }
}


