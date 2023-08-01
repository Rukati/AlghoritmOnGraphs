#include <stack>
#include <queue>
#include <vector>
#include <fstream>
#include <iostream>
#include <conio.h>
#include <string>
#include <numeric>
#include <stdlib.h>
#include <ctime>


using namespace std;


int main()
{
	clock_t start = clock();

	vector<vector <int>>matrix;
	vector <int> row;
	vector <int> select;
	string str;
	ifstream file;
	string text = "input_graph (1).csv";
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
					if (text != "")
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
	}
	file.close();

	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	vector<int>BFS;
	vector<int>DFS;

	//инициализация стека
	queue <int> q;
	stack <int> s;

	// список непосещенных вершины ( select )
	select.resize(matrix.size() - 1);
	iota(select.begin(), select.end(), 1);
	// 

	// рандом первой вершины
	srand(time(NULL));
	int v = 1;
	if (find(select.begin(), select.end(), v) != select.end())
	{
		// удаление её из select'a
		select.erase(find(select.begin(), select.end(), v));
	}

	q.push(v);
	BFS.push_back(v);

	// ------------------------BFS------------------------\\

	for (; select.size() != 0; )
	{
		if (q.empty())
		{
			v = select[rand() % select.size()];
			if (find(select.begin(), select.end(), v) != select.end())
			{
				select.erase(find(select.begin(), select.end(), v));
			}
			q.push(v);
		}
		v = q.front();
		q.pop();
		for (int i = 0; i < matrix[v - 1].size(); i++)
		{

			if (find(select.begin(), select.end(), matrix[v - 1][i]) != select.end())
			{
				select.erase(find(select.begin(), select.end(), matrix[v - 1][i]));
				BFS.push_back(matrix[v - 1][i]);
				q.push(matrix[v - 1][i]);
			}
		}
	}
	//------------------------/BFS\------------------------\\


	// список непосещенных вершины ( select )
	select.clear();
	select.resize(matrix.size() - 1);
	iota(select.begin(), select.end(), 1);
	// 

	v = 1;
	if (find(select.begin(), select.end(), v) != select.end())
	{
		// удаление её из select'a
		select.erase(find(select.begin(), select.end(), v));
	}
	s.push(v);

	// ------------------------DFS------------------------\\

	for (; select.size() != 0; )
	{
		if (s.empty())
		{
			v = select[rand() % select.size()];
			if (find(select.begin(), select.end(), v) != select.end())
			{
				select.erase(find(select.begin(), select.end(), v));
				s.push(v);
			}

		}
		v = s.top();
		s.pop();
		for (int i = 0; i < matrix[v - 1].size(); i++)
		{

			if (find(select.begin(), select.end(), matrix[v - 1][i]) != select.end())
			{
				select.erase(find(select.begin(), select.end(), matrix[v - 1][i]));
				s.push(matrix[v - 1][i]);
			}
		}
		DFS.push_back(v);

	}

	while(s.size()>0) {

		DFS.push_back(s.top());
		s.pop();
	}

	// ------------------------/DFS\------------------------\\

	cout << "BFS" << endl;
	for (int i = 0; i < BFS.size(); i++)
	{
		cout << BFS[i] << " ";
	}

	cout << endl << '\n';

	cout << "DFS" << endl;
	for (int i = 0; i < DFS.size(); i++)
	{
		cout << DFS[i]-1 << " ";
	}


	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;

	cout << endl;
	cout << endl;
	cout << "The time: %f seconds:" << seconds;
}