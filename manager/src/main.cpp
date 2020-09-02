#include <QApplication>
#include <QTranslator>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    QTranslator translator;
    translator.load("manager_", "ts");
    app.installTranslator(&translator);
    window.show();
    return app.exec();
}
