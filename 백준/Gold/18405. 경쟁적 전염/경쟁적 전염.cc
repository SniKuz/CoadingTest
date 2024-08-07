#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, k;
vector<vector<int>> board(200, vector<int>(200));
vector<queue<pair<int, int>>> virus(1001);
int s, x, y;

void Diffusion()
{
    for(int t = 1; t <= k; t++)
    {
        int size = virus[t].size();
        for(int s = 0; s < size; s++)
        {
            auto pos = virus[t].front(); virus[t].pop();
            for(int i = 0; i < 4; i++)
            {
                int nx = pos.X + dx[i];
                int ny = pos.Y + dy[i];

                if(nx < 0 || ny < 0 || nx >= n || ny >= n)
                    continue;
                if(board[nx][ny] != 0)
                    continue;
                board[nx][ny] = t;
                virus[t].push({nx, ny});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            if(board[i][j] > 0)
                virus[board[i][j]].push({i, j});
        }
    }
    cin >> s >> x >> y;
    x -= 1; y -= 1;
    for(int i = 0; i < s; i++)
    {
        Diffusion();
    }
    cout << board[x][y];
}