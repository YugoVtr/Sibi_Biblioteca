#include "Usuario.h"

namespace Vitor
{
    Usuario::Usuario():
        cpf(0),
        nome(""),
        tipo(Undefined),
        email("")
    {

    }

    Usuario::Usuario(long long cpf, QString nome, TipoDoCliente tipo, QString email):
        cpf(cpf),
        nome(nome),
        tipo(tipo),
        email(email)
    {
        if(!validar(cpf)) throw QString("CPF invalido");
    }

    void Usuario::montarObjeto(QString &str)
    {
        QStringList strList = str.split(';');
        if(strList.size()!=4) throw QString("ERRO - montarObjeto - Usuario") ;
        if(!validar(strList[0].toLongLong())) throw QString("CPF invalido"); 

        try
        {
            cpf = strList[0].toLongLong();
            nome = strList[1];

            if(strList[2].toInt()==1){tipo=bibliotecario;}
            if(strList[2].toInt()==2){tipo=professor;}
            if(strList[2].toInt()==3){tipo=aluno;}

            email = strList[3];

            PersistenciaTelefone buscar_fone("../Arquivos/telefones.txt");
            telefone = buscar_fone.buscarDados(cpf);
            PersistenciaEndereco buscar_end("../Arquivos/enderecos.txt");
            endereco = buscar_end.buscarDados(cpf);
        }catch(QString){throw QString("Erro-CarregarComposições-Usuario");}
    }

    QString Usuario::desmontarObjeto() const
    {
        int type = tipo;
        QString saida = QString::number(cpf);
        saida += ";";
        saida += nome;
        saida += ";";
        saida += QString::number(type);
        saida += ";";
        saida += email;
        return saida;
    }

    bool Usuario::validar(long long numero)const
    {
        //valores que segue a regra matematica mas são invalidos
        if (numero==0) return false;
        if (numero==11111111111)return false;
        if (numero==22222222222)return false;
        if (numero==33333333333)return false;
        if (numero==44444444444)return false;
        if (numero==55555555555)return false;
        if (numero==66666666666)return false;
        if (numero==77777777777)return false;
        if (numero==88888888888)return false;
        if (numero>=99999999999)return false;

        //definir os digitos verificadores
        int digitoVerificador1=(numero%100)/10;
        int digitoVerificador2=(numero%10);
        int resultado1=0,resultado2=0;

        //Operação que valida o CPF - validando da ESQUERDA para a DIREITA
        numero/=10;
        for (int contador=2 ; contador <=11 ; contador++)
        {
            if (contador>2) resultado1+=(numero%10)*(contador-1);
            resultado2 += (numero%10)*contador;
            numero/=10;
        }
        resultado1=(resultado1*10)%11;
        if (resultado1==10) resultado1=0;

        resultado2=(resultado2*10)%11;
        if (resultado2==10) resultado2=0;

        //comparação entre o resultado e os digitos verificadores
        if(digitoVerificador1==resultado1&&digitoVerificador2==resultado2) return true;
        else return false;
    }

    void Usuario::realizarEmprestimo(Usuario &user, Biblioteca::Exemplar &item)
    {
        Biblioteca::PersistenciaExemplar mudar("../Arquivos/arquivoExemplar.txt");
        item.setStatus(false);
        mudar.alterar(item);

        int prazo = 5 ;
        if(user.getTipo()==professor) prazo = 15;

        Codigo cod;
        Emprestimo emp(cod.gerarCodigo(),user.getCpf(),item,prazo);
        PersistenciaEmprestimo colocar("../Arquivos/emprestimos.txt");
        colocar.incluir(emp);
    }

    void Usuario::realizarDevolucao(Biblioteca::Exemplar &item)
    {
        Vitor::PersistenciaEmprestimo busca("../Arquivos/emprestimos.txt");
        Vitor::Emprestimo mudar= busca.consultar(item.getCodigo());
        mudar.setDataDevolucao(QDate::currentDate());
        int atrazo = mudar.getDataDeEmprestimo().daysTo(mudar.getDataDevolucao());
        if(atrazo > mudar.getPrazo()) gerarMulta(mudar.getCliente(),atrazo*2);
        busca.alterar(mudar);
    }

    void Usuario::gerarMulta(long long cpf, float valor)
    {
        Mumu::Multa multa(cpf,valor,false);
        Mumu::PersistenciaMulta incluir;
        incluir.setNomeDoArquivoEmDisco("../Arquivo/arquivoMulta.txt");
        incluir.incluir(multa);
    }
}

