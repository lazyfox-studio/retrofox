#pragma once

#include <QWidget>

namespace Ui {
class GameWindow;
}

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    GameWindow(std::string path, std::string name, /*date*/);
    ~GameWindow();

private:
    Ui::GameWindow *ui;
};
