#include <bits/stdc++.h>
#define pii pair<int, int>
#define pipii pair<int, pii>
#define INF 100001
#define ll long long

using namespace std;

int n, m;
vector<int> parents(INF, -1);
ll curPoint = 0, totalPoint = 0;
priority_queue<pipii, vector<pipii>, greater<pipii>> pq;

int Find(int a)
{
    if(parents[a] < 0) return a;
    return parents[a] = Find(parents[a]);
}

bool MakeUnion(int a, int b)
{
    a = Find(a);
    b = Find(b);
    
    if(a == b) return false;
    parents[a] += parents[b];
    parents[b] = a;
    return true;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({c, {a, b}});
        totalPoint += c;
    }
    
    while(pq.empty() == false)
    {
        auto cur = pq.top(); pq.pop();
        if(MakeUnion(cur.second.first, cur.second.second))
        {
            curPoint += cur.first;
        }
    }
    
    if(parents[Find(1)] + n == 0)
        cout << totalPoint - curPoint;
    else
        cout << -1;
    return 0;
}
