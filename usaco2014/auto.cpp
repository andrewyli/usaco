#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;

vector<string> dict;
vector<string> tasks;
vector<int> indexer;
int main()
{
    ifstream fin("auto.in");
    ofstream fout("auto.out");
    
    int w, n;
    fin >> w >> n;

    string buffer;
    int k_i = 0;
    for (int i = 0; i < w; i++)
    {
        fin >> buffer;
        dict.push_back(buffer);
        //cout << dict[i] << " ";
    }
    //cout << "\n";
    for (int i = 0; i < n; i++)
    {
        fin >> k_i >> buffer;
        tasks.push_back(buffer);
        indexer.push_back(k_i);
    }
    vector<string> dict_holder = dict;
    sort(dict.begin(), dict.end()); //sorted for convenience.
    for (int i = 0; i < dict.size(); i++)
    {
        //cout << dict[i] << " ";
    }
    //cout << "\n";
    int index = 0;
    bool success = true;
    for (int i = 0; i < n; i++) //main loop, go through all the necessary words
    {
        success = false;
        for (int j = 0; j < w; j++)
        {
            if (tasks[i] == dict[j].substr(0, tasks[i].length()))
            {
                index++;
                //cout << "index increased" << "\n";
            }
            if (index == indexer[i])
            {
                int location = (int)(find(dict_holder.begin(), dict_holder.end(), dict[j]) - dict_holder.begin());
                fout << location + 1 << "\n";
                //cout << dict[j - 1] << "\n";
                success = true;
                break;
            }
        }
        if (!success)
        {
            fout << "-1" << "\n";
        }
        success = false;
        index = 0;
    }
}
