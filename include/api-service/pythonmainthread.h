#pragma once

#include <Python.h>

#include "pythonenv.h"

/**
 * @ingroup api-service
 * @brief Main thread with parent interpreter
 * @details Class to represent and deploy Python interpreter in main thread
 * @warning You must instantiate it before any PythonThread (e.g. in main() function)
 */
class PythonMainThread
{
    /// Saved GIL state
    PyGILState_STATE m_gil_state;

    /// Saved main thread state
    PyThreadState* m_thread_state;

public:
    /// Default constructor
    PythonMainThread();

    /// Destructor
    ~PythonMainThread();
};
