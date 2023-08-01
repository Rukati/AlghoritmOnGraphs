#include <iostream>
#include <vector>
#include <limits>

using namespace std;

#define INF numeric_limits<int>::max()

void printMatrix(const vector<vector<int>>& matrix)
{
    for (const auto& row : matrix) {
        for (const auto& value : row) {
            if (value == INF) {
                cout << "INF ";
            }
            else {
                if (value == -1)
                    cout << "- ";
                else {
                    cout << value << " ";
                }
            }
        }
        cout << endl;
    }
}
