#include "app/executor.h"

void Executor::start(QString command)
{
    std::system(command.toStdString().c_str());
}
