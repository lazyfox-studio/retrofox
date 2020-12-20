#pragma once

#include <mutex>
#include <thread>

#include "pythonthread.h"

/**
 * @ingroup api-service
 * @brief Thread sub-interpreter controller
 * @details Class for controlling sub-interpreters with mutex mechanism.
 * Usage example:
 * @code{.cpp}
 * #include <thread>
 * #include <api-service.h>
 * 
 * void py_thread()
 * {
 *   PythonThreadController::instance.useInterpreter();
 *   // ... do some stuff with python
 *   PythonThreadController::instance.releaseInterpreter();
 * }
 * 
 * int main()
 * {
 *   PythonMainThread py_main_thread;
 *   PythonThreadController::instance.useInterpreter();
 *   // ... do some stuff with python
 *   PythonThreadController::instance.releaseInterpreter();
 *   std::thread thread(py_thread);
 *   py_thread.join();
 *   return 0;
 * }
 * @endcode
 */
class PythonThreadController
{
    /// ID of thread that interpreter is currently using
    std::thread::id m_thread_id;

    /// Thread sub-interpreter instance
    PythonThread* m_thread;

    /// Own mutex
    std::mutex m_mutex;

    /// Default constructor
    PythonThreadController();

public:
    /// Destructor
    ~PythonThreadController() = default;

    /// Waits for interpreter to be released by another thread and gives it to current one
    void useInterpreter();

    /// Releases interpreter holded by current thread to could be acquired by another one
    void releaseInterpreter();

    /**
     * @brief Returns thread controller instance
     * @return Instance reference
     */
    static PythonThreadController& instance();
};
