#pragma once

#include <QObject>

#include <cstdlib>

class Executor : public QObject
{
    Q_OBJECT

public:
    Q_INVOKABLE static void start(QString command);
};
