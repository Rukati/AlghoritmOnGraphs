#pragma once
#include <vector>
#include <string>
#include <iostream>

#define INF INFINITY

using namespace std;

void Graph(int row, int column, int max_weight, string name);
bool Read(string file, vector<vector<int>>& matrix);
vector<vector<int>> createMatrix(vector<vector<int>>& graph);
void printMatrix(const vector<vector<int>>& matrix);