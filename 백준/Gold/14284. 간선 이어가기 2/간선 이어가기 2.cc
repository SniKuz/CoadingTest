#include <bits/stdc++.h>
#define cost first
#define node second
#define pii pair<int, int>
#define pipii pair<int, pii>

using namespace std;

int n, m;
vector<vector<pii>> v(5001);
priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
vector<int> dist(5001, INT_MAX);
int s, t;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({c, b});
        v[b].push_back({c, a});
    }
    cin >> s >> t;
    dist[s] = 0;
    pq.push({0, {s, s}});
    while(pq.empty() == false)
    {
        auto cur = pq.top(); pq.pop();
        
        for(const auto &e : v[cur.node.second])
        {
            if(dist[cur.node.second] != INT_MAX && dist[e.node] > dist[cur.node.second] + e.cost)
            {
                dist[e.node] = dist[cur.node.second] + e.cost;
                pq.push({dist[e.node], {cur.node.second, e.node}});
            }
        }
    }
    cout << dist[t];
    return 0;
}
