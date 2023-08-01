/*
 _   _   _____   _____            __    _____   __
| | | | /  __ \ | ___ \          /  |  / __  \ /  |
| | | | | /  \/ | |_/ /  ______  `| | ` ' / /' `| |
| | | | | |     | ___ \ |______|  | |    / /    | |
| |_| | | \__ /\| |_/ /          _| |_ ./ /___ _| |_
 \___/   \____/ \____/           \___/ \_____/ \___/
					VengerMethod.cpp
*/
#include "Header.h"

#include <unistd.h> // sleep();
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>

using namespace std;
//
//  В каждой строке и в каждом столбце должен быть только один выбранный ноль.
//
bool ChekSet(vector<vector<int>> matrix, vector<vector<int>>zeroMatrix,vector<vector<int>>copy)
{
vector<vector<int>> SetMax;
vector<int>Set;
int maximum = 0;
for (int i = 0 ; i < matrix[0].size(); i ++ )
{
SetMax.push_back(Set);
for (int j = 0 ; j < matrix.size() ; j++ )
{
if (zeroMatrix[j][i] == 0 && matrix[j][i] == 0)
{
SetMax[i].push_back(j);
maximum += copy[j][i];
// столбцы
for (int n = 0; n < matrix.size(); n++)
zeroMatrix[n][i] = 1;
// строки
for ( int n = 0 ; n < matrix[j].size(); n ++ )
zeroMatrix[j][n] = 1;
}
}
}
for(int i = 0; i < zeroMatrix.size();i++)
if (count(zeroMatrix[i].begin(),zeroMatrix[i].end(), 0) > 0)
return false;
cout << "--------------------------\n";
cout << "Cmax ";
for(int i = 0 ; i < SetMax.size();i++)
for(int j = 0; j < SetMax[i].size();j++)
cout << "("<< SetMax[i][j] + 1<< ";"<<i + 1 <<")"<< " ";
cout << "= " << maximum;
cout <<"\n--------------------------";
return true;
}
//  Вычитаем максимальный элемент строки и умножаем на -1
void FirstStepMax(vector<vector<int>>&matrix)
{

    for (int i = 0; i < matrix.size(); i ++)
    {
        int max = *max_element(matrix[i].begin(),matrix[i].end());
        for (int j = 0; j < matrix[i].size();j ++)
        {
            matrix[i][j] -= max;
            matrix[i][j] *= -1;
        }
    }
}
//
//  Редукция матрицы по строкам
void RowReduction(vector<vector<int>>& matrix)
{
    for (int i = 0; i < matrix.size(); i ++)
    {
        int min = *min_element(matrix[i].begin(),matrix[i].end());
        for (int j = 0; j < matrix[i].size();j ++)
            matrix[i][j] -= min;
    }
}
//
//  Редукция матрицы по столбцам
void ColumnReduction(vector<vector<int>>& matrix)
{
    for (int j = 0  ; j < matrix[j].size() ; j++ )
    {
        float min = INFINITY;
        for (int i = 0 ; i < matrix.size(); i ++ ) {
            if (matrix[i][j] < min)
                min = matrix[i][j];
        }
        for (int i = 0 ; i < matrix.size(); i ++ ) {
            matrix[i][j] -= min;
        }
    }
}
//
//  Количество вычеркиваний должно быть минимальным
void Deletion(vector<vector<int>>&matrix,vector<vector<int>> zeroMatrix)
{
    vector<int>rowZero;
    int column;
    for (int i = 0 ; i < matrix[0].size(); i ++ )
    {
        column = 0;
        vector<int>row;
        for (int j = 0  ; j < matrix.size() ; j++ )
        {
                if (matrix[j][i] == 0 && zeroMatrix[j][i] == 0) {
                    column++;
                    row.push_back(j);
                }
                if (rowZero.size() < matrix.size()) {
                    int c = count(matrix[j].begin(), matrix[j].end(), 0);
                    rowZero.push_back(c);
                }
        }
        for(auto k : row)
        {
            if (rowZero[k] > column)
            {
                if(zeroMatrix[k][i] == 0) {
                    for (int j = 0; j < matrix[k].size(); j++) {
                        if (zeroMatrix[k][j] == 1)
                            zeroMatrix[k][j] = 2;
                        else
                            zeroMatrix[k][j] = 1;
                    }
                }
            }
            else {
                if (zeroMatrix[k][i] == 0) {
                    for (int j = 0; j < matrix.size(); j++) {
                        if (zeroMatrix[j][i] == 1)
                            zeroMatrix[j][i] = 2;
                        else
                            zeroMatrix[j][i] = 1;
                    }
                }
            }
        }
        row.clear();
    }
    vector<int>Elements;
    for(int i = 0; i < zeroMatrix.size(); i++)
    {
        int c = count(zeroMatrix[i].begin(),zeroMatrix[i].end(),0);
        int cC; // счётчик нулей. если он совпадает с кол-во ^ то break;
        for(int j = 0; j < zeroMatrix[i].size();j++)
        {
            if (cC == c) break;
            if (zeroMatrix[i][j] == 0){
                cC++;
                Elements.push_back(matrix[i][j]);
            }
        }
    }
        for (int i = 0; i < zeroMatrix.size(); i++) {
            if (Elements.empty()) break;
            for (int j = 0; j < zeroMatrix[i].size(); j++) {
                int min = *min_element(Elements.begin(), Elements.end());
                if (zeroMatrix[i][j] == 0) {
                    matrix[i][j] -= min;
                }
                if (zeroMatrix[i][j] == 2) {
                    matrix[i][j] += min;
                }
            }
        }
}
//
//  Венгерский алгоритм
void VengerMathod(vector<vector<int>>& matrix, vector<vector<int>>& zeroMatrix)
{
    vector<vector<int>>matrixCopy = matrix;
    FirstStepMax(matrix);
    do {
        RowReduction(matrix);
        ColumnReduction(matrix);
        Deletion(matrix,zeroMatrix);
    } while (!ChekSet(matrix,zeroMatrix,matrixCopy));
}
//
int main()
{	//	time
	clock_t start;
    clock_t startProgram = clock();
    //
	clock_t end;
    clock_t endProgram;
    //
	double seconds;
	//
    GenGraph(2500, 4500, 100);
    vector<vector<int>> zeroMatrix;
    start = clock();
	vector<vector<int>>matrix = ReadMatrix("matrix.txt",zeroMatrix);
    end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "The matrix has read successfully\tThe time: " << seconds << "s\n";
	//
    start = clock();
    VengerMathod(matrix,zeroMatrix);
    //
    end = clock();
    endProgram = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "\nThe method has completed\tThe time: " << seconds << "s\n";
    seconds = (double)(endProgram - startProgram) / CLOCKS_PER_SEC;
    cout << "\nThe program has completed\tThe time: " << seconds << "s\n";
    return 0;
}