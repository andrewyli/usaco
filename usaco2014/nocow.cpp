#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
/*
vector<string> generator(vector<string>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        
    }
}
*/

int comeBefore(vector<vector<string> > v, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return v[n-1].size() * comeBefore(v, n - 1);
    }
}
int main()
{
    fstream stream;
    stream.open("nocow.in", ios::in);
    int n = 0;
    int k = 0;
    stream >> n; stream >> k;

    vector<vector<string> > adjgroups;
    vector<string> temp;
    string word = "";
    string censored = "";
    vector<string> paststates;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        while (word.compare("cow.") != 0)
        {
            if (i == 0 && count > 4)
            {
                temp.push_back(word);
                adjgroups.push_back(temp);
                temp.clear();
                censored += word;
            }
            else if (count > 4) 
            {
                adjgroups[count - 5].push_back(word);
                censored += word;
            }
            count++;
            stream >> word;
        }
        count = 0;
        word = "";
        paststates.push_back(censored);
        censored = "";
    }
    long long int maxcombo = 1;
    for (int i = 0; i < adjgroups.size(); i++)
    {
        maxcombo *= adjgroups[i].size();
    }
    string test = "";
    int counter = 0;
    int storei = 0;
    int storej = 0;
    vector<string> currentstates;
    for (int i = 0; i < maxcombo; i++)
    {
        for (int j = 0; j < adjgroups.size(); j++)
        {
            test += adjgroups[j][((int)(i / comeBefore(adjgroups, j)))%j];
            storej = j;
        }
        if (find(paststates.begin(), paststates.end(), test) == paststates.end())
            counter++;
        if (counter == k)
        {
            storei = i;
            break;
        }
            
    }
    stream.close();
    stream.open("nocow.out", ios::out);
    for (int i = 0; i < adjgroups.size(); i++)
    {
        stream << adjgroups[i][((int)(storei / comeBefore(adjgroups, i)))%i];
        stream << " ";
    }
    stream << endl;
    stream.close();
    return 0;
}
