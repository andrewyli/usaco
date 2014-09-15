#include <limits>
#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("skidesign.in");
    ofstream fout("skidesign.out");

    int n;
    fin >> n;

    vector<int> v;
    int buffer;
    for (int i = 0; i < n; i++)
    {
        fin >> buffer;
        v.push_back(buffer);
    }
    sort(v.begin(), v.end());
    int tempmin = numeric_limits<int>::max();
    int finalmin = numeric_limits<int>::max();
    for (int i = 0; i < 83; i++)
    {
        tempmin = 0;
        for (int j = 0; j < n; j++)
        {
            if (v[j] < i)
            {
                tempmin += (i - v[j])*(i - v[j]);
            }
            else if (v[j] > i + 17)
            {
                tempmin += (v[j] - i - 17)*(v[j] - i - 17);
            }
        }
        if (tempmin < finalmin)
            finalmin = tempmin;
    }
    fout << finalmin << "\n";
}
