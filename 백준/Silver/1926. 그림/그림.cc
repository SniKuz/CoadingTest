#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int dx[] = {1, 0, -1 , 0};
int dy[] = {0, 1, 0, -1};

int n, m;
vector<vector<int>> board(500, vector<int>(500));
vector<vector<bool>> visited(500, vector<bool>(500));
int cnt = 0, maxSize = 0;

void Search(int r, int c)
{
    cnt++;
    int size = 0;
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = true;

    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        size++;
        
        for(int i = 0; i < 4; i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if(visited[nx][ny])
                continue;
            if(board[nx][ny] == 0)
                continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    maxSize = max(maxSize, size);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!visited[i][j] && board[i][j] != 0)
                Search(i, j);
        }
    }
    cout << cnt << '\n' << maxSize;
}