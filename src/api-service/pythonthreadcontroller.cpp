#include "api-service/pythonthreadcontroller.h"

PythonThreadController::PythonThreadController()
    : m_thread(nullptr)
{
}

void PythonThreadController::useInterpreter()
{
    m_mutex.lock();
    m_thread = new PythonThread;
    m_thread_id = std::this_thread::get_id();
}

void PythonThreadController::releaseInterpreter()
{
    if (std::this_thread::get_id() != m_thread_id)
        return;
    m_thread_id = std::thread::id();
    delete m_thread;
    m_mutex.unlock();
}

PythonThreadController& PythonThreadController::instance()
{
    static PythonThreadController inst;
    return inst;
}
