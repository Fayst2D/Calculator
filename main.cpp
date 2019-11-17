#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow main;
    Calculator *w = new Calculator;
    main.setMinimumSize(300,400);
    main.setMaximumSize(300,400);
    main.setCentralWidget(w);
    main.show();

    return a.exec();
}
