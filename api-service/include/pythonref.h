#pragma once

#include <Python.h>

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
};
