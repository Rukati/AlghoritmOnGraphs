/*
 _   _   _____   _____            __    _____   __
| | | | /  __ \ | ___ \          /  |  / __  \ /  |
| | | | | /  \/ | |_/ /  ______  `| | ` ' / /' `| |
| | | | | |     | ___ \ |______|  | |    / /    | |
| |_| | | \__ /\| |_/ /          _| |_ ./ /___ _| |_
 \___/   \____/ \____/           \___/ \_____/ \___/
					 ReadMatrix.cpp
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

vector <vector<int>> ReadMatrix(string namefile, vector<vector<int>>& zeroMatrix)
{

	vector <vector<int>> matrix;
	vector<int>row;
	vector <int> select;
    vector<int>zero;

	string str;
	ifstream file;

	int chet = 0;

	file.open(namefile);
	if (file.is_open()) {
		while (!file.eof())
		{
			str = "";
			vector<char> razd = { ',',' ','-',';','\n' };
			getline(file, str);

			string text;

			int mass;
			matrix.push_back(row);
            zeroMatrix.push_back(zero);

			for (int i = 0; i < str.size(); i++)
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

			for (int i = 0; i < select.size(); i++)
			{
				matrix[chet].push_back(select[i]);
                zeroMatrix[chet].push_back(0);
			}
			select.clear();
			chet++;
		}
	}
	else {
		cout << "ERROR" << endl;
	}
	file.close();
	//
	return matrix;
}