#pragma once

#include <QMainWindow>
//#include "ui_window.h" // commented for testing purposes

class Window : public QMainWindow
{
    Q_OBJECT

public:
    Window(QWidget *parent = Q_NULLPTR);
    ~Window();

private:
    //Ui::Window ui; // commented for testing purposes
};
