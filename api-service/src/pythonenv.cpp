#include "pythonenv.h"

PythonEnv::PythonEnv()
    : c_modules_paths{"./../../api-service/scripts", "./../api-service/scripts"}
{
    Py_Initialize();
    PyObject* sys_module = PyImport_ImportModule("sys");
    PyObject* main_module = PyImport_AddModule("__main__");
    PyObject_SetAttrString(main_module, "sys", sys_module);
    Py_XDECREF(sys_module);
    std::string init_code;
    for (const std::string& path : c_modules_paths)
        init_code += "sys.path.append('" + path + "')\n";
    PyRun_SimpleString(init_code.c_str());
}

PyObject* PythonEnv::createCallableObject(const std::string& module_name, const std::string& func_name)
{
    PyObject* module = m_modules[module_name];
    PyObject* func = PyObject_GetAttrString(module, const_cast<char*>(func_name.c_str()));
    if (func && PyCallable_Check(func))
    {
        return func;
    }
    else
    {
        if (PyErr_Occurred())
            PyErr_Print();
        Py_XDECREF(func);
        throw std::runtime_error("Cannot find function");
    }
}

template<>
PyObject* PythonEnv::createArgObject(int arg)
{
    return PyLong_FromLong(arg);
}

template<>
PyObject* PythonEnv::createArgObject(long arg)
{
    return PyLong_FromLong(arg);
}

template<>
PyObject* PythonEnv::createArgObject(const char* arg)
{
    return Py_BuildValue("s", arg);
}

template<>
PyObject* PythonEnv::createArgObject(std::string arg)
{
    return Py_BuildValue("s", arg.c_str());
}

template<>
PyObject* PythonEnv::createArgObject(const std::string& arg)
{
    return Py_BuildValue("s", arg.c_str());
}

PythonRef PythonEnv::processFunctionCall(PyObject* func, PyObject* args)
{
    PyObject* ret_value = PyObject_CallObject(func, args);
    Py_DECREF(args);
    Py_XDECREF(func);
    if (ret_value != nullptr)
        return PythonRef(ret_value);
    else
    {
        PyErr_Print();
        throw std::runtime_error("Function call failed");
    }
}

PythonEnv::~PythonEnv()
{
    for (auto& pair : m_modules)
        Py_DECREF(pair.second);
    #ifdef _WIN64
    Py_FinalizeEx();
    #endif
    #ifdef linux
    Py_Finalize();
    #endif
}

bool PythonEnv::loadModule(const std::string& module_name)
{
    if (m_modules.find(module_name) != m_modules.end())
        return true;
    PyObject* module = PyImport_ImportModule(module_name.c_str());
    if (module != nullptr)
    {
        m_modules[module_name] = module;
        return true;
    }
    PyErr_Print();
    return false;
}

PythonRef PythonEnv::callFunction(const std::string& module_name, const std::string& func_name)
{
    loadModule(module_name);
    PyObject* func = createCallableObject(module_name, func_name);
    PyObject* ret_value = PyObject_CallObject(func, nullptr);
    Py_XDECREF(func);
    if (ret_value != nullptr) 
        return PythonRef(ret_value);
    else 
    {
        PyErr_Print();
        throw std::runtime_error("Function call failed");
    }
}

PythonEnv& PythonEnv::instance()
{
    static PythonEnv inst;
    return inst;
}
