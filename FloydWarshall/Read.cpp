#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <limits>

using namespace std;
#define INF INFINITY

bool Read(string file, vector<vector<int>>& matrix)
{
    ifstream infile(file);
    if (!infile) {
        cout << "������: �� ������� ������� ����" << endl;
        return false;
    }

    string line;
    while (getline(infile, line)) {
        istringstream iss(line);
        string token;
        vector<int> row;

        while (getline(iss, token, ';')) {
            try {
                int value = stoi(token);
                row.push_back(value);
            }
            catch (const exception&) {
                cout << "������: �������� ������ ����� � �����" << endl;
                return false;
            }
        }

        if (row.size() % 2 != 0) {
            cout << "������: �������� ���������� ����� � ������ �����" << endl;
            return false;
        }

        matrix.push_back(row);
    }
    return true;
}