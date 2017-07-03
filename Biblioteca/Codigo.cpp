#include "Codigo.h"

namespace Vitor
{
    Codigo::Codigo():
        value(1)
    {

    }

    int Codigo::gerarCodigo()
    {
        try
        {
            QFile arquivo("../Arquivos/codigos.txt");
            if(!arquivo.open(QIODevice::ReadWrite | QIODevice::Text)){ throw QString("Erro-Gerar_Codigo"); }
            QTextStream in(&arquivo);
            QString linha = in.readAll();
            value = linha.toInt();
            arquivo.resize(0);
            in << QString::number(value+1)+"\n";
            arquivo.close();
            return value;
        }catch(QString &erro) {throw erro;}
    }
}

