#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <clocale>

using namespace std;

struct graph
{
	int start;
	int end;
	int len;
	int flag;
};

bool compare(graph a, graph b)
{
	return a.len < b.len;
}

int main()
{
	setlocale(LC_ALL, "ru");
	clock_t start = clock();

	vector <vector<int>>top_weight;
	vector <int>weight;

	vector<vector <int>>matrix;
	vector <int> row;
	vector <int> select;

	string str;
	ifstream file;
	string text = "text.csv";
	file.open(text);

	int k = 0;
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
			top_weight.push_back(weight);

			int i;
			bool flag = false;
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

			for (int i = 0; i < select.size(); i++)
			{
				matrix[chet].push_back(select[i]);
				if (i % 2 == 0)
				{
					k++;
				}
			}
			select.clear();
			chet++;
		}
	}
	else {
		cout << "ERROR , Не могу открывать файл" << endl;
	}
	file.close();
	//------------------------TIME------------------------
	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "Прочитал: " << seconds<<"s" << endl;
	//------------------------MAIN------------------------
	vector<graph>graphs(k);
	vector<int>use;

	int N = 0;
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			if (j % 2 == 0)
			{
				graphs[N].start = i + 1;
				graphs[N].end = matrix[i][j];
				graphs[N].len = matrix[i][j + 1];
				++N;
			}
		}
		int m = 0;
	}

	sort(graphs.begin(), graphs.end(), compare);

	int weight_tree = 0;
	vector<bool>visit(matrix.size());
	vector<graph>tree;
	//------------------------TIME------------------------
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "Отсортировал: " << seconds << "s" << endl;
	//----------------------------------------------------
	for (int i = 0; i < k; i++)
	{
		if (!visit[graphs[i].start] && !visit[graphs[i].end])
		{
			weight_tree += graphs[i].len;
			visit[graphs[i].start] = true;
			visit[graphs[i].end] = true;
			tree.push_back(graphs[i]);
			graphs[i].flag = graphs[i].start;
		}
		else if ((!visit[graphs[i].start]) || (!visit[graphs[i].end]))
		{
			if (!visit[graphs[i].start])
			{
				weight_tree += graphs[i].len;
				visit[graphs[i].start] = true;
				tree.push_back(graphs[i]);
				for (graph k : graphs)
				{
					if ((k.end == graphs[i].end) || (k.end == graphs[i].start))
					{
						graphs[i].flag = k.flag;
						break;
					}
				}
			}
			else
			{
				weight_tree += graphs[i].len;
				visit[graphs[i].end] = true;
				tree.push_back(graphs[i]);
				for (graph k : graphs)
				{
					if ((k.start == graphs[i].start) || (k.end == graphs[i].start))
					{
						graphs[i].flag = k.flag;
						break;
					}
				}
			}
		}
		if (graphs[i].flag == 0)
		{
			graph A;
			graph B;
				for (graph k : graphs)
			{
				if (((k.start == graphs[i].start) || (k.start == graphs[i].end)) && (k.flag != 0))
				{
					A = k;
					break;
				}
			}
			for (graph k : graphs)
			{
				if (((k.end == graphs[i].start) || (k.end == graphs[i].end)) && (k.flag != 0))
				{
					B = k;
					break;
				}
			}
			if (A.flag != B.flag)
			{
				weight_tree += graphs[i].len;
				graphs[i].flag = B.flag;
				tree.push_back(graphs[i]);
					for (int j = 0; j < graphs.size(); j++)
					{
						if (((graphs[i].end == graphs[j].end) || (graphs[i].end == graphs[j].start)) && ((graphs[j].start != graphs[i].start) && (graphs[j].end != graphs[i].start)))
						{
							if (graphs[j].flag != 0) 
							{
								graphs[j].flag = graphs[i].flag;
							}
						}
						if (((graphs[j].start == graphs[i].start) || (graphs[j].end == graphs[i].end)) && (graphs[j].flag != 0))
						{
							graphs[j].flag = graphs[i].flag;
						}
					}
				}
			}
		if (tree.size() == (matrix.size() - 1)) break;
	}

	ofstream out;
	out.open("kraskal.csv");

	if (out.is_open()) {
		for (graph k : tree)
		{
			out << k.start << ":" << k.len << ":" << k.end << endl;
		}
	}
	
	cout << "Вес: " << weight_tree << endl;
	//------------------------TIME------------------------
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "Выполнил программу: " << seconds << "s" << endl;
}