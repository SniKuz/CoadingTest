#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, m, s, e;
vector<vector<pair<ll, ll>>> board(100001);
vector<ll> dist(100001, 0);

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> s >> e;
    for(int i = 0; i < m; i++)
    {
        ll h1, h2, k;
        cin >> h1 >> h2 >> k;
        board[h1].push_back({k,h2});
        board[h2].push_back({k,h1});
    }
    
    priority_queue<pair<ll, ll>> pq;
    pq.push({LLONG_MAX, s});
    dist[s] = LLONG_MAX;
    
    while(pq.empty() == false)
    {
        auto cur = pq.top(); pq.pop();
        if(cur.second == e)
        {
            cout << cur.first;
            return 0;
        }
        
        for(const auto& next : board[cur.second])
        {
            ll cost = min(cur.first, next.first);
            if(dist[next.second] < cost)
            {
                dist[next.second] = cost;
                pq.push({cost, next.second});
            }
        }
    }
    
    cout << 0;
    return 0;
}
