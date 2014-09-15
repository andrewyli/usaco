#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

void det_region(vector<vector<char> >& v, vector<vector<bool> >& b, int i, int j)
{
    //cout << i << ", " << j << '\n';
    b[i][j] = true;
    if (i > 0)
    {
        if (b[i - 1][j] == false && v[i - 1][j] == v[i][j])
        {
            det_region(v, b, i - 1, j);
        }
    }
    if (i < v.size() - 1)
    {
        if (b[i + 1][j] == false && v[i + 1][j] == v[i][j])
        {
            det_region(v, b, i + 1, j);
        }
    }
    if (j > 0)
    {
        if (b[i][j - 1] == false && v[i][j - 1] == v[i][j])
        {
            det_region(v, b, i, j - 1);
        }
    }
    if (j < v.size() - 1)
    {
        if (b[i][j + 1] == false && v[i][j + 1] == v[i][j])
        {
            det_region(v, b, i, j + 1);
        }
    }
    return;
}

int count_regions(vector<vector<char> >& v)
{
    int num_region = 0;
    vector<vector<bool> > in_region;
    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        vector<bool> temp;
        for (int j = 0; j < size; j++)
        {
            temp.push_back(false);
        }
        in_region.push_back(temp);
    }
    int next_i = 0;
    int next_j = 0;
    for (int i = 0; i < size*size; i++)
    {
        if (in_region[i / size][i % size] == false)
        {
            next_i = i / size;
            next_j = i % size;
            //cout << '\n' << next_i << " " << next_j << '\n';
            //cout << "------------------------" << '\n';
            det_region(v, in_region, next_i, next_j);
            num_region++;
        }
    }
    return num_region;
}

int main()
{
    ifstream fin("cowart.in");
    ofstream fout("cowart.out");
    vector<vector<char> > painting_h;
    vector<vector<char> > painting_c;
    int n;
    fin >> n;

    char buffer;
    for (int i = 0; i < n; i++)
    {
        vector<char> temp_h;
        vector<char> temp_c;
        for (int j = 0; j < n; j++)
        {
            fin >> buffer;
            temp_h.push_back(buffer);
            if (buffer == 'G')
                temp_c.push_back('R');
            else
                temp_c.push_back(buffer);
        }
        painting_h.push_back(temp_h);
        painting_c.push_back(temp_c);
    }
    int regions_h = count_regions(painting_h);
    int regions_c = count_regions(painting_c);
    fout << regions_h << " " << regions_c << '\n';
}
