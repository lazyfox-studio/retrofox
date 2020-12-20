#include "pythonmainthread.h"

PythonMainThread::PythonMainThread()
{
    PythonEnv::instance().initialize();
    PyEval_InitThreads(); // threads and gil mechanism initialization
    m_gil_state = PyGILState_Ensure(); // aquire gil state now
    m_thread_state = PyEval_SaveThread(); // save main thread and release gil
    // now gil unlocked here, we can lock it from other threads
}

PythonMainThread::~PythonMainThread()
{
    // gil must be unlocked here - all PythonSubThreads are destructed
    PyEval_RestoreThread(m_thread_state); // restore main thread and aquire gil state
    PyGILState_Release(m_gil_state); // save state and release gil
    PythonEnv::instance().finalize();
}
