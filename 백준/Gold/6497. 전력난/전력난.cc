#include <bits/stdc++.h>

#define pipii pair<unsigned int, pair<unsigned int,unsigned int>>
#define cost first
#define node second

using namespace std;

int n, e;
priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
vector<int> parents(200001, -1);
unsigned int total = 0;
unsigned int res = 0;

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

void Init()
{
    total = 0;
    res = 0;
    fill(parents.begin(), parents.end(), -1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> e;
    while(n != 0 && e != 0)
    {
        Init();
        for(int i = 0; i < e; i++)
        {
            int n1, n2, c;
            cin >> n1 >> n2 >> c;
            pq.push({c, {n1, n2}});
            total += c;
        }

        while(!pq.empty())
        {
            auto cur = pq.top(); pq.pop();
            if(Find(cur.node.first) != Find(cur.node.second))
            {
                MakeUnion(cur.node.first, cur.node.second);
                res += cur.cost;
            }
        }
        cout << total - res << '\n';
        cin >> n >> e;
    }
}