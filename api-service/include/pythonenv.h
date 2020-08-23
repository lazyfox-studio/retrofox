#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <stdexcept>
#include <string>
#include <map>

#include "pythonref.h"

/**
 * @ingroup api-service
 * @brief Python environment controller
 * @details Class to manage Python interpreter and its environment
 */
class PythonEnv
{
protected:
    /// Path to modules ('scripts' folder)
    const std::string c_modules_path;

    /// Map with py-references to loaded modules
    std::map<std::string, PyObject*> m_modules;

    /// Default constructor
    PythonEnv();

    /**
     * @brief Creates a py-reference to callable object
     * @details Service method
     * @param module_name Name of loaded module
     * @param func_name Name of function in module
     * @return Py-reference to callable object (if function exists in module)
     */
    PyObject* createCallableObject(const std::string& module_name, const std::string& func_name);

public:
    /// Destructor
    ~PythonEnv();

    /**
     * @brief Loads module from 'scripts' folder (no .py extension needed)
     * @param module_name Module name (no .py extension needed)
     * @return True on success
     */
    bool loadModule(const std::string& module_name);


    /**
     * @brief Calls Python function and returns its result
     * @details For functions with no arguments
     * @param module_name Module name
     * @param func_name Function name
     * @return Reference to result object
     */
    PythonRef callFunction(const std::string& module_name, const std::string& func_name);

    /**
     * @brief Calls Python function and returns its result
     * @details For functions with one argument with type int
     * @param module_name Module name
     * @param func_name Function name
     * @param int_arg Argument for passing to function
     * @return Reference to result object
     */
    PythonRef callFunction(const std::string& module_name, const std::string& func_name, long int_arg);

    /**
     * @brief Calls Python function and returns its result
     * @details For functions with one argument with type str
     * @param module_name Module name
     * @param func_name Function name
     * @param str_arg Argument for passing to function
     * @return Reference to result object
     */
    PythonRef callFunction(const std::string& module_name, const std::string& func_name, const std::string& str_arg);

    /**
     * @brief Returns environment instance
     * @return Instance reference
     */
    static PythonEnv& instance();
};
