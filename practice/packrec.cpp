/*
  ID: andrewy3
  PROB: packrec
  LANG: C++
*/


#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>
using namespace std;

struct Rect
{
    int length;
    int width;
};

Rect flip(Rect a, int n)
{
    if (n == 1)
    {
        int temp = a.length;
        a.length = a.width;
        a.width = temp;
    }
    return a;
}

bool rect_comp(Rect a, Rect b)
{
    return (a.length * a.width < b.length * b.width);
}

int area(Rect a)
{
    return a.length * a.width;
}

void calc_1(Rect rects[], vector<Rect>& result_1)
{
    int curr_area = 0;
    do
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    for (int l = 0; l < 2; l++)
                    {
                        Rect curr_rect;
                        curr_rect.length = (flip(rects[0], i).length + flip(rects[1], j).length + flip(rects[2], k).length + flip(rects[3], l).length);
                        curr_rect.width = max(max(flip(rects[0], i).width, flip(rects[1], j).width), max(flip(rects[2], k).width, flip(rects[3], l).width));
                        curr_area = area(curr_rect);
                        if (result_1.size() == 0)
                            result_1.push_back(curr_rect);
                        else if (curr_area < area(result_1[0]))
                        {
                            result_1.clear();
                            result_1.push_back(curr_rect);
                        }                            
                        else if (curr_area <= area(result_1[0]))
                            result_1.push_back(curr_rect);
                    }
                }
            }
        }
    } while (next_permutation(rects, rects + 4, rect_comp));
    return;
}

void calc_2(Rect rects[], vector<Rect>& result_2)
{
    int curr_area = 0;
    do
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    for (int l = 0; l < 2; l++)
                    {
                        Rect curr_rect;
                        curr_rect.length = max(flip(rects[0], i).length + flip(rects[1], j).length + flip(rects[2], k).length, flip(rects[3], l).length);
                        curr_rect.width = max(max(flip(rects[0], i).width, flip(rects[1], j).width), flip(rects[2], k).width) + flip(rects[3], l).width;
                        curr_area = area(curr_rect);
                        if (result_2.size() == 0)
                            result_2.push_back(curr_rect);
                        else if (curr_area < area(result_2[0]))
                        {
                            result_2.clear();
                            result_2.push_back(curr_rect);
                        }                            
                        else if (curr_area <= area(result_2[0]))
                            result_2.push_back(curr_rect);
                    }
                }
            }
        }
    } while (next_permutation(rects, rects + 4, rect_comp));
    return;
}

void calc_3(Rect rects[], vector<Rect>& result_3)
{
    int curr_area = 0;
    do
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    for (int l = 0; l < 2; l++)
                    {
                        Rect curr_rect;
                        curr_rect.length = max(flip(rects[0], i).length + flip(rects[1], j).length, flip(rects[2], k).length) + flip(rects[3], l).length;
                        curr_rect.width = max(max(flip(rects[0], i).width, flip(rects[1], j).width) + flip(rects[2], k).width, flip(rects[3], l).width);
                        curr_area = area(curr_rect);
                        if (result_3.size() == 0)
                            result_3.push_back(curr_rect);
                        else if (curr_area < area(result_3[0]))
                        {
                            result_3.clear();
                            result_3.push_back(curr_rect);
                        }                            
                        else if (curr_area <= area(result_3[0]))
                            result_3.push_back(curr_rect);
                        cout << curr_rect.length << ", " << curr_rect.width << ", " << curr_area << '\n';
                    }
                }
            }
        }
    } while (next_permutation(rects, rects + 4, rect_comp));
    return;
}

void calc_4(Rect rects[], vector<Rect>& result_4)
{
    int curr_area = 0;
    do
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    for (int l = 0; l < 2; l++)
                    {
                        Rect curr_rect;
                        curr_rect.length = flip(rects[0], i).length + max(flip(rects[1], j).length, flip(rects[2], k).length) + flip(rects[3], l).length;
                        curr_rect.width = max(max(flip(rects[0], i).width, flip(rects[1], j).width + flip(rects[2], k).width), flip(rects[3], l).width);
                        curr_area = area(curr_rect);
                        if (result_4.size() == 0)
                            result_4.push_back(curr_rect);
                        else if (curr_area < area(result_4[0]))
                        {
                            result_4.clear();
                            result_4.push_back(curr_rect);
                        }                            
                        else if (curr_area <= area(result_4[0]))
                            result_4.push_back(curr_rect);
                    }
                }
            }
        }
    } while (next_permutation(rects, rects + 4, rect_comp));
    return;
}

void calc_5(Rect rects[], vector<Rect>& result_5)
{
    int curr_area = 0;
    do
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    for (int l = 0; l < 2; l++)
                    {
                        Rect curr_rect;
                        curr_rect.length = max(flip(rects[0], i).length, flip(rects[1], j).length) + flip(rects[2], k).length + flip(rects[3], l).length;
                        curr_rect.width = max(max(flip(rects[2], k).width, flip(rects[3], l).width), flip(rects[0], i).width + flip(rects[1], j).width);
                        curr_area = area(curr_rect);
                        if (result_5.size() == 0)
                            result_5.push_back(curr_rect);
                        else if (curr_area < area(result_5[0]))
                        {
                            result_5.clear();
                            result_5.push_back(curr_rect);
                        }                            
                        else if (curr_area <= area(result_5[0]))
                            result_5.push_back(curr_rect);
                    }
                }
            }
        }
    } while (next_permutation(rects, rects + 4, rect_comp));
    return;
}

void calc_6(Rect rects[], vector<Rect>& result_6)
{
    int curr_area = 0;
    do
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    for (int l = 0; l < 2; l++)
                    {
                        Rect curr_rect;
                        if (flip(rects[3], l).width >= flip(rects[0], i).width + flip(rects[1], j).width)
                        {
                            curr_rect.length = max(max(flip(rects[3], l).length + flip(rects[0], i).length, flip(rects[3], l).length + flip(rects[1], j).length), flip(rects[2], k).length);
                            curr_rect.width = flip(rects[3], l).width + flip(rects[2], k).width;
                        }
                        else if (flip(rects[3], l).width >= flip(rects[1], j).width)
                        {
                            curr_rect.length = max(max(flip(rects[1], j).length + flip(rects[3], l).length, flip(rects[0], i).length + flip(rects[3], l).length), flip(rects[2], k).length + flip(rects[0], i).length);
                            curr_rect.width = max(flip(rects[0], i).width + flip(rects[1], j).width, flip(rects[2], k).width + flip(rects[3], l).width);
                        }
                        else if (flip(rects[1], j).width <= flip(rects[2], k).width + flip(rects[3], l).width)
                        {
                            curr_rect.length = max(max(flip(rects[1], j).length + flip(rects[3], l).length, flip(rects[1], j).length + flip(rects[2], k).length), flip(rects[2], k).length + flip(rects[0], i).length);
                            curr_rect.width = max(flip(rects[0], i).width + flip(rects[1], j).width, flip(rects[2], k).width + flip(rects[3], l).width);
                        }
                        else
                        {
                            curr_rect.width = flip(rects[1], j).width + flip(rects[0], i).width;
                            curr_rect.length = max(max(flip(rects[0], i).length, flip(rects[1], j).length + flip(rects[2], k).length), flip(rects[1], j).length + flip(rects[3], l).length);
                        }
                        curr_area = area(curr_rect);
                        if (result_6.size() == 0)
                            result_6.push_back(curr_rect);
                        else if (curr_area < area(result_6[0]))
                        {
                            result_6.clear();
                            result_6.push_back(curr_rect);
                        }                            
                        else if (curr_area <= area(result_6[0]))
                            result_6.push_back(curr_rect);
                    }
                }
            }
        }
    } while (next_permutation(rects, rects + 4, rect_comp));
    return;
}

int main()
{
    ifstream fin("packrec.in");
    ofstream fout("packrec.out");
    
    int x, y;
    Rect rects[4];
    for (int i = 0; i < 4; i++)
    {
        fin >> x >> y;
        Rect a;
        a.length = x;
        a.width = y;
        rects[i] = a;
    }
    
    sort(rects, rects + 4, rect_comp);

    vector<Rect> result_1;
    vector<Rect> result_2;
    vector<Rect> result_3;
    vector<Rect> result_4;
    vector<Rect> result_5;
    vector<Rect> result_6;

    calc_1(rects, result_1);
    calc_2(rects, result_2);
    calc_3(rects, result_3);
    calc_4(rects, result_4);
    calc_5(rects, result_5);
    calc_6(rects, result_6);

    int min_area = INT_MAX;
    for (int i = 0; i < result_1.size(); i++)
    {
        if (min_area > area(result_1[i]))
        {
            min_area = area(result_1[i]);
        }
        if (result_1[i].length > result_1[i].width)
        {
            result_1[i] = flip(result_1[i], 1);
        }
    }
    for (int i = 0; i < result_2.size(); i++)
    {
        if (min_area > area(result_2[i]))
        {
            min_area = area(result_2[i]);
        }
        if (result_2[i].length > result_2[i].width)
        {
            result_2[i] = flip(result_2[i], 1);
        }
    }
    for (int i = 0; i < result_3.size(); i++)
    {
        if (min_area > area(result_3[i]))
        {
            min_area = area(result_3[i]);
        }
        if (result_3[i].length > result_3[i].width)
        {
            result_3[i] = flip(result_3[i], 1);
        }
    }
    for (int i = 0; i < result_4.size(); i++)
    {
        if (min_area > area(result_4[i]))
        {
            min_area = area(result_4[i]);
        }
        if (result_4[i].length > result_4[i].width)
        {
            result_4[i] = flip(result_4[i], 1);
        }
    }
    for (int i = 0; i < result_5.size(); i++)
    {
        if (min_area > area(result_5[i]))
        {
            min_area = area(result_5[i]);
        }
        if (result_5[i].length > result_5[i].width)
        {
            result_5[i] = flip(result_5[i], 1);
        }
    }
    for (int i = 0; i < result_6.size(); i++)
    {
        if (min_area > area(result_6[i]))
        {
            min_area = area(result_6[i]);
        }
        if (result_6[i].length > result_6[i].width)
        {
            result_6[i] = flip(result_6[i], 1);
        }
    }
    cout << min_area << '\n';
    
    vector<int> final_lengths;
    for (int i = 0; i < result_1.size(); i++)
    {
        if (find(final_lengths.begin(), final_lengths.end(), result_1[i].length) == final_lengths.end() && area(result_1[i]) == min_area)
        {
            final_lengths.push_back(result_1[i].length);
            cout << result_1[i].length << ", " << result_1[i].width << ":1\n";
        }
    }
    for (int i = 0; i < result_2.size(); i++)
    {
        if (find(final_lengths.begin(), final_lengths.end(), result_2[i].length) == final_lengths.end() && area(result_2[i]) == min_area)
        {
            final_lengths.push_back(result_2[i].length);
            cout << result_2[i].length << ", " << result_2[i].width << ":2\n";
        }
    }
    for (int i = 0; i < result_3.size(); i++)
    {
        if (find(final_lengths.begin(), final_lengths.end(), result_3[i].length) == final_lengths.end() && area(result_3[i]) == min_area)
        {
            final_lengths.push_back(result_3[i].length);
            cout << result_3[i].length << ", " << result_3[i].width << ":3\n";
        }
    }
    for (int i = 0; i < result_4.size(); i++)
    {
        if (find(final_lengths.begin(), final_lengths.end(), result_4[i].length) == final_lengths.end() && area(result_4[i]) == min_area)
        {
            final_lengths.push_back(result_4[i].length);
            cout << result_4[i].length << ", " << result_4[i].width << ":4\n";
        }
    }
    for (int i = 0; i < result_5.size(); i++)
    {
        if (find(final_lengths.begin(), final_lengths.end(), result_5[i].length) == final_lengths.end() && area(result_5[i]) == min_area)
        {
            final_lengths.push_back(result_5[i].length);
            cout << result_5[i].length << ", " << result_5[i].width << ":5\n";
        }
    }
    for (int i = 0; i < result_6.size(); i++)
    {
        if (find(final_lengths.begin(), final_lengths.end(), result_6[i].length) == final_lengths.end() && area(result_6[i]) == min_area)
        {
            final_lengths.push_back(result_6[i].length);
            cout << result_6[i].length << ", " << result_6[i].width << ":6\n";
        }
    }
    
    for (int i = 0; i < final_lengths.size(); i++)
    {
        cout << final_lengths[i] << '\n';
    }
    
    sort(final_lengths.begin(), final_lengths.end());
    
    fout << min_area << '\n';
    for (int i = 0; i < final_lengths.size(); i++)
    {
        fout << final_lengths[i] << " " << min_area / final_lengths[i] << '\n';
    }
}
