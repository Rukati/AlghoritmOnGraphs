#include <string>
#include <vector>
#include <cmath>

using namespace std;

void Generator(int row, int column, int max_weight, string name);

class vertex
{
public:
    vector<int>dist;
    vector<int>ver;
};

bool readFile(string file, vector<vertex>& matrix);