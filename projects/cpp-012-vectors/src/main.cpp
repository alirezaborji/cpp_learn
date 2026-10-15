#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> meVector;

    meVector.push_back("Hi");
    meVector.push_back("Hi again");
    meVector.push_back("baby");
    cout << meVector[1] << endl;

    vector<int> it = {1, 2, 3};

    auto i = it.begin();

    cout << *i++ << endl;
    cout << *i++ << endl;
    cout << *i++ << endl;

    //###################
    //###################
    //###################

    std::vector<int> numbers;

    numbers.reserve(5);
    std::cout << numbers.size() << '\n';
    std::cout << numbers.capacity() << '\n';

    numbers.push_back(10);
    numbers.push_back(20);

    std::cout << numbers.size() << '\n';
    std::cout << numbers.capacity() << '\n';

    numbers.clear();

    std::cout << numbers.size() << '\n';
    std::cout << numbers.capacity() << '\n';

    return 0;
}