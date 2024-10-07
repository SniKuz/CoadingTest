#include <bits/stdc++.h>
#define pipii pair<int, pair<int, int>>

using namespace std;

int v, e;
priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
vector<int> parents(10001, -1);
int res = 0;

int Find(int x)
{
    if(parents[x] < 0) return x;
    return parents[x] = Find(parents[x]);
}

void MakeUnion(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if(x == y) return;
    parents[x] += parents[y];
    parents[y] = x;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> v >> e;
    for(int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({c, {a, b}});
    }
    
    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        if(Find(cur.second.first) == Find(cur.second.second))
            continue;
        MakeUnion(cur.second.first, cur.second.second);
        res += cur.first;
    }
    cout << res;
}