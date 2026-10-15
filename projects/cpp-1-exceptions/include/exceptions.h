//
// Created by jonas on 10/1/26.
//

#ifndef CPP_LEARN_EXCEPTIONS_H
#define CPP_LEARN_EXCEPTIONS_H

#include <exception>

// A custom exception type. It can be caught as myExceptions or std::exception.
class myExceptions : public std::exception
{
public:
    // Return the standard readable message for this exception.
    const char* what() const noexcept override;

    // Extra detail for handlers that catch this custom exception type.
    virtual const char* when() const noexcept;
};

// Example library class with a function that can report failure by throwing.
class TestClass
{
public:
    // Static: call as TestClass::sthWrong(); no TestClass object is needed.
    static void sthWrong();
};

#endif //CPP_LEARN_EXCEPTIONS_H
