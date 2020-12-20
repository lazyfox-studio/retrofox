#include "api-service/pythonref.h"

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
char PythonRef::cast()
{
    char value = static_cast<char>(PyLong_AsLong(p_ref));
    return value;
}

template<>
short PythonRef::cast()
{
    short value = static_cast<short>(PyLong_AsLong(p_ref));
    return value;
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

template<>
long long PythonRef::cast()
{
    long long value = PyLong_AsLongLong(p_ref);
    return value;
}

template<>
unsigned char PythonRef::cast()
{
    unsigned char value = static_cast<unsigned char>(PyLong_AsUnsignedLong(p_ref));
    return value;
}

template<>
unsigned short PythonRef::cast()
{
    unsigned short value = static_cast<unsigned short>(PyLong_AsUnsignedLong(p_ref));
    return value;
}

template<>
unsigned int PythonRef::cast()
{
    unsigned int value = static_cast<unsigned int>(PyLong_AsUnsignedLong(p_ref));
    return value;
}

template<>
unsigned long PythonRef::cast()
{
    unsigned long value = PyLong_AsUnsignedLong(p_ref);
    return value;
}

template<>
unsigned long long PythonRef::cast()
{
    unsigned long long value = PyLong_AsUnsignedLongLong(p_ref);
    return value;
}

template<>
float PythonRef::cast()
{
    float value = static_cast<float>(PyFloat_AsDouble(p_ref));
    return value;
}

template<>
double PythonRef::cast()
{
    double value = PyFloat_AsDouble(p_ref);
    return value;
}