#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;

int comp(int a, int b)
{
    return a < b;
}

int main()
{
    fstream stream;
    stream.open("baseball.in", ios::in);
    int n;
    stream >> n;
    int buffer;
    int count = 0;
    vector<int> cows;
    vector<int> diffs;
    for (int i = 0; i < n; i++)
    {
        stream >> buffer;
        cows.push_back(buffer);
    }
    sort(cows.begin(), cows.end(), comp);
    /*
    for (int i = 0; i < n; i++)
    {
        cout << cows[i];
    }*/
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = i + 1; k < j; k++)
            {
                if (2*(cows[k] - cows[i]) >= cows[j] - cows[k] && cows[k] - cows[i] <= cows[j] - cows[k])
                {
                    count++;
                    //cout << cows[i] << "-" << cows[k] << "-" << cows[j] << endl;
                }
            }
        }
    }
    stream.close();
    stream.open("baseball.out", ios::out);
    stream << count << "\n";
}
