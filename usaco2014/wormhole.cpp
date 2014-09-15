#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
/*
  int detPairs(vector<Point>& points, int* a, int size, int i, int n)
  {
  for (a[i] = 0; a[i] < size; a[i]++)
  {
//        if (i == n-1)
}
}
*/

class Point {
public:
    int x;
    int y;
    //int xrating;
    //int yrating;
    //Point (int x1, int y1, int x2, int y2) {x = x1; y = y1; xrating = x2; yrating = y2;}
    Point (int x1, int y1) {x = x1; y = y1;}
};

int main()
{
    fstream stream;
    stream.open("wormhole.in", ios::in);
    int n = 0; 
    stream >> n;
    vector<Point> points;
    int x, y;
    for (int i = 0; i < n; i++)
    {
        stream >> x >> y;
        Point p(x, y);
        points.push_back(p);
    }
    bool teleport = false;
    vector<Point> currentloop;
    Point pos(points[0].x, points[0].y);
    for (int i = 0; i < points.size(); i++)
    {
        pos.x++;
        while (pos.x != points[i].x || pos.y != points[i].y)
        {
            for (int j = 0; j < points.size();j++)
            {
                if (pos.x == points[j].x && pos.y == points[j].y)
                {
                    teleport = true;
                    currentloop.push_back(points[j]);
                }
            }
            if (teleport)
            {
                for (int j = 0; j < points.size(); j++)
                {
                    
                }
            }
            teleport = false;
            if (pos.x < 1000) pos.x++;
            else break;
        }
        
        currentloop.clear();
    }
}
