#ifndef VIDEO_H
#define VIDEO_H
#include <ITransformarDados.h>

namespace Mumu
{
class Video : public ITransformaDados
{
private:
    int codigo;
    int anoDeProducao;
    int tempoDeDuracao;
    QString titulo;
    QString genero;
    QString produtora;
public:
    inline Video() { }
    inline Video(QString &str){montarObjeto(str);}
    inline Video(std::string &str) {QString x = QString::fromStdString(str); montarObjeto(x);}
    Video(int codigo, int ano, int tempo,QString titulo, QString genero,QString produtora);

    inline ~Video() { }

    void setCodigo(int codigo);
    void setAnoDeProducao(int ano);
    void setTempoDeDuracao(int tempo);
    inline void setTitulo(QString nome) {this->titulo = nome;}
    inline void setGenero(QString genero){this->genero = genero;}
    inline void setProdutora(QString produtora){this->produtora = produtora;}

    inline int getCodigo()const {return this->codigo;}
    inline int getAnoDeProducao(){return this->anoDeProducao;}
    inline int getTempoDeDuracao(){return this->tempoDeDuracao;}
    inline QString getTitulo()const {return this->titulo;}
    inline QString getGenero()const {return this->genero;}
    inline QString getProdutora()const{return this->produtora;}

    void montarObjeto(QString &str);
    QString desmontarObjeto() const;
};
}
#endif // VIDEO_H
