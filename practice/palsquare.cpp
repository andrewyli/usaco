/*
ID: andrewy3
TASK: palsquare
LANG: C++
*/
#include <cmath>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

string convertInt(int number)
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

bool isPalindromic(string s)
{
    for (int i = 0; i < s.length()/2; i++)
    {
        if (!(s[i] == s[s.length() - i - 1]))
            return false;
    }
    return true;
}
string convertBase(int n, int b)
{
    string result = ""; //the final product of the function
    int dividend = 0; //each digit
    int power = (int)(log(n) / log(b)); //max power of b that fits
    for (int i = power; i >= 0; i--)
    {
        dividend = (int) (n / pow(b, i));
        if (dividend <= 9)
            result += convertInt(dividend);
        else
        {
            char c = dividend + 55;
            result += c;
        }
        n -= dividend * pow(b, i);
    }
    return result;
}

int main()
{
    ifstream fin("palsquare.in");
    ofstream fout("palsquare.out");

    int base;
    fin >> base;

    for (int i = 1; i <= 300; i++)
    {
        if (isPalindromic(convertBase(i*i, base)))
            fout << convertBase(i, base) << " " << convertBase(i*i, base) << endl;
    }
    fin.close();
    fout.close();
}
