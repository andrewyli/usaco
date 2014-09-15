#include<string>
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

bool balanced(string);
int lor(string);
string swap(string, int);

int main()
{
    int total;

    fstream stream;
    stream.open("typo.in", ios::in);
    string input;
    stream >> input;
    //input is over

    string temp;
    int count = 0;
    bool prefix = true;
    for (int i = 0; i < input.length(); i++)
    {
        temp = input;
        if (temp[i] == '(') temp[i] = ')';
        else temp[i] = '(';
        
        for (int j = 0; j < temp.length(); j++)
        {
            if (temp[j] == '(') count++;
            else count--;
        }
        int count2;        
        for (int j = 0; j < temp.length(); j++)
        {
            for (int k = 0; k <= j; k++)
            {
                if (temp.at(k) == '(') count2++;
                else count2--;
            }
            if (count2 >= 0) prefix = true;
            else prefix = false;
        }
        if (prefix == 0 && count == 0) total++;
    }
    stream.close();
    stream.open("typo.out", ios::out);
    stream << total << endl;
    return 0;
}

int lor(string s)
{
    int count;
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == '(') count++;
        else if (s.at(i) == ')') count--;
    }
    return count;
}

bool balanced(string s)
{
    bool equal = true;
    if (lor(s) == 0)
        equal = true;
    else
        return false;
    for (int i = 0; i < s.size(); i++)
        if (lor(s.substr(0, i + 1)) < 0) return false;
    return true;
}

string swap (string s, int x)
{
    if (s[x] == '(') s[x] = ')';
    else s[x] = '(';
    return s;
}
