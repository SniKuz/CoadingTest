#include <bits/stdc++.h>
#define cost first
#define node second
#define pii pair<int, int>

using namespace std;

int n,e;
vector<vector<pair<int, int>>> board(801); // node, cost
int v1, v2;

int dijkstra(int root, int target)
{
    vector<int> dist(n+1, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[root] = 0;
    pq.push({0, root});
    
    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        
        for(const auto& next : board[cur.node])
        {
            if(dist[next.node] > dist[cur.node] + next.cost)
            {
                dist[next.node] = dist[cur.node] + next.cost;
                pq.push({dist[cur.node] + next.cost, next.node});
            }
        }
    }
    return dist[target];
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> e;
    for(int i = 0; i < e; i++)
    {
        int n1, n2, c;
        cin >> n1 >> n2 >> c;
        board[n1].push_back({c, n2});
        board[n2].push_back({c, n1});
    }
    cin >> v1 >> v2;
    int root2v1 = dijkstra(1, v1);
    int v12v2 = dijkstra(v1, v2);
    int v22n = dijkstra(v2, n);
    if(root2v1 == INT_MAX || v12v2 == INT_MAX || v22n == INT_MAX)
        cout << -1;
    else
        cout << min(root2v1 + v12v2 + v22n,
            dijkstra(1,v2) + dijkstra(v2, v1) + dijkstra(v1, n));
    return 0;
}
