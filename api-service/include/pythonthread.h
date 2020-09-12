#pragma once

#include <Python.h>

/**
 * @ingroup api-service
 * @brief Thread sub-interpreter
 * @details Class for initialization sub-interpreters in any threads of application
 * @note You need to instantiate it in thread if you want to call Python functions, but it is recommended to use PythonThreadController with helper functions
 */
class PythonThread
{
    /// Main interpreter GIL state
    PyGILState_STATE m_main_gil_state;

    /// Sub-interpreter GIL state
    PyGILState_STATE m_sub_gil_state;

    /// Current thread state for main interpreter
    PyThreadState* m_old_thread_state;

    /// Thread state for new sub-interpreter
    PyThreadState* m_new_thread_state;

    /// Saved thread state when unlocking GIL
    PyThreadState* m_sub_thread_state;

public:
    /// Default constructor
    PythonThread();

    /// Destructor
    ~PythonThread();
};
