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
        cout << "Ошибка: Не удалось открыть файл" << endl;
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
                cout << "Ошибка: Неверный формат числа в файле" << endl;
                return false;
            }
        }

        if (row.size() % 2 != 0) {
            cout << "Ошибка: Неверное количество чисел в строке файла" << endl;
            return false;
        }

        matrix.push_back(row);
    }
    return true;
}