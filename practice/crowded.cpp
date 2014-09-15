#include <cmath>
#include <algorithm>
#include <utility>
#include <iostream>
#include <fstream>

#define MAX_N 50000
std::pair<int, int> a[MAX_N];

bool h_comp(std::pair<int, int> a, std::pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    std::ifstream fin("crowded.in");
    std::ofstream fout("crowded.out");
    
    int n, d;
    fin >> n >> d;
    int x;
    int h;
    for (int i = 0; i < n; i++)
    {
        fin >> x >> h;
        a[i] = std::make_pair(x, h);
    }
    std::sort(a, a + n, h_comp);

    for (int i = 0; i < n; i++)
    {
        
    }
}
