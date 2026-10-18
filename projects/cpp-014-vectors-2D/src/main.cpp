#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // task:
    // Try a theater seating map in cpp-014-vectors-2D/src/main.cpp.
    // Use a 2D vector of integers where 0 means an empty seat and 1 means occupied. Start with 3 rows and 4 seats per row; give the seats some values yourself.
    // Work through these steps:
    // 1. Use nested loops to print the map as rows and columns.
    // 2. Count how many seats are occupied in each row.
    // 3. Count the occupied seats in the whole theater.
    // 4. Stretch goal: let someone choose a row and seat, then report whether it’s occupied.
    // Start with hard-coded seat values so you can focus on the 2D vector and loops. Hint: the outer loop visits rows; the inner loop visits seats in that row. I’ll stick to hints if you share your attempt.

    // Theater saloon
    vector< vector<int> > theater(5, vector<int>(4, 0));

    theater[0][0] = 1;
    theater[1][1] = 1;
    theater[2][1] = 1;
    theater[2][2] = 1;
    theater[2][3] = 1;

    int rowCount = 0;
    int seatCount = 0;

    cout << "1:" << endl;

    for (int row = 0; row < theater.size(); row++)
    {
        for (int col = 0; col < theater[row].size(); col++)
        {
            cout << theater[row][col] << flush;
            if (theater[row][col] == 1)
            {
                seatCount++;
            }
            if (theater[row][col] == 1)
            {
                rowCount++;
            }
        }

        cout << "  2:" << rowCount << flush;
        rowCount = 0;
        cout << endl;
    }

    cout << "3:" << endl;
    cout << seatCount << endl;
    seatCount = 0;

    return 0;
}