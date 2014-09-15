#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int max_size = 0;

struct Cow;
bool comp(Cow, Cow);
bool less_spotted(vector<Cow>&, int, int);
void calculate(vector<Cow>&, int, int);

struct Cow
{
    int pos;
    bool spotted;
};

int main()
{
    vector<Cow> cows;
    ifstream fin("fairphoto.in");
    ofstream fout("fairphoto.out");

    int n;
    fin >> n;
    
    int buffer;
    char input;
    for (int i = 0; i < n; i++)
    {
        fin >> buffer >> input;
        Cow a;
        a.pos = buffer;
        a.spotted = input;
        cows.push_back(a);
    }
    cout << "starting sort\n";
    sort(cows.begin(), cows.end(), comp);
    cout << "sorted\n";
    calculate(cows, 0, cows.size() - 1);
    fout << max_size << '\n';
}

bool comp(Cow a, Cow b)
{
    return a.pos < b.pos;
}

void calculate(vector<Cow>& v, int left, int right)
{
    if (less_spotted(v, left, right))
    {
        if (max_size < right - left)
        {
            cout << "changed max\n";
            max_size = right - left;
        }
        return;
    }
    else
    {
        if (right - left == 1)
            return;
        if (v[left + 1].spotted && v[right - 1].spotted)
        {
            return calculate(v, left + 1, right - 1);
        }
        if (v[right - 1].spotted)
        {
            return calculate(v, left, right - 1);
        }
        if (v[left + 1].spotted)
        {
            return calculate(v, left + 1, right);
        }
    }
}

/*
  left and right are inclusive
*/
bool less_spotted(vector<Cow>& v, int left, int right)
{
    int white = 0;
    int spotted = 0;
    for (int i = left; i <= right; i++)
    {
        if (v[i].spotted)
            spotted++;
        else
            white++;
    }
    if (spotted <= white)
        return true;
    cout << "spotted more\n";
    return false;
}
