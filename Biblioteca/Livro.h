#ifndef LIVRO_H
#define LIVRO_H

#include <QString>
#include <QStringList>
#include "ITransformarDados.h"
#include "Autor.h"
#include "Editora.h"
#include "Exemplar.h"

namespace Biblioteca
{

class Livro : public ITransformaDados
{
    int codigo;
    long isbn;
    QString titulo;
    int ano;
    QList<Exemplar> exemplares;
    QList<Mumu::Autor> listAutores;
    QList<Editora> listEditoras;
public:
    Livro();
    Livro(int codigo,long isbn,QString &titulo,int ano);
    //Livro(int codigo,long isbn, QString &titulo, int ano,QList<Mumu::Autor> list);

    void setCodigo(int value) {codigo = value;}
    void setIsbn(long value) {isbn = value;}
    void setTitulo(const QString &value) {titulo = value;}
    void setAno(int value) {ano = value;}
    void setAutor(Mumu::Autor &autor) {listAutores.push_back(autor);}
    void setEditora(Editora &editora) {listEditoras.push_back(editora);}
    void setExemplar(Exemplar &exemplar) {exemplares.push_back(exemplar);}

    int getCodigo()const {return codigo;}
    long getIsbn() const {return isbn;}
    QString getTitulo() const {return titulo;}
    int getAno() const {return ano;}
    QList<Mumu::Autor> getAutores() const {return listAutores;}
    QList<Editora> getEditoras() const {return listEditoras;}
    QList<Exemplar> getExemplares() const {return exemplares;}


    void montarObjeto(QString &str,QList<Editora> list);
    void montarObjeto(QString &str, QList<Editora> listE, QList<Mumu::Autor> listA);
    void montarObjeto(QString &str,QList<Mumu::Autor> list);
    void montarObjeto(QString &str);
    QString desmontarObjeto()const;
};

}

#endif // LIVRO_H
