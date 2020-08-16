#pragma once

#include <Python.h>

class PythonRef
{
protected:
    friend class PythonEnv;

    PyObject* p_ref;

    PythonRef(PyObject* ref);
public:
    PythonRef() = delete;
    PythonRef(const PythonRef&) = delete;
    PythonRef(PythonRef&& other);
    ~PythonRef();

    PythonRef& operator=(const PythonRef&) = delete;
    PythonRef& operator=(PythonRef&& other);

    template<typename RType>
    RType cast();
};
