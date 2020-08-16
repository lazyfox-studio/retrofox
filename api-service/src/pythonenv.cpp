#include "pythonenv.h"

PythonEnv::PythonEnv()
{
    Py_Initialize();
    PyObject* sys_module = PyImport_ImportModule("sys");
    PyObject* main_module = PyImport_AddModule("__main__");
    PyObject_SetAttrString(main_module, "sys", sys_module);
    Py_XDECREF(sys_module);
    PyRun_SimpleString("sys.path.append('./../../api-service/scripts')\n");
}

PythonEnv::~PythonEnv()
{
    for (auto& pair : m_modules)
        Py_DECREF(pair.second);
    Py_FinalizeEx();
}

bool PythonEnv::loadModule(const std::string& module_name)
{
    std::string py_path = c_modules_path + module_name;
    if (m_modules.find(module_name) != m_modules.end())
        return true;
    PyObject* module = PyImport_ImportModule(py_path.c_str());
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
    PyObject* module = m_modules[module_name];
    PyObject* func = PyObject_GetAttrString(module, const_cast<char*>(func_name.c_str()));
    if (func && PyCallable_Check(func)) 
    {
        PyObject* ret_value = PyObject_CallObject(func, nullptr);
        if (ret_value != nullptr) 
        {
            Py_XDECREF(func);
            return PythonRef(ret_value);
        }
        else 
        {
            Py_DECREF(func);
            PyErr_Print();
            throw std::exception("Function call failed");
        }
    }
    else 
    {
        if (PyErr_Occurred())
            PyErr_Print();
        Py_XDECREF(func);
        throw std::exception("Cannot find function");
    }
}


PythonEnv& PythonEnv::instance()
{
    static PythonEnv inst;
    return inst;
}
