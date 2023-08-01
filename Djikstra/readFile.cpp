#include "Header.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool readFile(string file, vector<vertex>& matrix)
{
    vector <int> select;

    string str;
    ifstream Text;

    int chet = 0;

    Text.open(file);
    if (Text.is_open()) {
        while (!Text.eof())
        {
            str = "";
            vector<char> razd = { ',',' ',';','\n' };
            getline(Text, str);

            string text;

            int mass;

            int i;
            for (i = 0; i < str.size(); i++)
            {
                if (find(razd.begin(), razd.end(), str[i]) == razd.end())
                {
                    text = text + str[i];
                }
                else
                {
                    mass = stoi(text);
                    select.push_back(mass);
                    text.clear();

                }
            }

            if (text != "")
            {
                mass = stoi(text);
                select.push_back(mass);
                text.clear();
            }
            matrix.resize(chet+1);
            for (int i = 0; i < select.size(); i++)
            {
                if (select[i] < 0)
                    return false;
                if (i % 2 == 0)
                    matrix[chet].ver.push_back(select[i]);
                else {
                    if (select[i] < 0)
                        return false;
                    matrix[chet].dist.push_back(select[i]);
                }
            }
            select.clear();
            chet++;
        }
    }
    else {
        cout << "ERROR , Не могу открывать файл" << endl;
    }
    return true;
}