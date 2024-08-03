#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int dx[] = {0, 1, 1};
int dy[] = {1, 1, 0};

int n;
vector<vector<int>> board(16, vector<int>(16));
vector<vector<bool>> visited(16, vector<bool>(16));
pair<int, pair<int, int>> rootP = {0, {0, 1}};
int res = 0;

void solution(pair<int, pair<int, int>> pipe)
{
    if(pipe.second.X == n-1 && pipe.second.Y == n-1)
    {
        res++;
        return;
    }

    switch (pipe.first)
    {
        case 0: // vertical
            for(int i = 0; i < 2; i++)
            {
                int nx = pipe.second.X + dx[i];
                int ny = pipe.second.Y + dy[i];
                if(nx >= n || ny >= n)
                    continue;
                if(board[nx][ny] != 0)
                    continue;
                if(i == 1 && (board[nx-1][ny] != 0 || board[nx][ny-1] != 0))
                    continue;
                solution({i, {nx, ny}});
            }
            break;
        case 1: // diagonal
            for(int i = 0; i < 3; i++)
            {
                int nx = pipe.second.X + dx[i];
                int ny = pipe.second.Y + dy[i];
                if(nx >= n || ny >= n)
                    continue;
                if(board[nx][ny] != 0)
                    continue;
                if(i == 1 && (board[nx-1][ny] != 0 || board[nx][ny-1] != 0))
                    continue;
                solution({i, {nx, ny}});
            }
            break;
        case 2: //horizontal
            for(int i = 1; i < 3; i++)
            {
                int nx = pipe.second.X + dx[i];
                int ny = pipe.second.Y + dy[i];
                if(nx >= n || ny >= n)
                    continue;
                if(board[nx][ny] != 0)
                    continue;
                if(i == 1 && (board[nx-1][ny] != 0 || board[nx][ny-1] != 0))
                    continue;
                solution({i, {nx, ny}});
            }
            break;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    solution(rootP);
    cout << res;
}