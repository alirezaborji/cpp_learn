#include "exceptions.h"
//
// Created by jonas on 10/1/26.
//

const char* myExceptions::what() const noexcept
{
    return "Hi what()";
}

const char* myExceptions::when() const noexcept
{
    return "Hi when()";
}

void TestClass::sthWrong()
{
    // Signal failure; a caller can catch this exception and decide what to do.
    throw myExceptions();
}
