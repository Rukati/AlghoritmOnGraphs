#include "Header.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void Generator(int row, int column, int max_weight, string name)
{
	vector<vector<int>>Matrix(row);
	vector <vector <int>> weight_list(row);
	vector<int>select(row);
	iota(select.begin(), select.end(), 1);

	{
		srand(time(NULL));
		for (int i = 0; i < row; i++) {

			int RandomColumn = 1 + rand() % column;
			for (int j = 0; j < RandomColumn; j++) {

				int random_pos;
				do
				{
					random_pos = rand() % select.size();
				} while (select[random_pos] == i + 1);

				if (find(Matrix[select[random_pos]-1].begin(), Matrix[select[random_pos]-1].end(), i+1) == Matrix[select[random_pos] - 1].end())
				{
					Matrix[i].push_back(select[random_pos]);
					int dist = rand() % (max_weight)+1;
					weight_list[i].push_back(dist);
					select.erase(select.begin() + random_pos);
				}
			}
			select.clear();
			select.resize(row);
			iota(select.begin(), select.end(), 1);
		}
		ofstream out;
		out.open(name);

		if (out.is_open()) {
			for (int i = 0; i < Matrix.size(); i++) {

				for (int j = 0; j < Matrix[i].size(); j++) {
					if (out.is_open()) {
						if (j + 1 == Matrix[i].size())
						{
							out << Matrix[i][j] << ";" << weight_list[i][j];
						}
						else
						{
							out << Matrix[i][j] << ";" << weight_list[i][j] << ";";
						}
					}
				}
				if (i + 1 != Matrix.size())
				out << endl;
			}
		}
	}
}