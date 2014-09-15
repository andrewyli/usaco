#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    fstream stream;
    stream.open("scramble.in", ios::in);
    int n;
    string b;
    stream >> n;

    int v[n];

    for (int i = 0; i < n; i++)
    {
        stream >> b;
        v[i] = b;
    }
    
    for (int i = 0; i < v.size(); i++)
    {
        
    }
    
    return 0;
}
