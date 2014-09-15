#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int mod(int a, int b) {
    int ret = a % b;
    if (ret < 0)
        ret += b;
    return ret;
}

class Combination
{
public:
    int first;
    int second;
    int third;
    Combination (int f, int s, int t);
};

Combination::Combination (int f, int s, int t){
    first = f;
    second = s;
    third = t;
}
vector<Combination> comboCounter(vector<int>& v, int n)
{
    Combination a(0, 0, 0);
    vector<Combination> combos;
    int itemp = 0;
    int jtemp = 0;
    int ktemp = 0;
    for (int i = v[0] - 2; i < v[0] + 3; i++)
    {
        for (int j = v[1] - 2; j < v[1] + 3; j++)
        {
            for (int k = v[2] - 2; k < v[2] + 3; k++)
            {
                /*if (i > n)
                    itemp = i % n;
                else if (i < 1)
                    itemp = i + n;
                else itemp = i;
                if (j > n)
                    jtemp = j % n;
                else if (j < 1)
                    jtemp = j + n;
                else jtemp = j;
                if (k > n)
                    ktemp = k % n;
                else if (k < 1)
                    ktemp = k + n;
                    else ktemp = k;*/
                itemp = mod(i, n);
                jtemp = mod(j, n);
                ktemp = mod(k, n);
                a = Combination(itemp, jtemp, ktemp);
                combos.push_back(a);
            }
        }
    }
    return combos;
}

int main()
{
    fstream stream;
    stream.open("combo.in", ios::in);
    int n = 0;
    stream >> n;

    int totalcount = 0;
    vector<int> farmer;
    vector<int> master;
    int temp = 0;
    for (int i = 0; i < 3; i++)
    {
        stream >> temp;
        farmer.push_back(temp);
    }
    for (int i = 0; i < 3; i++)
    {
        stream >> temp;
        master.push_back(temp);
    }
    vector<Combination> fcombos = comboCounter(farmer, n);
    vector<Combination> mcombos = comboCounter(master, n);
    for (int i = 0; i < fcombos.size(); i++)
    {
        for (int j = 0; j < mcombos.size(); j++)
        {
            if (fcombos[i].first == mcombos[j].first && fcombos[i].second == mcombos[j].second && fcombos[i].third == mcombos[j].third)
            {
                totalcount--;
            }
        }
    }
    totalcount += fcombos.size() + mcombos.size();
    stream.close();
    stream.open("combo.out", ios::out);
    stream << totalcount << endl;
}
