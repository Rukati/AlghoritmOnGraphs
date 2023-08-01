#include "Header.h"

#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


void dijkstra(vector<vertex>& graph, int start_vertex, int end_vertex) {
    int n = graph.size();

    vector<int> distance(n, INFINITY);
    vector<int> previous(n, -1);
    vector<bool> visited(n, false);

    distance[start_vertex - 1] = 0;
    //
    // тип, контейнер, сортировка
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(distance[start_vertex - 1], start_vertex));

    while (!pq.empty()) {
        //  текущая
        int current = pq.top().second;
        pq.pop();

        if (visited[current - 1]) continue;
        visited[current - 1] = true;

        //  соседи
        for (int i = 0; i < graph[current - 1].ver.size(); i++) {
            //
            int next_vertex = graph[current - 1].ver[i];
            int weight = graph[current - 1].dist[i];
            //
            if (distance[current - 1] + weight < distance[next_vertex - 1]) {
                distance[next_vertex - 1] = distance[current - 1] + weight;
                previous[next_vertex - 1] = current;
                pq.push(make_pair(distance[next_vertex - 1], next_vertex));
            }
        }
    }

    //  путь
    vector<int> path;
    int current = end_vertex;
    while (previous[current - 1] != -1) {
        path.push_back(current);
        current = previous[current - 1];
    }
    path.push_back(current);

    reverse(path.begin(), path.end());

    if (distance[end_vertex - 1] != INFINITY && previous[end_vertex - 1] != -1) {
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1)
                cout << " -> ";
        }
        cout << ", distance = " << distance[end_vertex - 1];
    } else {
        cout << "no path.";
    }
}

int main() {

    clock_t start = clock();
    clock_t end;
    double seconds;

    Generator(20000,10,200,"output.txt");
    end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Generator: " << seconds << "s\n";

    start = clock();
    vector<vertex>matrix;
    if(readFile("output.txt",matrix)) {
        int start = 1;
        int end = matrix.size();
        dijkstra(matrix,start, end);
    }
    else {
        cout << " i don't work with negative numbers ";
        return 0;
    }

    /*
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0 ; j < matrix[i].dist.size();j++)
            cout << matrix[i].dist[j] << " ";
        cout << endl;
    }
    */
    end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "\nAlgorithm: " << seconds << "s";
        return 0;
}
