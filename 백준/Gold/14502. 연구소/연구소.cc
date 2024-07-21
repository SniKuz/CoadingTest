#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;
vector<vector<int>> board(8, vector<int>(8)); //0 empty, 1 wall 2 virus
vector<pair<int, int>> virus;
int wall = 0;
int maxSafeArea = 0;

void Input()
{
    cin >> n >> m;
    for(int r = 0; r < n; r++)
    {
        for(int c = 0; c < m; c++)
        {
            cin >> board[r][c];
            if(board[r][c] == 2)
            {
                virus.push_back({r, c});
            }
            else if(board[r][c] == 1)
                wall += 1;
        }
    }
}

void Solution()
{
    int virusArea = 0;
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for(const auto& v : virus)
    {
        q.push({v.X, v.Y});
        visited[v.X][v.Y] = true;
    }
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        virusArea += 1;

        for(int i = 0; i < 4; i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if(visited[nx][ny])
                continue;
            if(board[nx][ny] == 1)
                continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    int safeArea = n * m - virusArea - wall - 3;
    if(maxSafeArea < safeArea)
        maxSafeArea = safeArea;
}

void CreateWall(int cnt)
{
    if(cnt == 0)
    {
        Solution();
        return;
    }
    
    for(int r = 0; r < n; r++)
    {
        for(int c = 0; c < m; c++)
        {
            if(board[r][c] == 0)
            {
                board[r][c] = 1;
                CreateWall(cnt-1);
                board[r][c] = 0;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Input();
    CreateWall(3);
    cout << maxSafeArea;
}