#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

/*
  Assume they are of same length
*/
bool vec_eq(vector<int>& a, vector<int>& b)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            return false; 
    }
    return true;
}

int main()
{
    ifstream fin("reorder.in");
    ofstream fout("reorder.out");
    vector<int> a; //original
    vector<int> b; //final product
    vector<bool> not_in_cycle;
    int num_cycle = 0;
    int max_length = 0;

    int n;
    fin >> n;

    int buffer;
    for (int i = 0; i < n; i++)
    {
        fin >> buffer;
        a.push_back(buffer);
        not_in_cycle.push_back(true);
    }
    for (int i = 0; i < n; i++)
    {
        fin >> buffer;
        b.push_back(buffer);
    }
    
    int next_index = 0;
    int first_index = 0;
    int curr_index = 0;
    int curr_length = 0;
    while (!vec_eq(a, b))
    {
        next_index = 200; //arbitrary bigger than 100
        first_index = 0;
        curr_index = 0;
        curr_length = 0;

        while (not_in_cycle[first_index] == false)
            first_index++;
        curr_index = first_index;
        not_in_cycle[curr_index] = false;

        while (next_index != first_index)
        {
            next_index = find(b.begin(), b.end(), a[curr_index]) - b.begin();
            int storage = a[next_index];
            a[next_index] = a[curr_index]; //moving in
            a[curr_index] = storage;
            curr_length++;
            not_in_cycle[next_index] = false;
        }

        if (curr_length > max_length)
            max_length = curr_length;
        num_cycle++;
    }
    
    fout << num_cycle << " " << max_length << '\n';
    return 0;
}

