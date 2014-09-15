#include <iostream>
#include <fstream>
using namespace std;

bool contains(string a, string b) //a is the whole thing, b is the removed letter string
{
    if (a.substr(0, a.length() - 1) == b || a.substr(1) == b)
        return true;
    else
        return false;
}

int go_backwards(string input)
{
    string a = input.substr(0, input.length() / 2 + 1);
    string b = input.substr(input.length() / 2 + 1);
    string c = input.substr(input.length() / 2);
    string d = input.substr(0, input.length() / 2);
    if (contains(a, b) && contains(c, d)) 
    {
        return 1 + go_backwards(a) + go_backwards(c);
        cout << a << ", " << c << "\n";
    }
    else if (contains(a, b))
    {
        return 1 + go_backwards(a);
        cout << a << "\n";
    }
    else if (contains(c, d))
    {
        return 1 + go_backwards(c);
        cout << c << "\n";
    }
    else
    {
        return 1;
        cout << "1" << "\n";
    }
}

int main()
{
    ifstream fin("scode.in");
    ofstream fout("scode.out");

    string input;
    fin >> input;
/*
    if (contains(input.substr(0, input.length() / 2 + 1), input.substr(input.length() / 2 + 1)))
    {
        cout << "derp";
    }
*/
    fout << go_backwards(input) - 1 << "\n";
}
