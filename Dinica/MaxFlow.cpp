#include "Header.h"

#include <iostream>
#include <string>
#include <fstream>
#include <clocale>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

#include <ctime>

using namespace std;

int vert = 10000; //âåðøèíû
int conn = 10; //ñâÿçè
int dist = 10; //âåñ

class Graph
{
public:
	vector<int>vertex;
	vector<int>dist;
};

float min(float a, float b)
{
	if (a > b)
		return b;
	else
		return a;

}

void print(vector<Graph>graph)
{
	for (int i = 0; i < graph.size(); i++)
	{
		cout << "[" << i + 1 << "] ";
		for (int j = 0; j < graph[i].vertex.size(); j++)
			cout << graph[i].vertex[j] << "{" << graph[i].dist[j] << "}" << " ";
		if (i + 1 == graph.size())break;
		cout << endl;
	}
}

bool dfs(int u, vector<Graph>& graph, vector<bool>& visit, vector<int>& path)
{

	int v = u - 1;
	visit[v] = true;
	path.push_back(u);
	if (u == vert) {
		return true;
	}
	int i = 0;
	for (int to : graph[v].vertex)
	{
		if (!visit[to - 1] && graph[v].dist[i] > 0)
		{
			if (dfs(to, graph, visit, path)) {
				return true;
			}
		}
		i++;
	}
	path.pop_back();
	return false;
}

void bfs(vector<Graph>& graph, vector<bool>& visit)
{
	vector<int>top;
	int v = 1;
	queue<int>q;
	q.push(v);
	visit[v] = true;
	while (!q.empty()) {
		int to = q.front();
		top.push_back(to);
		if (to == vert)
		{
			visit[vert] = true;
			break;
		}
		q.pop();
		for (int i = 0; i < graph[to - 1].vertex.size(); i++) {
			if (!visit[graph[to - 1].vertex[i]] && (graph[to - 1].dist[i] > 0)) {
				visit[graph[to - 1].vertex[i]] = true;
				q.push(graph[to - 1].vertex[i]);
			}
		}
	}
}

void printPath(vector<int>& path)
{
	cout << " DFS: ";
	for (int i : path)
		cout << i << " ";
}

vector<Graph> read_file(string file)
{

	vector <Graph> graphs(vert);
	vector <int> select;

	string str;
	ifstream Text;

	int chet = 0;

	Text.open(file);
	if (Text.is_open()) {
		while (!Text.eof())
		{
			str = "";
			vector<char> razd = { ',',' ','-',';','\n' };
			getline(Text, str);

			string text;

			int mass;

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

				if (i % 2 == 0)
					graphs[chet].vertex.push_back(select[i] + 1);
				else
					graphs[chet].dist.push_back(select[i]);
			}
			select.clear();
			chet++;
		}
	}
	else {
		cout << "ERROR , Íå ìîãó îòêðûâàòü ôàéë" << endl;
	}
	return graphs;
}

int main()
{
	clock_t start = clock();

	setlocale(LC_ALL, "ru");

	string out_file = "textGenerator.txt";
	//Generator(vert, conn, dist, out_file);

	string file = "input_transport_network.csv";
	vector<Graph> graph = read_file(file);

	//print(graph);
	//cout << endl;
	vector<int>path;

	int maxflow = 0;

	while (true)
	{
		float value = INFINITY;
		vector<bool>visitBFS(graph.size() + 1, false);
		bfs(graph, visitBFS);

		if (!visitBFS[vert])
		{
			cout << " Ïóòè äî ñòîêà íåò, ïîòîê ìàêñèìàëüíûé: ";
			cout << maxflow;
			break;//Åñëè ïóòè äî ñòîêà íåò, ïîòîê ìàêñèìàëüíûé
		}
		vector<bool> visitDFS(graph.size() + 1, false);

		if (dfs(1, graph, visitDFS, path)) 
		{
			//printPath(path);
			vector<bool>flag(graph.size() + 1, false);
			for (int k : path)
			{
				k -= 1;
				for (int i = 1; i < path.size(); i++)
				{
					auto it = find(graph[k].vertex.begin(), graph[k].vertex.end(), path[i]);
					if (it != graph[k].vertex.end())
					{
						if (!flag[graph[k].vertex[it - graph[k].vertex.begin()]])
						{
							//cout << graph[k].dist[it - graph[k].vertex.begin()] << " ";
							value = min(value, graph[k].dist[it - graph[k].vertex.begin()]);
							flag[graph[k].vertex[it - graph[k].vertex.begin()]] = true;
							break;
						}
					}
				}
			}

			flag.clear();
			flag.resize(graph.size() + 1, false);
			for (int k : path)
			{
				k -= 1;
				for (int i = 1; i < path.size(); i++)
				{
					auto it = find(graph[k].vertex.begin(), graph[k].vertex.end(), path[i]);
					if (it != graph[k].vertex.end())
					{
						if (!flag[graph[k].vertex[it - graph[k].vertex.begin()]])
						{
							graph[k].dist[it - graph[k].vertex.begin()] -= value;
							//cout << graph[k].dist[it - graph[k].vertex.begin()] << " ";
							flag[graph[k].vertex[it - graph[k].vertex.begin()]] = true;
							break;
						}
					}
				}
			}
			path.clear();
			maxflow += value;
		}
	}

	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "\n The time:\n seconds:" << seconds;

}
