#include <iostream>
#include <vector>
using namespace std;

int main()
{

    std::pmr::vector< std::pmr::vector<int> > meVector(3, std::pmr::vector<int> (4, 7));

    // meVector.resize(5);
    meVector[0][2]= 8;
    meVector[1][0]= 8;
    meVector[2][3]= 8;

    meVector[0].push_back(1);
    meVector[0].push_back(1);
    meVector[1].push_back(1);

    for (int row = 0; row < meVector.size(); row++)
    {
        for (int col = 0; col < meVector[row].size(); col++)
        {
            cout << meVector[row][col] << flush;
        }
        cout << endl;
    }

    return 0;
}