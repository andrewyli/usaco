#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("slowdown.in");
    ofstream fout("slowdown.out");
    
    int n;
    fin >> n;

    char buffer;
    double value;
    vector<double> times;
    vector<double> distances;
    for (int i = 0; i < n; i++)
    {
        fin >> buffer;
        fin >> value;
        if (buffer == 'T')
            times.push_back(value);
        else if (buffer == 'D')
            distances.push_back(value);
    }
    sort(times.begin(), times.end());
    sort(distances.begin(), distances.end());
    
    double currenttime = 0.0;
    double currentdistance = 0.0;
    double reciprocal = 1.0;
    while (times.size() > 0 || distances.size() > 0)
    {
        bool isTimeNext = false;
        if (distances.empty())
        {
            isTimeNext = true;
        }
        else if (!distances.empty() && !times.empty() && currentdistance + (1.0 / reciprocal)*(times[0] - currenttime) < distances[0])
        {
            isTimeNext = true;
        }
        if (isTimeNext)
        {
            currentdistance += (times[0] - currenttime)*(1 / reciprocal);
            currenttime = times[0];
            times.erase(times.begin());
        }
        else
        {
            currenttime += (distances[0] - currentdistance)*reciprocal;
            currentdistance = distances[0];
            distances.erase(distances.begin());
        }
        reciprocal++;
    }
    fout << floor(currenttime+0.5) << "\n";
}
