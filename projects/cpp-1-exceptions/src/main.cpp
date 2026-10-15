#include <iostream>
#include <ostream>
#include "exceptions.h"


int main()
{
    try
    {
        TestClass::sthWrong();
    }
    // Catch this exception by reference so its type and details are preserved.
    catch (myExceptions& e)
    {
        // what() returns the standard message defined by myExceptions.
        std::cout << e.what() << std::endl;
    }

    return 0;
}
