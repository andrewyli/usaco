/*
  PROB: ariprog
  ID: andrewy3
  LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <time.h>
struct Pair
{
    int a;
    int b;
};

int e_pow(int a, int b)
{
    int n = 1;
    for (int i = 0; i < b; i++)
    {
        n *= a;
    }
    return n;
}

bool p_comp(Pair p, Pair q)
{
    if (p.b < q.b)
        return true;
    else if (p.b > q.b)
        return false;
    else
    {
        return p.a < q.a;
    }
}

std::vector<Pair> find_seq(std::vector<int>& lst, int n)
{
    std::vector<Pair> out;
    for (int i = 0; i < lst.size() - n + 1; i++)
    {
        for (int j = i + 1; j < lst.size(); j++)
        {
            int a = lst[i];
            int b = lst[j] - lst[i];
            int k = 0;
            while (k < n - 1)
            {
                if (!std::binary_search(lst.begin() + k, lst.end(), a + (k + 1) * b))
                    break;
                k++;
            }
            if (k == n - 1)
            {
                Pair p;
                p.a = a;
                p.b = b;
                out.push_back(p);
            }
        }
    }
    return out;
}

int main()
{
    std::ifstream fin("ariprog.in");
    std::ofstream fout("ariprog.out");
    
    int n, m;
    fin >> n >> m;

    std::vector<int> bisquares((m + 1) * (m + 2) / 2);

    int count = 0;
    for (int i = 0; i <= m; i++)
        for (int j = i; j <= m; j++)
        {
            bisquares[count] = e_pow(i, 2) + e_pow(j, 2);
            count++;
        }
    std::sort(bisquares.begin(), bisquares.end());
    std::vector<int>::iterator it;
    it = std::unique(bisquares.begin(), bisquares.end());
    bisquares.resize(std::distance(bisquares.begin(), it));
    std::vector<Pair> pairs = find_seq(bisquares, n);
    std::sort(pairs.begin(), pairs.end(), p_comp);
    if (pairs.size() == 0)
        fout << "NONE" << '\n';
    else
    {
        for (int i = 0; i < pairs.size(); i++)
        {
            std::cout << pairs[i].a << ' ' << pairs[i].b << '\n';
            fout << pairs[i].a << ' ' << pairs[i].b << '\n';
        }
    }
    return 0;
}
