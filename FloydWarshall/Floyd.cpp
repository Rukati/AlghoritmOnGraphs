#include "Header.h"
#include <vector>
#include <iostream>
#include <clocale>
#include <numeric>

#define file "output.txt"
#define INF numeric_limits<int>::max()

using namespace std;

void PrintPath(const vector<vector<int>>& ancestors, int startVertex, int endVertex) {
    vector<int> path;
    int current = startVertex - 1;

    while (current != endVertex - 1) {
        path.push_back(current);
        current = ancestors[current][endVertex - 1] - 1;
    }
    path.push_back(current);
    cout << "Путь: ";
    for (int vertex : path) {
        cout << vertex + 1 << " ";
    }
    
    cout << endl;
}

void AlgorithmFloyda(vector<vector<int>>& matrix) {
    clock_t start = clock();
    clock_t end;
    double seconds;

    int n = matrix.size();

    vector<vector<int>> ancestors(n, vector<int>(n, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != INF && i != j) {
                ancestors[i][j] = j + 1;
            }
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][k] < INF && matrix[k][j] < INF) {
                    if (matrix[i][k] + matrix[k][j] < matrix[i][j]) 
                    {
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                        ancestors[i][j] = ancestors[i][k];
                    }
                }
            }
        }
    }

    end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "\nThe time algorithm: " << seconds << "s\n";

    //printMatrix(ancestors); 
    cout << endl;
    int startVertex;
    int endVertex;
    while (true) {
        cout << "Введите первую вершину: ";
        cin >> startVertex;
        cout << "Введите вторую вершину: ";
        cin >> endVertex;

        if (startVertex < 1 || startVertex > n || endVertex < 1 || endVertex > n) {
            cout << "Некорректные вершины. Попробуйте снова.\n";
            continue;
        }

        if (matrix[startVertex - 1][endVertex - 1] == INF) {
            cout << "Нет пути\n";
            continue;
        }

        PrintPath(ancestors, startVertex, endVertex);
        cout << "Длина пути: " << matrix[startVertex - 1][endVertex - 1] << endl << endl;
    }
}


int main() {
    setlocale(LC_ALL, "ru");

    int row, column, dist;
    cout << "Вершин, связей, вес: ";
    cin >> row >> column >> dist;

    clock_t start = clock();
    clock_t end;
    double seconds;

    Graph(row, column, dist, file);
    end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "\nThe time generator: " << seconds << "s\n";
    start = clock();

    vector<vector<int>>graph;
    vector<vector<int>>matrix;

    if (Read(file, graph))
        matrix = createMatrix(graph);
    end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "\nThe time create matrix: " << seconds << "s\n";
    start = clock();

    //printMatrix(matrix);
    //cout << endl;
    AlgorithmFloyda(matrix);
    return 0;
}