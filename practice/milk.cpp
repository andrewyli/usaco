/*
PROB: milk
ID: andrewy3
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Farmer
{
    int price;
    int max;
};

bool operator< (const Farmer& f1, const Farmer& f2)
{
    return f1.price < f2.price;
}

int main()
{
    vector<Farmer> farmers;

    ifstream fin("milk.in");
    ofstream fout("milk.out");

    int n, m;
    fin >> n >> m;

    int pi, ai;
    for (int i = 0; i < m; i++)
    {
        fin >> pi >> ai;
        Farmer f;
        f.price = pi;
        f.max = ai;
        farmers.push_back(f);
    }

    sort(farmers.begin(), farmers.end());

    int currentmilk = 0;
    int totalprice = 0;
    while (currentmilk < n)
    {
        if (farmers[0].max > 0)
        {
            farmers[0].max--;
            totalprice += farmers[0].price;
            //cout << totalprice << "\n";
            currentmilk++;
        }
        else if (farmers.size() >= 1)
        {
            farmers.erase(farmers.begin());
        }
    }
    
    fout << totalprice << "\n";
}

