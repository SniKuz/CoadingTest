//Union-Find structure (disjoint-set)

#include <vector>
using namespace std;

vector<int> set;

void init(int e)
{
    for(int i = 0; i < e; i++)
    {
        set.push_back(i++);
    }
}

int find(int n)
{
    if(set[n] < 0) return n;
    set[n] = find(set[n]);
    return set[n];
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if(a==b) return ;
    set[a] += set[b];
    set[b] = a;
}

