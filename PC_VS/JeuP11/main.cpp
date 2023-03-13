#include "PageMenu.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PageMenu w;
    w.show();
    return a.exec();
}
