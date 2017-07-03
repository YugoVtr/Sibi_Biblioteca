#include "frmCad_Livro.h"
#include "ui_frmCad_Livro.h"
#include <QRegExp>
#include "PersistenciaExemplar.h"

frmCad_Livro::frmCad_Livro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmCad_Livro)
{
    ui->setupUi(this);
    iniciarComboBoxEditora();
    iniciarComboBoxAutor();
    ui->anoSpinBox->setMaximum(2016);
    ui->anoSpinBox->setMinimum(1600);
    ui->anoSpinBox->setValue(2000);
    QRegExp reg("[0-9]*");
    QRegExpValidator *validar = new QRegExpValidator(reg);
    ui->isbnLineEdit->setValidator(validar);
    this->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,this->size(),qApp->desktop()->availableGeometry()));
}

frmCad_Livro::~frmCad_Livro()
{
    delete ui->isbnLineEdit->validator();
    delete ui;
}

void frmCad_Livro::iniciarComboBoxAutor() const
{
    Mumu::PersistenciaAutor autorPeristencia("../Arquivos/arquivoAutor.txt");
    QList<Mumu::Autor> *listaAutor = autorPeristencia.listagem();
    ui->autorComboBox->clear();
    while(!listaAutor->empty())
    {
        QString cod = QString::number(listaAutor->front().getCodigo());
        ui->autorComboBox->addItem(cod+"/"+listaAutor->front().getNome());
        listaAutor->pop_front();
    }
}

void frmCad_Livro::on_concluirPushButton_clicked()
{
    try{
        int codigo = Vitor::Codigo().gerarCodigo();
        long isbn = ui->isbnLineEdit->text().toLong();
        Biblioteca::PersistenciaLivro persistencia("../Arquivos/arquivoLivro.txt");
        if(persistencia.consultar(codigo)!="0") throw QString("Livro ja existe");
        QString titulo = ui->tituloLineEdit->text();
        int ano = ui->anoSpinBox->value();
        Biblioteca::Livro livro(codigo,isbn,titulo,ano);
        if(editoras.empty()) throw QString("Não é possivel cadastrar livro sem editoras");
        if(autores.empty()) throw QString("Não é possivel cadastrar livro sem autores");
        persistencia.incluir(livro);

        QString des =QString::number(livro.getCodigo())+" ";
        des += QString::number(livro.getIsbn())+" "+livro.getTitulo();
        des += " "+QString::number(livro.getAno())+" ";

        Biblioteca::PersistenciaLivroAutor persistenciaLivroAutor("../Arquivos/arquivoLinkLivroAutor.txt");
        for(int contador=0;contador<autores.size();contador++)
        {
            Biblioteca::LivroAutor livroAutor(autores.at(contador).getCodigo(),codigo);
            persistenciaLivroAutor.incluir(livroAutor);
            if(contador<=2) des += autores.at(contador).getNome()+" ";
        }
        if(autores.size()>2) des += " at al";

        Biblioteca::PersistenciaLivroEditora persistenciaLivroEditora("../Arquivos/arquivoLinkLivroEditora.txt");
        for(int contador=0;contador<editoras.size();contador++)
        {
            Biblioteca::LivroEditora livroEditora(codigo,editoras.at(contador).getCodigo());
            persistenciaLivroEditora.incluir(livroEditora);
        }

        int qtdExemplares = ui->exemplaresSpinBox->value();

        Biblioteca::PersistenciaExemplar exemplarPer("../Arquivos/arquivoExemplar.txt");

        Biblioteca::Exemplar exemplar;
        exemplar.setCodigo(Vitor::Codigo().gerarCodigo());
        exemplar.setNumeroDoExemplar(1);
        exemplar.setCirculavel(0);
        exemplar.setStatus(1);
        exemplar.setDescricao(des);
        exemplarPer.incluir(exemplar);
        for(int i=1;i<qtdExemplares;i++)
        {
            Biblioteca::Exemplar aux(Vitor::Codigo().gerarCodigo(),1,1,i+1,des);
            exemplarPer.incluir(aux);
        }


        QMessageBox::information(this,"Cadastrar","Livro cadastrado com sucesso");
        this->close();
    } catch(QString &erro) {
        QMessageBox::about(this,"Erro",erro);
    }
}

void frmCad_Livro::on_incluirAutorPushButton_clicked()
{
    try{
        QStringList aux = ui->autorComboBox->currentText().split('/');
        ui->autorComboBox->removeItem(ui->autorComboBox->currentIndex());
        int codigo = aux[0].toInt();
        QString nome = aux[1];
        autores.push_back(Mumu::Autor(codigo,nome));
        QMessageBox::about(this,"Autor","Autor incluido");
    } catch (QString &erro) {
        QMessageBox::about(this,"Erro",erro);
    }
}

//void frmCad_Livro::on_alterarPushButton_clicked()
//{
//    try{
//        long isbn = ui->isbnLineEdit->text().toLong();
//        Biblioteca::LivroPersistencia persistencia("../Arquivos/arquivoLivro.txt");
//        if(persistencia.consultar(isbn)=="0") throw QString("Livro não existe");
//        QString titulo = ui->tituloLineEdit->text();
//        int ano = ui->anoSpinBox->value();
//        Biblioteca::Livro livro(isbn,titulo,ano);
//        persistencia.alterar(livro);

//        Biblioteca::LivroAutorPersistencia persistenciaLivroAutor("../Arquivos/arquivoLinkLivroAutor.txt");

//        QList<Biblioteca::LivroAutor> lista;
//        for(int i=0; i<autores.size();i++)
//        {
//            Biblioteca::LivroAutor aux(autores[i].getCodigo(),isbn);
//            lista.push_back(aux);
//        }

//        persistenciaLivroAutor.alterar(lista);

//        Biblioteca::LivroEditoraPersistencia persistenciaLivroEditora("../Arquivos/arquivoLinkLivroEditora.txt");

//        QList<Biblioteca::LivroEditora> lista2;
//        for(int i=0; i<editoras.size();i++)
//        {
//            Biblioteca::LivroEditora aux(isbn,editoras[i].getCodigo());
//            lista2.push_back(aux);
//        }

//        persistenciaLivroEditora.alterar(lista2);

//        QMessageBox::information(this,"Alterar","Livro alterado com sucesso");
//        this->close();
//    } catch (QString &erro) {
//        QMessageBox::about(this,"Erro",erro);
//    }
//}

void frmCad_Livro::on_incluirEditoraPushButton_clicked()
{
    try{
        QStringList aux = ui->editoraComboBox->currentText().split('/');
        ui->editoraComboBox->removeItem(ui->editoraComboBox->currentIndex());
        int codigo = aux[0].toInt();
        QString nome = aux[1];
        QString cidade = aux[2];
        QString estado = aux[3];
        editoras.push_back(Biblioteca::Editora(codigo,nome,cidade,estado));
        QMessageBox::about(this,"Autor","Editora incluida");
    } catch (QString &erro) {
        QMessageBox::about(this,"Erro",erro);
    }
}

void frmCad_Livro::iniciarComboBoxEditora()const
{
    Biblioteca::PersistenciaEditora editoraPersistencia("../Arquivos/arquivoEditora.txt");
    QList<Biblioteca::Editora> *listaEditora = editoraPersistencia.listagem();
    ui->autorComboBox->clear();
    while(!listaEditora->empty())
    {
        QString cod = QString::number(listaEditora->front().getCodigo());
        QString nome = listaEditora->front().getNome();
        QString cidade = listaEditora->front().getCidade();
        QString estado = listaEditora->front().getEstado();

        ui->editoraComboBox->addItem(cod+"/"+nome+"/"+cidade+"/"+estado);
        listaEditora->pop_front();
    }
}
