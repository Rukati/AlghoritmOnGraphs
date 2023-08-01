/*
 _   _   _____   _____            __    _____   __
| | | | /  __ \ | ___ \          /  |  / __  \ /  |
| | | | | /  \/ | |_/ /  ______  `| | ` ' / /' `| |
| | | | | |     | ___ \ |______|  | |    / /    | |
| |_| | | \__ /\| |_/ /          _| |_ ./ /___ _| |_
 \___/   \____/ \____/           \___/ \_____/ \___/
					  GenGraph.cpp
*/
#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>

using namespace std;

void GenGraph(int num_vertices_left, int num_vertices_right,int max_weight)
{
    clock_t start = clock();
    clock_t end;
    double seconds;
	//
	//
	//	generator -> graph
	vector<vector<int>>graph;
	vector<int>vertex;
	srand(time(NULL));
	for (int i = 0; i < num_vertices_left; i++)
	{
		graph.push_back(vertex);
		int l = 0;
		graph[i].resize(num_vertices_left + num_vertices_right);
		for (int j = num_vertices_left; j < (num_vertices_left + num_vertices_right); j++)
		{
			graph[i][l] = 1 + rand() % max_weight;
			l++;
		}
		graph[i].erase(graph[i].end() - num_vertices_left, graph[i].end());
	}
	//
	//	
	//	out <- graph
	ofstream out;
	out.open("graph.txt");
	for (int i = 0; i < graph.size(); i++)
	{
		int l = 0;
		for (int j = num_vertices_left; j < (num_vertices_left + num_vertices_right); j++) {
			out << i << " " << j << " " << graph[i][l];
            out << endl;
			l++;
		}
	}
	out.close();
	//
	//
	//	graph -> matrix
	vector<vector<int>> matrix;
	vector<int>row;
	for (int i = 0; i < graph.size(); i++)
	{
		int l = 0;
		matrix.push_back(row);
		for (int j = num_vertices_left; j < (num_vertices_left + num_vertices_right); j++) {
			matrix[i].push_back(graph[i][l]);
			l++;
		}
	}
	//
	//
	//	out <- matrix
	out.open("matrix.txt");
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++) {
			out << matrix[i][j] << " ";
		}
        if (i + 1 < matrix.size())
            out << endl;
	}
	out.close();
    end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "The matrix has generation successfully\tThe time: " << seconds << "s\n";
	//
	//
	//
}