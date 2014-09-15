/*
  ID: andrewy3
  PROB: clocks
  LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("clocks.in");
    ofstream fout("clocks.out");
    
    vector<vector<int> > clocks;
    int a, b, c;
    for (int i = 0; i < 3; i++)
    {
        vector<int> row;
        fin >> a, b, c;
        row.push_back(a);
        row.push_back(b);
        row.push_back(c);
        clocks.push_back(row);
    }

}

int turnClock(int n)
{
    return (n + 3) % 12;
}

void move1(vector<vector<int> >& v)
{
    v[0][0] = turnClock(v[0][0]);
    v[0][1] = turnClock(v[0][1]);
    v[1][0] = turnClock(v[1][0]);
    v[1][1] = turnClock(v[1][1]);    
}
void move2(vector<vector<int> >& v)
{
    
}
void move3(vector<vector<int> >& v)
{
}
void move4(vector<vector<int> >& v)
{
    
}
void move5(vector<vector<int> >& v)
{
    
}
void move6(vector<vector<int> >& v)
{
    
}
void move7(vector<vector<int> >& v)
{
    v[1][0] = turnClock(v[1][0]);
    v[1][1] = turnClock(v[1][1]);
    v[0][2] = turnClock(v[2][0]);
    v[1][2] = turnClock(v[1][2]);
}
void move8(vector<vector<int> >& v)
{
    v[2][0] = turnClock(v[2][0]);
    v[2][1] = turnClock(v[2][1]);
    v[2][2] = turnClock(v[2][2]);    
}
void move9(vector<vector<int> >& v)
{
    v[1][1] = turnClock(v[1][1]);
    v[2][1] = turnClock(v[2][1]);
    v[1][2] = turnClock(v[1][2]);
    v[2][2] = turnClock(v[2][2]);    
}
