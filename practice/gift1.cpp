/*
ID: andrewy3
PROB: gift1
LANG: C++
*/
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
/*
coding at 12:51 - bad idea

 */
int find(string arr[], int len, string seek)
{
    for (int i = 0; i < len; ++i)
    {
        if (arr[i] == seek) return i;
    }
    cout << "find success\n";
    return -1;
}

int main()
{
    fstream stream;
    stream.open("gift1.in", ios::in);
    int numpeople;
    stream >> numpeople;

    int accounts[numpeople];
    string people[numpeople];
    for (int i = 0; i < numpeople; i++)
        accounts[i] = 0;
    string input;
    for (int i = 0; i < numpeople; i++)
    {
        stream >> input;
        people[i] = input;
    }
    cout << "setup finished";
    int money = 0;
    int distnum = 0;
    int remainder = 0;
    string receiver = "";
    string sender = "";
    int p = 0;
    /*
      Actual algorithm:
      for all the people read in the first number to determine how many more lines to read (distnum, I think). next, if distnum == 0 remainder is 0. for the next few lines, read in the receiver's name. give them money/distnum number of money, since they are sharing it equally.
     */
    for (int i = 0; i < numpeople; i++)
    {
        stream >> sender >> money >> distnum;
        if (distnum == 0) 
        {
            remainder = 0;
            accounts[find(people, numpeople, sender)] += money;
        }
        else 
        { 
            remainder = money % distnum;
            accounts[find(people, numpeople, sender)] += remainder - money;
        }
        for (int j = 0; j < distnum; j++)
        {
            stream >> receiver;
            p = find(people, numpeople, receiver);
            if (distnum != 0) accounts[p] += int(money / distnum);
        }
    }
    stream.close();
    cout << "reading over" << endl;
    stream.open("gift1.out", ios::out);
    for (int i = 0; i < numpeople; i++)
        stream << people[i] << " " << accounts[i] << endl;
    cout << "end" << endl;
    return 0;
}
