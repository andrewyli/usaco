#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
    fstream stream;
    stream.open("relay.in", ios::in);
    int sum = 0;
    vector<int> values;
    
    int n = 0;
    stream >> n;
    
    int buffer = 0;
    for (int i = 0; i < n; i++)
    {
        stream >> buffer;
        values.push_back(buffer);
    }
    int current = 0;
    int next = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        current = values[i];
        while (current != 0)
        {
            next = values[current];
            current = next;
            cout << " ->" << current;
            count++;
            if (count > n + 2)
            {
                break;
            }

        }
        if (count <= n + 2)
        {
            count = 0;
            sum++;
        }
        else
        {
            count = 0;
        }
        
    }
    stream.close();
    stream.open("relay.out", ios::out);
    stream << sum;
}
