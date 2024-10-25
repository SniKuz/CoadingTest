#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;
vector<string> board(100);
vector<vector<bool>> visited(100, vector<bool>(100));
int white = 0;
int blue = 0;

int BFS(int r, int c)
{
    char color = board[r][c];
    int cnt = 0;
    queue<pii> q;
    q.push({r, c});
    visited[r][c] = true;
    
    while(q.empty() == false)
    {
        auto cur = q.front(); q.pop();
        cnt++;
        
        for(int i = 0; i < 4; i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if(board[nx][ny] != color)
                continue;
            if(visited[nx][ny]) 
                continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    return cnt * cnt;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> board[i];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(visited[i][j] == false)
            {
                if(board[i][j] == 'W')
                    white += BFS(i, j);
                else
                    blue += BFS(i, j);
            }
        }
    }
    cout << white << ' ' << blue;
    return 0;
}
