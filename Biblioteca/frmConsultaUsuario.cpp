#include "frmConsultaUsuario.h"
#include "ui_frmConsultaUsuario.h"

frmConsultaUsuario::frmConsultaUsuario(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::frmConsultaUsuario)
{
    ui->setupUi(this);
    ui->tableWidget_Usuarios->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            this->size(),
            qApp->desktop()->availableGeometry()
        )
    );
    this->setFixedSize(this->width(),this->height());
}

frmConsultaUsuario::~frmConsultaUsuario()
{
    limparGrid();
    delete ui;
}

void frmConsultaUsuario::on_action_Novo_Cadastro_triggered()
{
    frmCad_Usuario novoUser;
    novoUser.setModal(true);
    novoUser.exec();
}
void frmConsultaUsuario::limparGrid()const
{
    for(int linha=0;linha<ui->tableWidget_Usuarios->rowCount();linha++)
        for(int coluna=0;coluna<ui->tableWidget_Usuarios->columnCount();coluna++)
            delete ui->tableWidget_Usuarios->item(linha,coluna);
    ui->tableWidget_Usuarios->setRowCount(0);
}

void frmConsultaUsuario::on_action_Consultar_Cadastros_triggered()
{
    try
    {
        limparGrid();

        QString url_Mais = "../Arquivos/Imagens/mais.png";
        QPixmap img_Mais(url_Mais);
        QIcon mais(img_Mais);

        Vitor::PersistenciaUsuario mostrar("../Arquivos/usuarios.txt");
        QList<Vitor::Usuario>* lista = mostrar.listagem();
        if(lista->empty()) {QMessageBox::information(this,"AVISO","NÃO HÁ USUARIOS CADASTRADOS");}
        else
        {
            for(int contador = 0 ; !lista->empty() ; contador++)
            {
                QString cpf = QString::number(lista->front().getCpf());
                while(cpf.size()!=11) cpf = "0"+cpf;

                QString nome = lista->front().getNome();

                QString tipo = "";
                if(lista->front().getTipo()==1) tipo = "bibliotecario";
                if(lista->front().getTipo()==2) tipo = "professor";
                if(lista->front().getTipo()==3) tipo = "aluno";

                QString email = lista->front().getEmail();

                QString telefone = "";
                if(!lista->front().getTelefone().isEmpty())
                    telefone = lista->front().getTelefone().front().obterNumero();

                QString endereco = "";
                if(!lista->front().getEndereco().isEmpty()) endereco =
                        lista->front().getEndereco().front().obterEndereco();

                ui->tableWidget_Usuarios->setRowCount(ui->tableWidget_Usuarios->rowCount()+1);
                ui->tableWidget_Usuarios->setItem(contador,0,new QTableWidgetItem(cpf));
                ui->tableWidget_Usuarios->setItem(contador,1,new QTableWidgetItem(nome));
                ui->tableWidget_Usuarios->setItem(contador,2,new QTableWidgetItem(tipo));
                ui->tableWidget_Usuarios->setItem(contador,3,new QTableWidgetItem(email));
                ui->tableWidget_Usuarios->setItem(contador,4,new QTableWidgetItem(mais,telefone));
                ui->tableWidget_Usuarios->setItem(contador,5,new QTableWidgetItem(""));
                ui->tableWidget_Usuarios->setItem(contador,6,new QTableWidgetItem(mais,endereco));
                lista->pop_front();
            }
            ui->tableWidget_Usuarios->resizeColumnToContents(1);
            ui->tableWidget_Usuarios->resizeColumnToContents(3);
            ui->tableWidget_Usuarios->resizeColumnToContents(4);
            alinhamento(ui->tableWidget_Usuarios,ui->tableWidget_Usuarios->rowCount(),ui->tableWidget_Usuarios->columnCount());
        }
        if(lista) delete lista;
    }catch(QString &erro){QMessageBox::critical(this,"ERRO",erro);}
}
void frmConsultaUsuario::alinhamento(QTableWidget *lista,int linhas,int colunas)const
{
    try
    {
        for(int linha=0; linha<linhas;linha++)
            for(int coluna=0; coluna<colunas;coluna++)
                lista->item(linha,coluna)->setTextAlignment(Qt::AlignCenter);
    }catch(...){}
}

void frmConsultaUsuario::on_tableWidget_Usuarios_cellClicked(int row, int column)
{
    try
    {
        if(column==4)
        {
            frmConsultaTelefone telefones(ui->tableWidget_Usuarios->item(row,0)->text().toLongLong());
            telefones.setModal(true);
            telefones.exec();
        }
        if(column==6)
        {
            frmConsultaEndereco enderecos(ui->tableWidget_Usuarios->item(row,0)->text().toLongLong());
            enderecos.setModal(true);
            enderecos.exec();
        }
    } catch (QString &erro) { QMessageBox::critical(this,"ERRO",erro);   }
}

void frmConsultaUsuario::on_pushButton_AlterarCadastro_clicked()
{
    frmJanelaPrincipal *w;
    w = new frmJanelaPrincipal(this);
    w->show();
    this->hide();
}
