#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
using namespace std;

int team[12];
int minimum = numeric_limits<int>::max();

int generate()
{
    int sums[4];
    int count = 0;
    do
    {
        sums[0] = team[0] + team[4] + team[8];
        sums[1] = team[1] + team[5] + team[9];
        sums[2] = team[2] + team[6] + team[10];
        sums[3] = team[3] + team[7] + team[11];
        sort(sums, sums + 4);
        if (minimum > sums[3] - sums[0])
            minimum = sums[3] - sums[0];
        if (minimum == 876994)
        {
            cout << team[0] << ", " << team[4] << ", " << team[8] << "\n";
            cout << team[1] << ", " << team[5] << ", " << team [9] << "\n";
            cout << team[2] << ", " << team[6] << ", " << team [10] << "\n";
        }
        count++;
    }   while (next_permutation(team, team + 12) && minimum > 0 && count < 4000000);
}

int main()
{
    clock_t t;
    int f;
    t = clock();
    ifstream fin("bteams.in");
    ofstream fout("bteams.out");
    
    int buffer;
    for (int i = 0; i < 12; i++)
    {
        fin >> buffer;
        team[i] = buffer;
    }
    sort(team, team + 12);
    
    generate();
    cout << minimum << "\n";
    fout << minimum << "\n";
    t = clock() - t;
    cout << ((float)t)/CLOCKS_PER_SEC;
}
