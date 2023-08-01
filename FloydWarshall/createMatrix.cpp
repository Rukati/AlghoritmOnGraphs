#include <iostream>
#include <vector>
#include <limits>

using namespace std;

#define INF numeric_limits<int>::max()

vector<vector<int>> createMatrix(vector<vector<int>>& graph) {
    const int n = graph.size();
    vector<vector<int>> adjacencyMatrix(n, vector<int>(n, INF));

    for (int i = 0; i < n; ++i) {
        adjacencyMatrix[i][i] = 0; 

        for (size_t j = 0; j < graph[i].size(); j += 2) {
            int vertex = graph[i][j];
            int weight = graph[i][j + 1];
            if (vertex >= 1 && vertex <= n) {
                adjacencyMatrix[i][vertex - 1] = weight;
            }
        }
    }

    return adjacencyMatrix;
}

