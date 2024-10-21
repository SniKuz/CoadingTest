#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;
vector<string> board(50);
int res = 0;

void DFS(int r, int c)
{
    vector<vector<bool>> visited(n, vector<bool>(m));
    queue<pair<int, pii>> q;
    q.push({0, {r, c}});
    visited[r][c] = true;
    
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        res = max(res, cur.first);
        
        for(int i = 0; i < 4; i++)
        {
            int nx = cur.second.X + dx[i];
            int ny = cur.second.Y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if(board[nx][ny] == 'W')
                continue;
            if(visited[nx][ny])
                continue;
            visited[nx][ny] = true;
            q.push({cur.first+1, {nx, ny}});
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> board[i];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == 'L')
                DFS(i, j);
        }
    }
    cout << res;
    return 0;
}
