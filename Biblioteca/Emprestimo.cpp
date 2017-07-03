#include "Emprestimo.h"

namespace Vitor
{
    Emprestimo::Emprestimo():
        id(0),
        cliente(0),
        exemplar(),
        dataDeEmprestimo(QDate::currentDate()),
        dataDevolucao(0,0,0)
    {

    }

    Emprestimo::Emprestimo(int id, long long cliente, Biblioteca::Exemplar exemplar,int prazo):
        id(id),
        cliente(cliente),
        exemplar(exemplar),
        dataDeEmprestimo(QDate::currentDate()),
        dataDevolucao(0,0,0),
        prazo(prazo)
    {
    }

    bool Emprestimo::isDevolvido()
    {
        return dataDevolucao.isNull();
    }

    void Emprestimo::montarObjeto(QString &str)
    {
        try
        {
            QStringList strList = str.split(';');
            if(strList.size()!=6) throw QString("ERRO - montarObjeto - Emprestimo") ;

            id = strList[0].toInt();

            cliente = strList[1].toLongLong();

            Biblioteca::PersistenciaExemplar carregarExemplar("../Arquivos/arquivoExemplar.txt");
            Biblioteca::Exemplar exem;
            QString valor = carregarExemplar.consultar(strList[2].toInt());
            exem.montarObjeto(valor);
            exemplar = exem;

            QStringList dataList_1 = strList[3].split('/');
            QDate data_1(dataList_1[0].toInt(),dataList_1[1].toInt(),dataList_1[2].toInt());
            dataDeEmprestimo = data_1;

            QStringList dataList_2 = strList[4].split('/');
            QDate data_2(dataList_2[0].toInt(),dataList_2[1].toInt(),dataList_2[2].toInt());
            dataDevolucao = data_2;

            prazo = strList[5].toInt();

        } catch (QString &erro) {throw QString(erro);  }
    }

    QString Emprestimo::desmontarObjeto() const
    {
        QString dataEmprestimo("");
        QString dataDeDevolucao("");

        dataEmprestimo += QString::number(dataDeEmprestimo.year())+"/";
        dataEmprestimo += QString::number(dataDeEmprestimo.month())+"/";
        dataEmprestimo += QString::number(dataDeEmprestimo.day())+"/";

        dataDeDevolucao += QString::number(dataDevolucao.year())+"/";
        dataDeDevolucao += QString::number(dataDevolucao.month())+"/";
        dataDeDevolucao += QString::number(dataDevolucao.day())+"/";

        QString saida = QString::number(id);
        saida += ";";
        saida += QString::number(cliente);
        saida += ";";
        saida += QString::number(exemplar.getCodigo());
        saida += ";";
        saida += dataEmprestimo;
        saida += ";";
        saida += dataDeDevolucao;
        saida += ";";
        saida += QString::number(prazo);
        return saida;
    }

}

