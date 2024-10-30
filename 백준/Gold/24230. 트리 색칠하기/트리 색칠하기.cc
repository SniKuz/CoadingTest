#include <bits/stdc++.h>
#define INF 200'001

using namespace std;

int n;
vector<int> colors(INF, 0);
vector<vector<int>> board(INF);
vector<int> parents(INF);
vector<bool> visited(INF);
int res = 0;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> colors[i];
    for(int i = 1; i < n; i++)
    {
        int s, e;
        cin >> s >> e;
        board[s].push_back(e);
        board[e].push_back(s);
    }
    
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while(q.empty() == false)
    {
        auto cur = q.front(); q.pop();
        if(colors[cur] != colors[parents[cur]])
        {
            //cout << parents[cur] << ' ' << cur << '\n';
            res++;
        }
        for(const auto& next : board[cur])
        {
            if(visited[next])
                continue;
            visited[next] = true;
            parents[next] = cur;
            q.push(next);
        }
    }
    cout << res;
    return 0;
}
