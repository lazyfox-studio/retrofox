#include <QApplication>

#include <api-service.h>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    PythonMainThread py_main_thread;
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();
}
