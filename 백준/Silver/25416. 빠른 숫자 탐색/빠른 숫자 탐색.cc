#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int board[5][5];
bool visited[5][5];
int r, c;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            cin >> board[i][j];
    cin >> r >> c;
    
    queue<pair<int, pii>> q;
    q.push({0, {r, c}});
    visited[r][c] = true;
    
    while(q.empty() == false)
    {
        auto cur = q.front(); q.pop();
        if(board[cur.second.X][cur.second.Y] == 1)
        {
            cout << cur.first;
            return 0;
        }
        
        for(int i = 0; i < 4; i++)
        {
            int nx = cur.second.X + dx[i];
            int ny = cur.second.Y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5)
                continue;
            if(board[nx][ny] < 0)
                continue;
            if(visited[nx][ny])
                continue;
            visited[nx][ny] = true;
            q.push({cur.first+1, {nx, ny}});
        }
    }
    cout << -1;
    return 0;
}
