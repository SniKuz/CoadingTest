#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int n, m;
vector<vector<int>> board;
int ans = 0;
int len = 0;

void BF(int sx, int sy)
{
    vector<vector<bool>> visited(n, vector<bool>(m));
    deque<pair<int, pii>> coord = {{1, {sx, sy}}};
    visited[sx][sy] = true;
    
    while (coord.empty() == false)
    {
        auto curNodeLen = coord.front().first;
        auto curNode = coord.front().second;
        coord.pop_front();
        
        if (len < curNodeLen) 
        {
            len = curNodeLen;
            ans = board[sx][sy] + board[curNode.X][curNode.Y];
        }
        else if(len == curNodeLen)
        {
            ans = max(ans, board[sx][sy] + board[curNode.X][curNode.Y]); 
        }
        
        for(int i = 0; i < 4; i++)
        {
            int nx = curNode.X + dx[i];
            int ny = curNode.Y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (board[nx][ny] == 0)
                continue;
            if(visited[nx][ny])
                continue;
            coord.push_back({curNodeLen + 1, {nx, ny}});
            visited[nx][ny] = true;
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    board.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(board[i][j] != 0)
                BF(i, j);
        }
    }

    cout << ans;
    return 0;
}
