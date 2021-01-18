#pragma once

#include <QObject>

#include <QProcess>
#include <QThread>

class Executor : public QObject
{
    Q_OBJECT

protected:
    QProcess process;

public:
    Q_INVOKABLE void start(QString command);

public slots:
    static void recover();
};
