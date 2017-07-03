#include "frmJanelaPrincipal.h"
#include "ui_frmJanelaPrincipal.h"


frmJanelaPrincipal::frmJanelaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::frmJanelaPrincipal),
    adm()
{
    ui->setupUi(this);
    this->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,this->size(),qApp->desktop()->availableGeometry()));
    Vitor::PersistenciaUsuario busca("../Arquivos/usuarios.txt");
    adm = busca.consultar(70090277147);

    ui->codigoDoExemplarLabel->setVisible(false);
    ui->codigoDoExemplarLineEdit->setVisible(false);
    ui->cPFLabel->setVisible(false);
    ui->cPFLineEdit->setVisible(false);
    ui->pushButton_OK->setVisible(false);

    ui->codigoDoExemplarLabel_Devolucao->setVisible(false);
    ui->codigoDoExemplarLineEdit_Devolucao->setVisible(false);
    ui->pushButton_OK_Devolucao->setVisible(false);

    ui->widget_Reserva->setVisible(false);
}

frmJanelaPrincipal::~frmJanelaPrincipal()
{
    delete ui;
}


void frmJanelaPrincipal::on_actionCadastrar_triggered()
{
    frmCad_Usuario w;
    w.setModal(true);
    w.exec();
}

void frmJanelaPrincipal::on_actionConsulta_triggered()
{
    frmConsultaUsuario *w = new frmConsultaUsuario();
    w->show();
    this->hide();
}

void frmJanelaPrincipal::on_actionLivro_triggered()
{
    frmCad_Livro w;
    w.setModal(true);
    w.exec();
}

void frmJanelaPrincipal::on_actionRevista_triggered()
{
    frmCad_Revista w;
    w.setModal(true);
    w.exec();
}

void frmJanelaPrincipal::on_actionArtigo_triggered()
{
    frmCad_Artigo w;
    w.setModal(true);
    w.exec();
}

void frmJanelaPrincipal::on_actionVideo_triggered()
{
    frmCad_Video w;
    w.setModal(true);
    w.exec();
}

void frmJanelaPrincipal::on_actionLivro_2_triggered()
{
    frmConsultaLivro w;
    w.setModal(true);
    w.exec();
}

void frmJanelaPrincipal::on_actionRevista_2_triggered()
{
    frmConsultaVideo w;
    w.setModal(true);
    w.exec();
}

void frmJanelaPrincipal::on_actionArtigo_2_triggered()
{
    frmConsultaVideo w;
    w.setModal(true);
    w.exec();
}

void frmJanelaPrincipal::on_actionVideo_2_triggered()
{
    frmConsultaVideo w;
    w.setModal(true);
    w.exec();
}

void frmJanelaPrincipal::on_actionCadastro_triggered()
{
    frmCad_Editora w;
    w.setModal(true);
    w.exec();
}

void frmJanelaPrincipal::on_actionConsulta_2_triggered()
{
    frmConsultaEditora w;
    w.setModal(true);
    w.exec();
}

void frmJanelaPrincipal::on_actionCadastro_2_triggered()
{
    frmCad_Autor w;
    w.setModal(true);
    w.exec();
}

void frmJanelaPrincipal::on_actionConsulta_3_triggered()
{
    frmCosultaAutor w;
    w.setModal(true);
    w.exec();
}

void frmJanelaPrincipal::on_actionExemplar_triggered()
{
    frmConsultaExemplar w;
    w.setModal(true);
    w.exec();
}

void frmJanelaPrincipal::on_pushButton_OK_clicked()
{
    try
    {
    Vitor::PersistenciaUsuario busca("../Arquivos/usuarios.txt");
    Vitor::Usuario user = busca.consultar(ui->cPFLineEdit->text().toLongLong());

    Biblioteca::PersistenciaExemplar busca2("../Arquivos/arquivoExemplar.txt");
    Biblioteca::Exemplar item;
    QString linha = busca2.consultar(ui->codigoDoExemplarLineEdit->text().toInt());
    item.montarObjeto(linha);

    adm.realizarEmprestimo(user,item);
    QMessageBox::information(this,"CONCLUIDO","CONCLUIDO");
    }catch(QString &erro){QMessageBox::critical(this,"Erro",erro);}
}


void frmJanelaPrincipal::on_pushButton_OK_Devolucao_clicked()
{
    Biblioteca::PersistenciaExemplar busca2("../Arquivos/arquivoExemplar.txt");
    Biblioteca::Exemplar item;
    QString linha = busca2.consultar(ui->codigoDoExemplarLineEdit_Devolucao->text().toInt());
    item.montarObjeto(linha);

    adm.realizarDevolucao(item);
    QMessageBox::information(this,"CONCLUIDO","CONCLUIDO");
}

void frmJanelaPrincipal::on_pushButton_clicked()
{
    ui->codigoDoExemplarLabel->setVisible(!ui->codigoDoExemplarLabel->isVisible());
    ui->codigoDoExemplarLineEdit->setVisible(!ui->codigoDoExemplarLineEdit->isVisible());
    ui->cPFLabel->setVisible(!ui->cPFLabel->isVisible());
    ui->cPFLineEdit->setVisible(!ui->cPFLineEdit->isVisible());
    ui->pushButton_OK->setVisible(!ui->pushButton_OK->isVisible());
}

void frmJanelaPrincipal::on_pushButton_2_clicked()
{
    ui->codigoDoExemplarLabel_Devolucao->setVisible(!ui->codigoDoExemplarLabel_Devolucao->isVisible());
    ui->codigoDoExemplarLineEdit_Devolucao->setVisible(!ui->codigoDoExemplarLineEdit_Devolucao->isVisible());
    ui->pushButton_OK_Devolucao->setVisible(!ui->pushButton_OK_Devolucao->isVisible());
}

void frmJanelaPrincipal::on_pushButton_Reserva_clicked()
{
    ui->widget_Reserva->setVisible(!ui->widget_Reserva->isVisible());
}
