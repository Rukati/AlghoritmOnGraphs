/*
 _   _   _____   _____            __    _____   __
| | | | /  __ \ | ___ \          /  |  / __  \ /  |
| | | | | /  \/ | |_/ /  ______  `| | ` ' / /' `| |
| | | | | |     | ___ \ |______|  | |    / /    | |
| |_| | | \__ /\| |_/ /          _| |_ ./ /___ _| |_
 \___/   \____/ \____/           \___/ \_____/ \___/
					    Header.h
*/
#pragma once

#include <vector>
#include <iostream>

using namespace std;

void GenGraph(int num_vertices_left, int num_vertices_right, int max_weight);
vector <vector<int>> ReadMatrix(string namefile, vector<vector<int>>& zeroMatrix);
void PrintMatrix(vector<vector<int>>& matrix);