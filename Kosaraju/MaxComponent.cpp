#include <stack>
#include <vector>
#include <fstream>
#include <iostream>
#include <conio.h>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

vector<vector <int>>matrix;
stack<int>s;

void dfs(int v, vector<bool>& visited) {
	visited[v] = true;
	for (int i = 0; i < matrix[v].size(); i++) {
		int next_v = matrix[v][i];
		if (!visited[next_v - 1]) {
			dfs(next_v - 1, visited);
		}
	}
	s.push(v);
}

void reverse_dfs(int v, vector<vector<int>>& revers_matrix, vector<bool>& visited, vector<int>& component) {
	visited[v] = true;
	component.push_back(v);

	for (int i = 0; i < revers_matrix[v].size(); i++) {
		int next_v = revers_matrix[v][i];
		if (!visited[next_v - 1]) {
			reverse_dfs(next_v - 1, revers_matrix, visited, component);
		}
	}
}

vector<vector <int>>kasaraju(vector<vector<int>>& matrix_revers)
{
	vector<vector<int>> components;
	vector<bool>visited(matrix.size(), false);

	for (int i = 0; i < matrix.size(); i++)
	{
		if (!visited[i])
			dfs(i, visited);
	}

	for (int i = 0; i < matrix.size(); i++) {
		visited[i] = false;
	}

	while (!s.empty()) {
		int v = s.top();
		s.pop();
		if (!visited[v]) {
			vector<int> component;
			reverse_dfs(v, matrix_revers, visited, component);
			components.push_back(component);
		}
	}
	return components;
}

int main()
{
	clock_t start = clock();
	vector <int> row;
	vector <int> select;
	string str;
	ifstream file;

	string text = "tetrad2.txt";

	file.open(text);
	int chet = 0;
	if (file.is_open()) {

		while (!file.eof())
		{
			str = "";
			vector<char> razd = { ',',' ','-',';','\n' };

			getline(file, str);
			string text;

			int mass;
			matrix.push_back(row);
			int i;
			for (i = 0; i < str.size(); i++)
			{
				if (find(razd.begin(), razd.end(), str[i]) == razd.end())
				{
					text = text + str[i];
				}
				else
				{
					if (text != " ")
					{
						mass = stoi(text);
						select.push_back(mass);
						text.clear();
					}
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
			}
			select.clear();
			chet++;
		}
	}
	else {
		cout << "NO";
		return 0;
	}
	file.close();

	//перевернул дуги 
	vector < vector<int >> matrix_revers(matrix.size());
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			matrix_revers[matrix[i][j] - 1].push_back(i + 1);
		}
	}


	for (int i = 0; i < matrix.size(); i++)
	{
		cout << i+1 << " ----";
		for (int j = 0; j < matrix_revers[i].size(); j++)
		{
			cout << matrix_revers[i][j] << " ";
		}
		cout << endl;
	}
	

	vector<vector<int>> components = kasaraju(matrix_revers);

	for (int i = 0; i < components.size(); i++) {
		cout << i + 1 << ": ";
		for (int j = 0; j < components[i].size(); j++)
		{
			cout << components[i][j] + 1 << " ";
		}
		cout << endl;
	}
}