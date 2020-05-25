#include "mainwindow.h"


#include <QApplication>

int main(int argc, char *argv[])
{
\
    myseminit(MAXSEM1); // 2 sem, 50 val

    QApplication a(argc, argv);
    MainWindow w;


    w.show();
    return a.exec();

}


