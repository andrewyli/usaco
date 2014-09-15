/**
 *Problem not completed- got about half right
 *Should use a wall-following algorithm.
 */
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    int field[100][100];
    for (int i = 0; i < 10000; i++)
    {
        field[i / 100][i % 100] = 0;
    }
    fstream stream;
    stream.open("perimeter.in", ios::in);
    int n = 0;
    stream >> n;

    int xc = 0;
    int yc = 0;
    for (int i = 0; i < n; i++)
    {
        stream >> xc >> yc;
        field[xc - 1][yc - 1] = 1;
    }
    int ncount = 0;
    int totalcount = 0;
    vector<int> empties;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            ncount = 4;
            if (field[i][j] == 1)
            {
                if (i > 0)
                {
                    if (field[i - 1][j] == 1)
                        ncount--;
                }
                if (i < 99)
                {
                    if (field[i + 1][j] == 1)
                        ncount--;
                }
                if (j > 0)
                {
                    if (field[i][j - 1] == 1)
                        ncount--;
                }
                if (j < 99)
                {
                    if (field[i][j + 1] == 1)
                        ncount--;
                }
                totalcount += ncount;
            }
            else
            {
                if (i > 0 && i < 99 && j > 0 && j < 99)
                {
                    if (field[i - 1][j] == 1 && field[i + 1][j] == 1 && field[i][j - 1] == 1 && field[i][j + 1] == 1)
                        totalcount -= 4;
                }
            }
        }
    }
    stream.close();
    stream.open("perimeter.out", ios::out);
    stream << totalcount << endl;
    stream.close();
    return 0;
}
