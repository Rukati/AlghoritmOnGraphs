/*
 _   _   _____   _____            __    _____   __
| | | | /  __ \ | ___ \          /  |  / __  \ /  |
| | | | | /  \/ | |_/ /  ______  `| | ` ' / /' `| |
| | | | | |     | ___ \ |______|  | |    / /    | |
| |_| | | \__ /\| |_/ /          _| |_ ./ /___ _| |_
 \___/   \____/ \____/           \___/ \_____/ \___/
					 PrintMatrix.cpp
*/
#include "Header.h"

#include <iostream>

void PrintMatrix(vector<vector<int>>& matrix)
{
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
			cout << matrix[i][j] << " ";
		if (i + 1 < matrix.size())
			cout << endl;
	}
}