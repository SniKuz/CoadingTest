#include <bits/stdc++.h>
#define h first
#define node second
#define pii pair<int, int>

using namespace std;

int n, m;
vector<int> heights(5001);
priority_queue<pii> pqH;
vector<vector<int>> board(5001);
vector<int> dist(5001, 0);

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> heights[i];
        pqH.push({heights[i], i});
    }
    for(int i = 0;  i < m; i++)
    {
        int s, e;
        cin >> s >> e;
        board[s].push_back(e);
        board[e].push_back(s);
    }
    
    while(pqH.empty() == false)
    {
        auto cur = pqH.top(); pqH.pop();
        if(dist[cur.node] != 0)
            continue;
        
        dist[cur.node] = 1;
        queue<pair<int, pii>> q;
        q.push({1, cur});
        
        while(q.empty() == false)
        {
            auto cur = q.front(); q.pop();
            
            for(const auto& next : board[cur.second.node])
            {
                if(heights[next] < cur.second.h)
                {
                    if(dist[next] < cur.first + 1)
                    {
                        dist[next] = cur.first+1;
                        q.push({dist[next], {heights[next], next}});
                    }
                }
            }
        }
    }
    
    for(int i = 1; i <= n; i++)
    {
        cout << dist[i] << '\n';
    }
    return 0;
}
/*
각 쉽터의 높이는 고유
*/