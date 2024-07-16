#include <bits/stdc++.h>

using namespace std;

int n, r0, r1;
vector<vector<pair<int, int>>> board(100001); // node, cost

void solution()
{
    queue< pair<int, pair<int, int>>> q; // node, {cost, maxWeight};
    vector<int> visited(n+1);
    q.push({r0, {0, 0}});
    visited[r0] = true;

    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        if(cur.first == r1)
        {
            cout << cur.second.first - cur.second.second;
            return;
        }

        for(const auto& next : board[cur.first])
        {
            if(visited[next.first])
                continue;
            visited[next.first] = true;
            q.push({next.first, {cur.second.first + next.second, max(cur.second.second, next.second)}});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> r0 >> r1;
    for(int i = 0; i < n-1; i++)
    {
        int s, e, c;
        cin >> s >> e >> c;
        board[s].push_back({e, c});
        board[e].push_back({s, c});
    }
    solution();
}