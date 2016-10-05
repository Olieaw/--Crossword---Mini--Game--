#include "interface.h"
#include "fieldgui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Interface i;
    i.show();

    return a.exec();
}
