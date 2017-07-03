#ifndef FRMCONSULTAACERVO_H
#define FRMCONSULTAACERVO_H

#include <QWidget>

namespace Ui {
class frmConsultaAcervo;
}

class frmConsultaAcervo : public QWidget
{
    Q_OBJECT

public:
    explicit frmConsultaAcervo(QWidget *parent = 0);
    ~frmConsultaAcervo();

private slots:
    void on_pesquisarPushButton_clicked();
    void consultarTitulo()const;
    void consultarEditora()const;
    void consultarAutor()const;
    void consultarISBN()const;
    void limpar()const;

private:
    Ui::frmConsultaAcervo *ui;
};

#endif // FRMCONSULTAACERVO_H
