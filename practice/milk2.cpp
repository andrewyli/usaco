/*
  ID: andrewy3
  LANG: C++
  PROG: milk2
*/
/*
 *Progress: 6 checks, fails on 7
 *Seems like it's creating ranges that are backwards, and not combining correctly?
 */
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Range
{
    int left;
    int right;
public:
    Range(int, int);
    int getLeft();
    void setLeft(int);
    int getRight();
    void setRight(int);
    vector<Range> consolidateRanges(vector<Range>&);//see comments below
    int size();
};

Range::Range(int a, int b)
{
    left = a;
    right = b;
}

int Range::getLeft()
{
    return left;
}

int Range::getRight()
{
    return right;
}

void Range::setLeft(int a)
{
    left = a;
}

void Range::setRight(int b)
{
    right = b;
}
/*
 * This is supposed to combine ranges as much as possible and get rid of any extra ranges*/
vector<Range> consolidateRanges(vector<Range>& v) 
{
    Range temp(0, 0);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            if (i != j)
            {
                if (v[i].getLeft() <= v[j].getLeft())
                {
                    if (v[i].getRight() >= v[j].getLeft())
                    {
                        if (v[i].getRight() >= v[j].getRight()) //i contains j
                        {
                            v[i] = Range(v[i].getLeft(), v[i].getRight());//fill in action: i's left, i's right
                            v.erase(v.begin() + j);
                            return consolidateRanges(v);
                        }
                        else //overlap middle
                        {
                            v[i] = Range(v[i].getLeft(), v[j].getRight());
                            v.erase(v.begin() + j);
                            return consolidateRanges(v); //fill in action: i's left, j's right
                        }
                    }
                }
                else
                {
                    if (v[j].getRight() >= v[i].getLeft())
                    {
                        if (v[j].getRight() >= v[i].getRight()) //j contains i
                        {
                            v[j] = Range(v[j].getLeft(), v[j].getRight()); //fill in action: j's left, j's right
                            v.erase(v.begin() + i);
                            return consolidateRanges(v);
                        }
                        else //overlap middle
                        {
                            v[j] = Range(v[j].getLeft(), v[i].getRight()); //fill in action: j's left, i's right
                            v.erase(v.begin() + i);
                            return consolidateRanges(v);
                        }
                    }
                }
            }
        }
    }
    return v;
}

int Range::size()
{
    return right - left;
}

int main()
{
    cout << "Program started." << endl;
    vector<Range> ranges;
    fstream stream;
    stream.open("milk2.in", ios::in);
    cout << "Stream opened." << endl;
    int cowcount = 0;
    stream >> cowcount;

    int holder1 = 0;
    int holder2 = 0;
    for (int i = 0; i < cowcount; i++)
    {
        stream >> holder1; stream >> holder2;
        ranges.push_back(Range(holder1, holder2));
    }
    cout << "Data input." << endl;
    ranges = consolidateRanges(ranges);
    cout << "Stuff consolidated." << endl;
    int maximumidle = 0;
    Range temp(0, 0);
    for (int i = 1; i < ranges.size(); i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (ranges[j].getLeft() < ranges[j - 1].getLeft())
            {
                temp = ranges[j];
                ranges[j] = ranges[j - 1];
                ranges[j - 1] = temp;
            }
        }
    }
    cout << "Stuff sorted." << endl;
    stream.close();
    stream.open("milk2.out", ios::out);
    int maximummilk = 0;
    for (int i = 0; i < ranges.size(); i++)
    {
        if (maximummilk < ranges[i].size()) maximummilk = ranges[i].size();
        if (i != 0 & maximumidle < ranges[i].getLeft() - ranges[i - 1].getRight())
            maximumidle = ranges[i].getLeft() - ranges[i - 1].getRight();
    }
    cout << "Stuff written" << endl;
    stream << maximummilk << " " << maximumidle << endl;
    cout << "Done." << endl;
    return 0;
}


