#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <string>
#include <map>

#include "pythonref.h"

class PythonEnv
{
protected:
    const std::string c_modules_path;
    std::map<std::string, PyObject*> m_modules;

    PythonEnv();
public:
    ~PythonEnv();

    bool loadModule(const std::string& module_name);

    PythonRef callFunction(const std::string& module_name, const std::string& func_name);
    PythonRef callFunction(const std::string& module_name, const std::string& func_name, long int_arg);
    PythonRef callFunction(const std::string& module_name, const std::string& func_name, const std::string& str_arg);

    static PythonEnv& instance();
};
