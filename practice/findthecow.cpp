#include<string>
#include<fstream>
#include<iostream>
#include<vector>
using namespace std;

bool leftleg(string, int);
bool rightleg(string, int);

int main()
{
    int total = 0;

    fstream stream;
    stream.open("cowfind.in", ios::in);
    string input;
    stream >> input;
    //that was input

    vector<int> lefts;
    for (int i = 0; i < input.length() - 1; i++)
        if (leftleg(input, i)) lefts.push_back(i);

    vector<int> rights;
    for (int i = 0; i < input.length() - 1; i++)
        if (rightleg(input, i)) rights.push_back(i);

    for (int i = 0; i < lefts.size(); i++)
        for (int j = 0; j < rights.size(); j++)
            if (lefts[i] < rights[j]) total++;

    stream.close();
    stream.open("cowfind.out", ios::out);
    stream << total << endl;
}

bool leftleg(string s, int x)
{
    return (s.at(x) == '(' && s.at(x + 1) == '(')?true:false;
}

bool rightleg(string s, int x)
{
    return (s.at(x) == ')' && s.at(x + 1) == ')')?true:false;
}
