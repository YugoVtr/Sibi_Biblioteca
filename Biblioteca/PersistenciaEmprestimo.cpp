#include "PersistenciaEmprestimo.h"

namespace Vitor
{
    void PersistenciaEmprestimo::incluir(Emprestimo &objeto) const
    {
        try
        {
            std::ofstream arquivo;
            arquivo.open(nome_No_Disco.toStdString().c_str(),std::ios::out|std::ios::app);
            if(!arquivo.is_open()){ throw QString("Erro-incluir-Emprestimo"); }
            arquivo<<objeto.desmontarObjeto().toStdString()+"\n";
            arquivo.close();
        }catch(QString &erro) {throw erro;}
    }

    void PersistenciaEmprestimo::alterar(Emprestimo &objeto) const
    {
        //Caso nao haja nenhum item no meu arquivo insiro na minha LISTA
        if(dados->indexOf(objeto)==-1) incluir(objeto);
        else
        {   //insiro na minha LISTA o objeto de acordo com sua posição
            (*dados)[dados->indexOf(objeto)] = objeto;

            std::ofstream arquivo;
            arquivo.open(nome_No_Disco.toStdString().c_str(),std::ios::out);
            if(!arquivo.is_open()){ throw QString("Erro-alterar-Emprestimo");}

            for(int contador=0;contador<dados->size();contador++)
            {
                //coloco no arquivo os dados que estão na minha LISTA
                arquivo<<(*dados)[contador].desmontarObjeto().toStdString()+"\n";
            }
            arquivo.close();
        }
    }

    void PersistenciaEmprestimo::carregarDados()
    {
        try
        {
            std::ifstream arquivo;
            arquivo.open(nome_No_Disco.toStdString().c_str());
            if(!arquivo.is_open()){ throw QString("Erro-listagem-Emprestimo");}

             //cria uma nova lista de EMPRESTIMO
            dados = new QList<Emprestimo>();
            std::string linha;
            getline(arquivo,linha);
            while(!arquivo.eof())
            {
                Emprestimo objeto;
                QString str = QString::fromStdString(linha);
                try
                {
                    objeto.montarObjeto(str);
                    //Insiro o objeto na LISTA
                    dados->push_back(objeto);
                }catch(QString &erro) { }
                getline(arquivo,linha);
            }
            arquivo.close();
        } catch(QString &erro) {throw erro;}
    }

    //Devolvo os emprestimos em forma de uma LISTA
    QList<Emprestimo> PersistenciaEmprestimo::buscarDados(long long cpf) const
    {
        try
        {
            std::ifstream arquivo;
            arquivo.open(nome_No_Disco.toStdString().c_str());
            if(!arquivo.is_open()){ throw QString("Erro-buscarDados-Emprestimo");}
            QList<Emprestimo> lista;
            std::string linha;
            getline(arquivo,linha);
            while(!arquivo.eof())
            {
                try
                {
                    Emprestimo objeto;
                    QString str = QString::fromStdString(linha);
                    if(str.split(';')[0].toLongLong()==cpf)
                    {
                        objeto.montarObjeto(str);
                        lista.push_back(objeto);
                    }
                    getline(arquivo,linha);
                }catch(QString &erro) {throw erro;}
            }
            arquivo.close();
            return lista;
        }
        catch(QString &erro){throw erro; }
    }

    //LISTA
    Emprestimo PersistenciaEmprestimo::consultar(long long cpf) const
    {
        for(int contador=0;contador<dados->size();contador++)
        {
            if(dados->at(contador).getCliente()==cpf)
            {
                return dados->at(contador);
            }
        }
        throw QString("Emprestimo não cadastrado - obter Emprestimo - Persistencia do Emprestimo");
    }

    //LISTA
    Emprestimo PersistenciaEmprestimo::consultar(int codigo) const
    {
        for(int contador=0;contador<dados->size();contador++)
        {
            if(dados->at(contador).getExemplar().getCodigo()==codigo)
            {
                return dados->at(contador);
            }
        }
        throw QString("Emprestimo não cadastrado - obter Emprestimo - Persistencia do Emprestimo");
    }
}

