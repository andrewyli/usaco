/*
LANG: C++
ID: andrewy3
PROB: crypt1
*/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    vector<int> set;
    ifstream fin("crypt1.in");
    ofstream fout("crypt1.out");

    int n;
    fin >> n;
    
    int buffer;
    for (int i = 0; i < n; i++)
    {
        fin >> buffer;
        set.push_back(buffer);
    }
    int tri[3];
    int bi[2];
    int quad = 0;
    int quad1 = 0;
    int quad2 = 0;
    int numsol = 0;
    for (int i = 0; i < pow(n, 3); i++)
    {
        for (int j = 0; j < pow(n, 2); j++)
        {
            tri[0] = set[i%n]; tri[2] = set[(i/(n*n))%n]; tri[1] = set[(i/n)%n];
            bi[1] = set[((j/n)%n)]; bi[0] = set[j%n];
            quad1 = tri[0]*bi[0] + tri[1]*bi[0]*10 + tri[2]*bi[0]*100;
            quad2 = tri[0]*bi[1] + tri[1]*bi[1]*10 + tri[2]*bi[1]*100;
            quad = quad1+quad2*10;
            if (quad1 < 1000 && quad2 < 9991 && quad < 10000 && quad >= 1000 && find(set.begin(), set.end(), quad1 % 10) != set.end() && find(set.begin(), set.end(), (quad1/10) % 10) != set.end() && find(set.begin(), set.end(), (quad1/100) % 10) != set.end() && find(set.begin(), set.end(), quad2 % 10) != set.end() && find(set.begin(), set.end(), (quad2/10) % 10) != set.end() && find(set.begin(), set.end(), (quad2/100) % 10) != set.end() && find(set.begin(), set.end(), quad % 10) != set.end() && find(set.begin(), set.end(), (quad/10) % 10) != set.end() && find(set.begin(), set.end(), (quad/100) % 10) != set.end() && find(set.begin(), set.end(), (quad/1000) % 10) != set.end())
            {
                //cout << quad1 << ", " << quad2 << "\n";
                //cout << bi[1] << bi[0] << "\n" << tri[2] << tri[1] << tri[0] << "\n" << quad << "\n";
                numsol++;
            }
        }
    }
    fout << numsol << "\n";
}
