/*
PROB: dualpal
ID: andrewy3
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;

string convertInt(int);
string convertBase(int, int);
bool isPalindromic(string);

int main()
{
    ifstream fin("dualpal.in");
    ofstream fout("dualpal.out");
    
    int n, s;
    fin >> n >> s;

    int palcount = 0;
    int numcount = 0;
    while (numcount < n)
    {
        s++;
        for (int i = 2; i <= 10; i++)
            if (isPalindromic(convertBase(s, i)))
                palcount++;
        if (palcount >= 2)
        {
            fout << s << endl;
            numcount++;
        }
        palcount = 0;
    }
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

string convertInt(int number)
{
    stringstream ss;//create a stringstream
    ss << number;//add number to the stream
    return ss.str();//return a string with the contents of the stream
}

bool isPalindromic(string s)
{
    int length = s.length();
    for (int i = 0; i < length; i++)
    {
        if (!(s[i] == s[length - i - 1]))
            return false;
    }
    return true;
}

