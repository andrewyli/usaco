/*
ID: andrewy3
LANG: C++
PROB: transform
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    bool isOne = true;
    bool isTwo = true;
    bool isThree = true;
    bool isFour = true;
    bool isFiveOne = true;
    bool isFiveTwo = true;
    bool isFiveThree = true;
    bool isSix = true;
    fstream stream;
    stream.open("transform.in", ios::in);
    int n = 0;
    stream >> n;

    char square[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            stream >> square[i][j];
            //cout << square[i][j];
        }
    }
    //cout << endl;
    char image[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            stream >> image[i][j];
            //cout << image[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!(square[i][j] == image[j][n - i - 1]))
            {
                isOne = false;
            }
            if (!(square[i][j] == image[n - i - 1][n - j - 1]))
            {
                isTwo = false;
            }
            if (!(square[i][j] == image[n - j - 1][i]))
            {
                isThree = false;
            }
            if (!(square[i][j] == image[i][n - j - 1]))
            {
                isFour = false;
            }
            if (!(square[i][j] == image[j][i]))
            {
                isFiveOne = false;
            }
            if (!(square[i][j] == image[n - i - 1][j]))
            {
                isFiveTwo = false;
            }
            if (!(square[i][j] == image[n - j - 1][n - i - 1]))
            {
                isFiveThree = false;
            }
            if (!(square[i][j] == image[i][j]))
            {
                isSix = false;
            }
            //cout << square[i][j] << ", " << image[j][n - i - 1] << endl;
        }
    }
    stream.close();
    stream.open("transform.out", ios::out);
    if (isOne)
    {
        stream << "1" << endl;
    }
    else if (isTwo)
    {
        stream << "2" << endl;
    }
    else if (isThree)
    {
        stream << "3" << endl;
    }
    else if (isFour)
    {
        stream << "4" << endl;
    }
    else if (isFiveOne || isFiveTwo || isFiveThree)
    {
        stream << "5" << endl;
    }
    else if (isSix)
    {
        stream << "6" << endl;
    }
    else 
    {
        stream << "7" << endl;
    }
}
