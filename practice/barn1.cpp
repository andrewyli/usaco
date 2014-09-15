/*
PROB: barn1
ID: andrewy3
LANG: C++
*/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    vector<int> occupied;
    vector<int> spaces;
    ifstream fin("barn1.in");
    ofstream fout("barn1.out");
    
    int m = 0, s = 0, c = 0;
    fin >> m >> s >> c;
    
    int buffer = 0;
    for (int i = 0; i < c; i++)
    {
        fin >> buffer;
        occupied.push_back(buffer);
    }
    sort(occupied.begin(), occupied.end());
    for (int i = 0; i < occupied.size() - 1; i++)
    {
        spaces.push_back(occupied[i + 1] - occupied[i] - 1);
    }
    sort(spaces.begin(), spaces.end(), compare);

    int numcovered = occupied[occupied.size() - 1] - occupied[0] + 1;
    int numfences = 1;
    while (numfences < m && !(spaces.size() == 0))
    {
        numcovered -= spaces[0];
        spaces.erase(spaces.begin());
        numfences++;
    }
    
    fout << numcovered << "\n";
}
