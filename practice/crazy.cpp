#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Point
{
    int x;
    int y;
    bool occ;
public:
    Point() {x = 0; y = 0;}
    Point(int a1, int b1) {x = a1; y = b1;}
    int getX() {return x;}
    int getY() {return y;}
    bool getOcc() {return occ;}
    void setX(int x1) {x = x1;}
    void setY(int y1) {y = y1;}
    void setOcc(bool b) {occ = b;}
};

class Fence
{
    Point a;
    Point b;
    double slope;
public:
    Fence(Point a1, Point b1, double s) {a = a1; b = b1; s = slope;}
    Point getA() {return a;}
    Point getB() {return b;}
    double getSlope() {return slope;}
    void setA(Point a1) {a = a1;}
    void setB(Point b1) {b = b1;}
    void setSlope(double s) {slope = s;}
};

class Grid
{
    vector<Fence> fences;
    vector<Point> cows;
public:
    Grid(vector<Fence> f, vector<Point> p) {fences = f; cows = p;}
    vector<Point> getCows() {return cows;}
    void setCows(vector<Point> a1) {cows = a1;}
    vector<Fence> getFences() {return fences;}
    void setFences(vector<Fence> f) {fences = f;}
};
int main()
{
    vector<Fence> fences;
    vector<Point> points;

    fstream stream;
    stream.open("crazy.in", ios::in);
    int n, c;
    stream >> n >> c;
    
    int x1 = 0;
    int y1 = 0; 
    int x2 = 0; 
    int y2 = 0;
    for (int i = 0; i < n; i++)
    {
        stream >> x1 >> y1 >> x2 >> y2;
        Point p(x1, y1);
        Point q(x2, y2);
        Fence f(p, q, (double)(y2-y1)/(x2-x1));
        fences.push_back(f);
        cout << "Slope: " << f.getSlope() << endl;
    }
    for (int i = 0; i < c; i++)
    {
        stream >> x1 >> y1;
        Point p(x1, y1);
        points.push_back(p);
    }
    Grid g(fences, points);
    return 0;
}
