#include <QApplication>

#include <api-service/api-service.h>

#include "manager/mainwindow.h"

int main(int argc, char *argv[])
{
    PythonMainThread py_main_thread;
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();
}
