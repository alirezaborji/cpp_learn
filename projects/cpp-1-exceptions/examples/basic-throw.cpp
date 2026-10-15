#include <iostream>
#include <ostream>

void myTest()
{
    bool success = false;
    if (!success)
    {
        throw 10;
    }
}

int main()
{
    try
    {
        myTest();
    }catch (int e)
    {
        std::cout << e << std::endl;
    }

    return 0;
}