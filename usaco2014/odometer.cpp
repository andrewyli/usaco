#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

string convert_int(int n)
{
    stringstream ss;
    ss << n;
    return ss.str();
}

int factorial(int n)
{
    int total = 1;
    for (int i = 1; i <= n; i++)
    {
        total *= i;
    }
    return total;
}

int choose(int n, int k)
{
    if (k > n)
        return -1;
    else
        return (factorial(n))/(factorial(k) * factorial(n - k));
}

/*
  n denotes the number of samities, x and y are the inputs from the file.
  power is the number of total digits
*/
int calculate(int n, int power, int x, int y)
{
    int result = 1;
    result *= choose(power, n) * 10;
    return 1;
}

bool works(string s)
{
    int nums[10];
    for (int i = 0; i < 10; i++)
    {
        nums[i] = 0;
    }
    for (int i = 0; i < s.length(); i++)
    {
        nums[atoi(str.c_str())]++;
    }
}

int main()
{
    ifstream fin("odometer.in");
    ofstream fout("odometer.out");
    
    int x, y;
    fin >> x >> y;

    int power = convert_int(y).length();

    for (int i = x; i <= y; i++)
    {
        string s = convert_int(i);
        if (works(i))
            total++;
    }
    fout << total << '\n';

}
