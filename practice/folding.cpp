#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream stream;
    stream.open("folding.in", ios::in);
    
    vector<int> knots;

    int n = 0;
    stream >> n;
    
    int l = 0;
    stream >> l;

    int buffer = 0;
    for (int i = 0; i < n; i++)
    {
        stream >> buffer;
        knots.push_back(buffer);
    }
    sort(knots.begin(); knots.end());

    return 0;
}
