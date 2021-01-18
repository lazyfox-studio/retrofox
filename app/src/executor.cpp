#include "app/executor.h"

void Executor::start(QString command)
{
    if (process.state() != QProcess::ProcessState::NotRunning)
    {
        //TODO: do something!
        return;
    }
    process.setProgram(command);
    connect(&process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), this, &Executor::recover);
    process.start();
    QThread::currentThread()->setPriority(QThread::Priority::IdlePriority);

}

void Executor::recover()
{
    QThread::currentThread()->setPriority(QThread::Priority::NormalPriority);
}
