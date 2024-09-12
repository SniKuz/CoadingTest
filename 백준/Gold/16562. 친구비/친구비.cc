#include <bits/stdc++.h>
#define FAIL "Oh no"
#define cost first
#define friend second

using namespace std;

int n, m, k;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<int> parents(10001, -1);
vector<int> friends(10001);
int res = 0;

int Find(int a)
{
    if(parents[a] < 0) return a;
    return parents[a] = Find(parents[a]);
}

void MakeFriend(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if(a == b) return;
    parents[a] += parents[b];
    parents[b] = a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
    {
        int cost;
        cin >> cost;
        pq.push({cost, i});
    }
    for(int i = 0; i < m; i++)
    {
        int f1, f2;
        cin >> f1 >> f2;
        MakeFriend(f1, f2);
    }
    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        int friendGroup = Find(cur.friend);
        if(friends[friendGroup] == 0) //not friend
        {
            friends[friendGroup] = 1;
            res += cur.cost;
        }
    }
    if(res > k)
        cout << FAIL;
    else
        cout << res;
}