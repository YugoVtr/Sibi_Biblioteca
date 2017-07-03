#ifndef FRMCAD_VIDEO_H
#define FRMCAD_VIDEO_H

#include <QDialog>
#include <Video.h>
#include <PersistenciaVideo.h>
#include <QDesktopWidget>
#include <QStyle>

namespace Ui {
class frmCad_Video;
}

class frmCad_Video : public QDialog
{
    Q_OBJECT

public:
    explicit frmCad_Video(QWidget *parent = 0);
    ~frmCad_Video();

private slots:
    void on_pushButtonGravar_clicked();

    void on_pushButtonSair_clicked();

    void limpar();

    void on_pushButtonLimpar_clicked();

    void on_pushButtonConsultar_clicked();

private:
    Ui::frmCad_Video *ui;
    QList<Mumu::Video> *lista;
    Mumu::PersistenciaVideo persistir;
    QString nomeDoArquivoNoDisco;
};

#endif // FRMCAD_VIDEO_H
