#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("mirror.in");
    ofstream fout("mirror.out");
    
    int n, m;
    fin >> n >> m;
    
    char field[n][m];
    bool visited[n][m];
    char buffer;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            fin >> buffer;
            field[i][j] = buffer;
            visited[i][j] = false;
            ////cout << field[i][j];
        }
        ////cout << "\n";
    }
    
    int direction = 2; //0 is up, 1 is right, 2 is down, 3 is left
    int xindex = 0; //up to down
    int yindex = 0; //left to right
    int maxlen = 0;
    int currentlen = 0; //for each trial
    for (int i = 0; i < m; i++) //loop: from the top
    {
        xindex = 0;
        yindex = i;
        direction = 2;
        while (xindex >= 0 && xindex < n && yindex >= 0 && yindex < m)
        {
            //cout << xindex << ", " << yindex << "\n";
            visited[xindex][yindex] = true;
            if (field[xindex][yindex] == '/')
            {
                if (direction == 0)
                {
                    direction = 1;
                    yindex++;
                }
                else if (direction == 1)
                {
                    direction = 0;
                    xindex--;
                }
                else if (direction == 2)
                {
                    direction = 3;
                    yindex--;
                }
                else if (direction == 3)
                {
                    direction = 2;
                    xindex++;
                }
                else
                {
                    //cout << "error: direction.";
                }
            }
            else //if it's "\"
            {
                if (direction == 0)
                {
                    direction = 3;
                    yindex--;
                }
                else if (direction == 1)
                {
                    direction = 2;
                    xindex++;
                }
                else if (direction == 2)
                {
                    direction = 1;
                    yindex++;
                }
                else if (direction == 3)
                {
                    direction = 0;
                    xindex--;
                }
                else
                {
                    //cout << "error: direction.";
                }
            }
            if (visited[xindex][yindex] == false) currentlen++;
        }
        if (maxlen < currentlen)
        {
            maxlen = currentlen;
        }
        currentlen = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = false;
        }
    }
    for (int i = 0; i < n; i++) //from the left
    {
        xindex = i;
        yindex = 0;
        direction = 1;
        while (xindex >= 0 && xindex < n && yindex >= 0 && yindex < m)
        {
            visited[xindex][yindex] = true;
            //cout << xindex << ", " << yindex << "\n";
            if (field[xindex][yindex] == '/')
            {
                if (direction == 0)
                {
                    direction = 1;
                    yindex++;
                }
                else if (direction == 1)
                {
                    direction = 0;
                    xindex--;
                }
                else if (direction == 2)
                {
                    direction = 3;
                    yindex--;
                }
                else if (direction == 3)
                {
                    direction = 2;
                    xindex++;
                }
                else
                {
                    //cout << "error: direction.";
                }
            }
            else //if it's "\"
            {
                if (direction == 0)
                {
                    direction = 3;
                    yindex--;
                }
                else if (direction == 1)
                {
                    direction = 2;
                    xindex++;
                }
                else if (direction == 2)
                {
                    direction = 1;
                    yindex++;
                }
                else if (direction == 3)
                {
                    direction = 0;
                    xindex--;
                }
                else
                {
                    //cout << "error: direction.";
                }
            }
            if (visited[xindex][yindex] == false) currentlen++;
        }
        if (maxlen < currentlen)
        {
            maxlen = currentlen;
        }
        currentlen = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = false;
        }
    }
    for (int i = 0; i < m; i++) //from the bottom
    {
        xindex = n - 1;
        yindex = m - i - 1;
        direction = 0;
        while (xindex >= 0 && xindex < n && yindex >= 0 && yindex < m)
        {
            visited[xindex][yindex] = true;

            //cout << xindex << ", " << yindex << "\n";
            if (field[xindex][yindex] == '/')
            {
                if (direction == 0)
                {
                    direction = 1;
                    yindex++;
                }
                else if (direction == 1)
                {
                    direction = 0;
                    xindex--;
                }
                else if (direction == 2)
                {
                    direction = 3;
                    yindex--;
                }
                else if (direction == 3)
                {
                    direction = 2;
                    xindex++;
                }
                else
                {
                    //cout << "error: direction.";
                }
            }
            else //if it's "\"
            {
                if (direction == 0)
                {
                    direction = 3;
                    yindex--;
                }
                else if (direction == 1)
                {
                    direction = 2;
                    xindex++;
                }
                else if (direction == 2)
                {
                    direction = 1;
                    yindex++;
                }
                else if (direction == 3)
                {
                    direction = 0;
                    xindex--;
                }
                else
                {
                    //cout << "error: direction.";
                }
            }
            if (visited[xindex][yindex] == false) currentlen++;
        }
        if (maxlen < currentlen)
        {
            maxlen = currentlen;
        }
        currentlen = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = false;
        }
    }
    for (int i = 0; i < n; i++) //from the right
    {
        xindex = n - i - 1;
        yindex = m - 1;
        direction = 3;
        while (xindex >= 0 && xindex < n && yindex >= 0 && yindex < m)
        {
            visited[xindex][yindex] = true;
            //cout << xindex << ", " << yindex << "\n";
            if (field[xindex][yindex] == '/')
            {
                if (direction == 0)
                {
                    direction = 1;
                    yindex++;
                }
                else if (direction == 1)
                {
                    direction = 0;
                    xindex--;
                }
                else if (direction == 2)
                {
                    direction = 3;
                    yindex--;
                }
                else if (direction == 3)
                {
                    direction = 2;
                    xindex++;
                }
                else
                {
                    //cout << "error: direction.";
                }
            }
            else //if it's "\"
            {
                if (direction == 0)
                {
                    direction = 3;
                    yindex--;
                }
                else if (direction == 1)
                {
                    direction = 2;
                    xindex++;
                }
                else if (direction == 2)
                {
                    direction = 1;
                    yindex++;
                }
                else if (direction == 3)
                {
                    direction = 0;
                    xindex--;
                }
                else
                {
                    //cout << "error: direction.";
                }
            }
            if (visited[xindex][yindex] == false) currentlen++;
        }
        if (maxlen < currentlen)
        {
            maxlen = currentlen;
        }
        currentlen = 0;
    }

    fout << maxlen << "\n";
}
