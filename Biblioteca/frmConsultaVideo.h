#ifndef FRMCONSULTAVIDEO_H
#define FRMCONSULTAVIDEO_H
#include <PersistenciaVideo.h>

#include <QDialog>
#include <QDesktopWidget>
#include <QStyle>

namespace Ui {
class frmConsultaVideo;
}

class frmConsultaVideo : public QDialog
{
    Q_OBJECT

public:
    explicit frmConsultaVideo(QWidget *parent = 0);
    ~frmConsultaVideo();

private:
    Ui::frmConsultaVideo *ui;
};

#endif // FRMCONSULTAVIDEO_H
