#include "pythonref.h"

PythonRef::PythonRef(PyObject* ref)
    : p_ref(ref)
{
}

PythonRef::PythonRef(PythonRef&& other)
    : p_ref(other.p_ref)
{
    other.p_ref = nullptr;
}

PythonRef::~PythonRef()
{
    if (p_ref != nullptr)
        Py_DECREF(p_ref);
}

PythonRef& PythonRef::operator=(PythonRef&& other)
{
    p_ref = other.p_ref;
    other.p_ref = nullptr;
    return *this;
}

template<>
int PythonRef::cast()
{
    int value = static_cast<int>(PyLong_AsLong(p_ref));
    return value;
}

template<>
long PythonRef::cast()
{
    long value = PyLong_AsLong(p_ref);
    return value;
}
