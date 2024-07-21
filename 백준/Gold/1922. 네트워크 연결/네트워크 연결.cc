#include <bits/stdc++.h>

#define cost first
#define nodes second

using namespace std;

int n, m;
int res = 0;

vector<pair<int, pair<int, int>>> network;
vector<int> Group(1001, -1);

int Find(int a)
{
    if(Group[a] < 0) return a;
    return Group[a] = Find(Group[a]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if(a == b) return;
    Group[a] += Group[b];
    Group[b] = a;
}

bool SameGroup(int a, int b)
{
    a = Find(a);
    b = Find(b);
    return a == b;
}


void Input()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int s, e, c;
        cin >> s >> e >> c;
        network.push_back({c, {s, e}});

    }
}

void Solution()
{
    sort(network.begin(), network.end());
    for(int i = 0; i < m; i++)
    {
    }
    for(int i = 0; i < m; i++)
    {
        int c = network[i].cost;
        int s = network[i].nodes.first;
        int e = network[i].nodes.second;
        if(!SameGroup(s, e))
        {
            res += c;
            Union(s, e);
        }
    }
}

int main()
{
    Input();
    Solution();
    cout << res;
}