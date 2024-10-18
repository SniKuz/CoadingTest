#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> board(10001);
vector<bool> visited(10001, false);
int res = 0;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        board[a].push_back(b);
        board[b].push_back(a);
    }
    
    queue<pair<int, int>> q;
    q.push({2, 1});
    visited[1] = true;
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        if(cur.first == 0) continue;
        
        for(const auto &next : board[cur.second])
        {
            if(visited[next])
                continue;
            res++;
            visited[next] = true;
            q.push({cur.first-1, next});
        }
    }
    cout << res;
    return 0;
}
