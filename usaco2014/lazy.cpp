#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Spot
{
    int amt;
    int loc;
};

bool comp(Spot a, Spot b)
{
    return a.loc < b.loc;
}

int main()
{
    ifstream fin("lazy.in");
    ofstream fout("lazy.out");
    vector<Spot> grass_spots;

    int n = 0;
    int k = 0;
    fin >> n >> k;

    int buffer, buffer2;
    for (int i = 0; i < n; i++)
    {
        fin >> buffer >> buffer2;
        Spot a;
        a.amt = buffer;
        a.loc = buffer2;
        grass_spots.push_back(a);
    }

    sort(grass_spots.begin(), grass_spots.end(), comp);
    
/*
    for (int i = 0; i < grass_spots.size(); i++)
    {
        cout << grass_spots[i].amt << ',' << grass_spots[i].loc << '\n';
    }
*/
    int curr_sum = 0;
    int max_sum = 0;
    for (int i = 0; i < grass_spots.size(); i++)
    {
        curr_sum = grass_spots[i].amt;
        for (int j = i + 1; j < grass_spots.size(); j++)
        {
            if (grass_spots[j].loc - grass_spots[i].loc <= 2*k)
                curr_sum += grass_spots[j].amt;
            else
                break;
        }
        if (curr_sum > max_sum)
            max_sum = curr_sum;
        //cout << curr_sum << '\n';
        curr_sum = 0;
    }
    fout << max_sum << '\n';
    return 0;
}
