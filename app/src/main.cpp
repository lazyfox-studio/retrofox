#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <database/database.h>

#include "app/executor.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    Database::QmlInterface::addDatabase("testbase.db", "testbase");
    qmlRegisterType<Database::QmlInterface>("Database", 1, 0, "Database");
    qmlRegisterType<Executor>("Executor", 1, 0, "Executor");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/components/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
