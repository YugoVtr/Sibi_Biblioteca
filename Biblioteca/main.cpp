#include "frmJanelaPrincipal.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    frmJanelaPrincipal w;
    w.show();

    return a.exec();
}
