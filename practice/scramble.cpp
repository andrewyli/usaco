#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(char c1, char c2)
{
    return c1 < c2;
}

bool comp2(char c1, char c2)
{
    return c2 < c1;
}

int main()
{
    fstream stream;
    stream.open("scramble.in", ios::in);
    int n;
    string b;
    stream >> n;

    string v1[n];
    string v2[n];

    for (int i = 0; i < n; i++)
    {
        stream >> b;
        v1[i] = b;
        v2[i] = b;
    }
    
    for (int i = 0; i < n; i++)
    {
        sort(v1[i].begin(), v1[i].end(), comp);
        sort(v2[i].begin(), v2[i].end(), comp2);
    }
    sort(v1.begin(), v1.end());
    sort(v1.begin(), v1.end());
    for (int i = 0; i < n; i++)
    {
        
    }
    return 0;
}
