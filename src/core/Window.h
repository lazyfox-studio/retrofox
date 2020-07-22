#pragma once

#include <QMainWindow>
#include "ui_Window.h"

class Window : public QMainWindow
{
    Q_OBJECT

public:
    Window(QWidget *parent = Q_NULLPTR);
    ~Window();

private:
    Ui::Window ui;
};
