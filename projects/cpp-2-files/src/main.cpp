#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

#pragma pack(push, 1)
struct School
{
    int amountOfChildrens;
    int amountOfClasses;
    int amountOfTeachers;
    char headQuarterName[50];
};
#pragma pack(pop)

int main()
{
    const std::string filename = "meFile.bin";

    std::fstream outStream(filename, std::ios::binary|std::ios::out); // this

    School school = {.amountOfChildrens = 10, .amountOfClasses = 3, .amountOfTeachers = 5, .headQuarterName = "Khanoom Vaziri"};

    outStream.write(reinterpret_cast<char *>(&school), sizeof(school));

    outStream.close();



    school = {.amountOfChildrens = 0,.amountOfClasses = 0,.amountOfTeachers = 0,.headQuarterName = "NONE"};



    std::fstream inStream(filename, std::ios::binary|std::ios::in); // this

    inStream.read(reinterpret_cast<char *>(&school), sizeof(school));

    std::cout << school.amountOfChildrens << " :: " <<
                 school.amountOfClasses << " :: " <<
                 school.amountOfTeachers << " :: " <<
                 school.headQuarterName <<
                 std::endl;

    return 0;
}
