#pragma once

#include <Python.h>

#include <stdexcept>
#include <vector>

/**
 * @ingroup api-service
 * @brief Simple wrapper for py-reference
 * @details Class to represent py-reference and its typecasting
 */
class PythonRef
{
protected:
    friend class PythonEnv;

    /// Pointer to py-reference
    PyObject* p_ref;

    /**
     * @brief Typecast constructor
     * @param ref Pointer to py-reference to hold
     */
    PythonRef(PyObject* ref);

public:
    /// Default constructor is not provided
    PythonRef() = delete;

    /// Copy constructor is not provider
    PythonRef(const PythonRef&) = delete;

    /// Move constructor
    PythonRef(PythonRef&& other);

    /// Destructor
    ~PythonRef();

    /// Copy assignment operator is not provided
    PythonRef& operator=(const PythonRef&) = delete;

    /// Move assignment operator
    PythonRef& operator=(PythonRef&& other);

    /**
     * @brief Casts object (in py-reference) to preferred type (RType)
     * @details Supported types for RType:
     * @code{.txt}
     * char        unsigned char
     * short       unsigned short
     * int         unsigned int
     * long        unsigned long
     * long long   unsigned long long
     * float
     * double
     * @endcode
     * @return Value with RType type
     */
    template<typename RType>
    RType cast();

    /**
     * @brief Casts py-tuple to vector with elements of preferred type (RType)
     * @details Also converts list into tuple if needed, 
     * hence can be used both with lists and tuples.
     * Supported types for RType: see cast()
     * @return Vector of elements of RType type
     */
    template<typename RType>
    std::vector<RType> tuple();

    /**
     * @brief Casts py-list to vector with elements of preferred type (RType)
     * @details Supported types for RType: see cast()
     * @return Vector of elements of RType type
     */
    template<typename RType>
    std::vector<RType> list();
};

template<typename RType>
std::vector<RType> PythonRef::tuple()
{
    PyObject* ref = p_ref;
    if (!PyTuple_Check(ref))
    {
        if (PyList_Check(ref))
            ref = PyList_AsTuple(ref);
        else
            throw std::runtime_error("Ref is not a tuple object");
    }
    size_t size = PyTuple_Size(p_ref);
    std::vector<RType> tuple(0);
    tuple.reserve(size);
    for (size_t i = 0; i < size; i++)
        tuple.push_back(PythonRef(PyTuple_GetItem(p_ref, i)).cast<RType>());
    return tuple;
}

template<typename RType>
std::vector<RType> PythonRef::list()
{
    if (!PyList_Check(p_ref))
        throw std::runtime_error("Ref is not a list object");
    size_t size = PyList_Size(p_ref);
    std::vector<RType> list(0);
    list.reserve(size);
    for (size_t i = 0; i < size; i++)
        list.push_back(PythonRef(PyList_GetItem(p_ref, i)).cast<RType>());
    return list;
}
