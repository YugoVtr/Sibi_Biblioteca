#include "frmReserva.h"
#include "ui_frmReserva.h"
#include <QMessageBox>

frmReserva::frmReserva(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmReserva)
{
    ui->setupUi(this);
    try
    {
        ui->dateEdit->setDate(QDate().currentDate());

        Vitor::PersistenciaUsuario persistirUsuario("../Arquivos/usuarios.txt");
        listaUsuario = persistirUsuario.listagem();

        Biblioteca::PersistenciaExemplar persistirExemplar("../Arquivos/arquivoExemplar.txt");
        listaExemplar = persistirExemplar.listagem();

        //exemplares
        for(int i = 0; i < listaExemplar->size(); i++)
        {
            Biblioteca::Exemplar exemplar = listaExemplar->at(i);
            int codigo = exemplar.getCodigo();
            int numeroExemplar = exemplar.getNumeroDoExemplar();
            ui->comboBoxExemplar->addItem(QString::number(codigo) + " / Numero: Exemplar " + QString::number(numeroExemplar));
        }


        //usuarios
        for(int i = 0; i < listaUsuario->size(); i++)
        {
            Vitor::Usuario usuario = listaUsuario->at(i);
            long long cpf = usuario.getCpf();
            QString nome = usuario.getNome();
            ui->comboBoxNomeCliente->addItem(QString::number(cpf) + " / Usuario " + nome);
        }


    }
    catch(QString &erro){QMessageBox::information(this,"Reserva",erro);}
}

frmReserva::~frmReserva()
{
    delete ui;
}

void frmReserva::on_pushButtonSair_clicked()
{
    exit(1);
}

void frmReserva::on_pushButtonReservar_clicked()
{
    try
    {
        Mumu::Reserva novaReserva;
        Biblioteca::Exemplar exemplar;
        QDate data(ui->dateEdit->date());

        Biblioteca::PersistenciaExemplar persistirExemplar("../Arquivos/arquivoExemplar.txt");
        Mumu::PersistirReserva persistirReserva;
        persistirReserva.setNomeDoArquivoNoDisco("../Arquivos/arquivoReserva.txt");

        //EXEMPAR
        QStringList aux = ui->comboBoxExemplar->currentText().split('/');
        int codigo = aux.at(0).toInt();
        QString linhaExemplar = persistirExemplar.consultar(codigo);

        //pega o codigo da comboBox
        if(linhaExemplar == "0")
            throw QString ("Erro no exemplar form");

        //USUARIO
        int cpf = ui->comboBoxNomeCliente->currentIndex();
        Vitor::Usuario usuario = listaUsuario->at(cpf);




        //faz a reserva
        exemplar.montarObjeto(linhaExemplar);
        novaReserva.setDiaReservadoQdate(data);
        novaReserva.setItemReservadoExemplar(exemplar);
        novaReserva.setClienteReservaUsuario(usuario);
        persistirReserva.incluir(novaReserva);
        QMessageBox::information(this,"Reserva","Dados gravados");
    }
    catch(QString &erro){QMessageBox::information(this,"Reserva",erro);}
}
