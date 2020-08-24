#include "pythonenv.h"

PythonEnv::PythonEnv()
    : c_modules_path("./../../api-service/scripts")
{
    Py_Initialize();
    PyObject* sys_module = PyImport_ImportModule("sys");
    PyObject* main_module = PyImport_AddModule("__main__");
    PyObject_SetAttrString(main_module, "sys", sys_module);
    Py_XDECREF(sys_module);
    std::string init_code = "sys.path.append('" + c_modules_path + "')\n";
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

PythonRef PythonEnv::callFunction(const std::string& module_name, const std::string& func_name, long int_arg)
{
    loadModule(module_name);
    PyObject* func = createCallableObject(module_name, func_name);
    PyObject* args = PyTuple_New(1);
    PyObject* int_val = PyLong_FromLong(int_arg);
    PyTuple_SetItem(args, 0, int_val);
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

PythonRef PythonEnv::callFunction(const std::string& module_name, const std::string& func_name, const std::string& str_arg)
{
    loadModule(module_name);
    PyObject* func = createCallableObject(module_name, func_name);
    PyObject* args = PyTuple_New(1);
    PyObject* str_val = Py_BuildValue("s", str_arg.c_str());
    PyTuple_SetItem(args, 0, str_val);
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

PythonRef PythonEnv::callFunction(const std::string& module_name, const std::string& func_name, const std::string& arg1, long arg2, const std::string& arg3)
{
    loadModule(module_name);
    PyObject* func = createCallableObject(module_name, func_name);
    constexpr int arg_count = 3;
    PyObject* args = PyTuple_New(arg_count);
    PyObject* arg_vals[arg_count] = {
        Py_BuildValue("s", arg1.c_str()),
        PyLong_FromLong(arg2),
        Py_BuildValue("s", arg3.c_str())
    };
    for (int i = 0; i < arg_count; i++)
        PyTuple_SetItem(args, i, arg_vals[i]);
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

PythonEnv& PythonEnv::instance()
{
    static PythonEnv inst;
    return inst;
}
