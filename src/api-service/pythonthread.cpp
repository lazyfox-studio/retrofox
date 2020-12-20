#include "api-service/pythonthread.h"

PythonThread::PythonThread()
{
    m_main_gil_state = PyGILState_Ensure();
    m_old_thread_state = PyThreadState_Get();
    m_new_thread_state = Py_NewInterpreter();
    PyThreadState_Swap(m_new_thread_state);
    m_sub_thread_state = PyEval_SaveThread();
    m_sub_gil_state = PyGILState_Ensure();
}

PythonThread::~PythonThread()
{
    PyGILState_Release(m_sub_gil_state);
    PyEval_RestoreThread(m_sub_thread_state);
    Py_EndInterpreter(m_new_thread_state);
    PyThreadState_Swap(m_old_thread_state);
    PyGILState_Release(m_main_gil_state);
}
