/**
 *Feb 2013, Silver #2
 */
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point 
{
    int x;
    int y;
};
class Region 
{
    int id, size;
    vector<Region> borders;
    vector<Point> points;
public:
    int getID() {return id;}
    void setID(int i) {id = i;}
    int getSize() {return size;}
    void setSize(int s) {size = s;}
    vector<Region> getBorders() {return borders;}
    void addBorder(Region b) {borders.push_back(b);}
    vector<Point> getPoints() {return points;}
    void addPoint(Point p) {points.push_back(p);}
};

int main()
{
    vector<int> types;
    vector<Region> regions;
    vector<Pairing> pairings;
    fstream stream;
    stream.open("tractor.in", ios::in);
    int n = 0;
    stream >> n;
    
    int field[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            stream >> field[i][j];
            if(find(types.begin(), types.end(), field[i][j]) == types.end())
                types.push_back(field[i][j]);
        }
    }
    Region a;
    for (int i = 0; i < types.size(); i++)
    {
        a.setID(types[i]);
        a.setSize(0);
        regions.push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < regions.size(); k++)
            {
                if (field[i][j] = regions[k].getID())
                {
                    regions[k].setSize(regions[k].getSize() + 1);
                    regions[k].addBlock(field[i][j]);
                }
            }
        }
    }
    
    stream.close();
    
    return 0;
}
