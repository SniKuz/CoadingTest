#include <bits/stdc++.h>

#define node first
#define dist second

using namespace std;

int n, m;

vector<vector<int>> board(20001);
vector<bool> visited(20001);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;
        board[s].push_back(e);
        board[e].push_back(s);
    }

    queue<pair<int, int>> q; //node, length
    q.push({1, 0});
    visited[1] = true;
    int maxDist = 0;
    int maxDistCnt = 0;
    int maxDistNode = 0;

    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        if(cur.dist > maxDist)
        {
            maxDist = cur.dist;
            maxDistCnt = 1;
            maxDistNode = cur.node;
        }
        else if(cur.dist == maxDist)
        {
            maxDistCnt += 1;
            if(maxDistNode > cur.node)
                maxDistNode = cur.node;
        }
        int nextDist = cur.dist + 1;
        for(const auto& next : board[cur.node])
        {
            if(visited[next])
                continue;
            visited[next] = true;
            q.push({next, nextDist});
        }
    }
    cout << maxDistNode << ' ' << maxDist << ' ' << maxDistCnt;
}