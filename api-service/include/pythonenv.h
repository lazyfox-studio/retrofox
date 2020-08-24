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

    template<typename ArgType>
    PyObject* createArgObject(ArgType arg);

    PythonRef processFunctionCall(PyObject* function, PyObject* args);

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
     * @details For functions with one argument
     * @param module_name Module name
     * @param func_name Function name
     * @param arg Argument for passing to function
     * @return Reference to result object
     */
    template<typename Arg1Type>
    PythonRef callFunction(const std::string& module_name, const std::string& func_name, Arg1Type arg1);

    /**
     * @brief Calls Python function and returns its result
     * @details For functions with two arguments
     * @param module_name Module name
     * @param func_name Function name
     * @param arg1 Argument for passing to function
     * @param arg2 Argument for passing to function
     * @return Reference to result object
     */
    template<typename Arg1Type, typename Arg2Type>
    PythonRef callFunction(const std::string& module_name, const std::string& func_name, Arg1Type arg1, Arg2Type arg2);

    /**
     * @brief Calls Python function and returns its result
     * @details For functions with three arguments
     * @param module_name Module name
     * @param func_name Function name
     * @param arg1 Argument for passing to function
     * @param arg2 Argument for passing to function
     * @param arg3 Argument for passing to function
     * @return Reference to result object
     */
    template<typename Arg1Type, typename Arg2Type, typename Arg3Type>
    PythonRef callFunction(const std::string& module_name, const std::string& func_name, Arg1Type arg1, Arg2Type arg2, Arg3Type arg3);

    /**
     * @brief Returns environment instance
     * @return Instance reference
     */
    static PythonEnv& instance();
};

template<typename Arg1Type>
PythonRef PythonEnv::callFunction(const std::string& module_name, const std::string& func_name, Arg1Type arg1)
{
    loadModule(module_name);
    PyObject* func = createCallableObject(module_name, func_name);
    PyObject* args = PyTuple_New(1);
    PyTuple_SetItem(args, 0, createArgObject(arg1));
    return processFunctionCall(func, args);
}

template<typename Arg1Type, typename Arg2Type>
PythonRef PythonEnv::callFunction(const std::string& module_name, const std::string& func_name, Arg1Type arg1, Arg2Type arg2)
{
    constexpr int arg_count = 2;

    loadModule(module_name);
    PyObject* func = createCallableObject(module_name, func_name);
    PyObject* args = PyTuple_New(arg_count);
    PyObject* arg_vals[arg_count] = {
        createArgObject(arg1),
        createArgObject(arg2)
    };
    for (int i = 0; i < arg_count; i++)
        PyTuple_SetItem(args, i, arg_vals[i]);
    return processFunctionCall(func, args);
}

template<typename Arg1Type, typename Arg2Type, typename Arg3Type>
PythonRef PythonEnv::callFunction(const std::string& module_name, const std::string& func_name, Arg1Type arg1, Arg2Type arg2, Arg3Type arg3)
{
    constexpr int arg_count = 3;

    loadModule(module_name);
    PyObject* func = createCallableObject(module_name, func_name);
    PyObject* args = PyTuple_New(arg_count);
    PyObject* arg_vals[arg_count] = {
        createArgObject(arg1),
        createArgObject(arg2),
        createArgObject(arg3)
    };
    for (int i = 0; i < arg_count; i++)
        PyTuple_SetItem(args, i, arg_vals[i]);
    return processFunctionCall(func, args);
}
