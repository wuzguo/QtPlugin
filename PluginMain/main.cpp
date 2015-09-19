#include "mainwindow.h"
#include <QApplication>

#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication appc(argc, argv);

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);

    MainWindow wmin;
    wmin.show();

    return appc.exec();
}
