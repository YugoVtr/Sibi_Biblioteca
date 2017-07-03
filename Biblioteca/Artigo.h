#ifndef ARTIGO_H
#define ARTIGO_H
#include<Autor.h>
#include <QList>
#include <ITransformarDados.h>
namespace Mumu
{
class Artigo : public ITransformaDados
{
private:
    int codigo;
    QString titulo;
    QString Area;
    int anoPublicacao;
    QList<Autor> listAutores;
public:
    //construtores
    Artigo() { }
    Artigo(int codigo,QString titulo,QString area, int anoPublicacao);
    Artigo(int codigo,QString titulo,QString area,QList<Autor>list);
    Artigo(std::string &str, QList<Autor> list);
    Artigo(QString &str, QList<Autor>list){montarObjeto(str,list);}
    Artigo(std::string &str);


    //destrutor
    inline  ~Artigo() { }

    void setCodigo(int codigo);
    inline void setTitulo(QString titulo) { this->titulo = titulo;}
    inline void setArea(QString Area) { this->Area = Area;}
    inline void setAutor(Autor &autor){listAutores.push_front(autor);}
    void setAnoPublicacao(int value);

    inline int getCodigo()const{return this->codigo;}
    inline QString getTitulo()const{return this->titulo;}
    inline QString getArea()const{return this->Area;}
    inline QList<Autor> getAutores()const{return listAutores;}
    int getAnoPublicacao() const;

    void montarObjeto(QString &str, QList<Autor> list);
    void montarObjeto(QString &str);
    QString desmontarObjeto() const;

};
}

#endif // ARTIGO_H
