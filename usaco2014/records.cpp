#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Group
{
public:
    string a;
    string b;
    string c;
    int count;
    void organize();
    Group (string a1, string a2, string a3, int d) {a = a1; b = a2; c = a3; count = d;}
};

void Group::organize()
{
    string temp = "";
    if (b.compare(a) < 0)
    {
        temp = b;
        b = a;
        a = temp;
    }
    if (c.compare(b) < 0)
    {
        temp = b;
        b = c;
        c = temp;
    }
    if (b.compare(a) < 0)
    {
        temp = b;
        b = a;
        a = temp;
    }
}

int main()
{
    fstream stream;
    stream.open("records.in", ios::in);
    int n = 0;
    stream >> n;
    vector<Group> v;
    string a = "foo";
    string b = "foo";
    string c = "foo";
    bool changed = false;
    for (int i = 0; i < n; i++)
    {
        stream >> a >> b >> c;
        Group g(a, b, c, 1);
        g.organize();
        for (int j = 0; j < v.size(); j++)
        {
            if (v[j].a == g.a && v[j].b == g.b && v[j].c == g.c)
            {
                v[j].count++;
                changed = true;
            }
        }
        if (!changed)
            v.push_back(g);
        changed = false;
    }
    int max = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (max < v[i].count)
            max = v[i].count;
    }
    stream.close();
    stream.open("records.out", ios::out);
    stream << max << "\n";
    return 0;
}
