#include <bits/stdc++.h>
#define N 8
#define X first
#define Y second

using namespace std;

int dx[] = {0, 1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, 0, -1, 1, -1, 1, -1};

vector<vector<char>> board(N, vector<char>(N));
vector<vector<int>> walls(8); // j, i

void FallingWalls()
{
    for(int j = 0; j < N; j++)
    {
        for(int i = walls[j].size()-1; i >= 0; i--)
        {
            if(walls[j][i] >= N)
                continue;
            else
            {
                board[walls[j][i]][j] = '.';
                walls[j][i] += 1;
                if(walls[j][i] >= N)
                    continue;
                board[walls[j][i]][j] = '#';
            }
        }
    }
}

bool solution()
{
    queue<pair<int, int>> q1; 
    queue<pair<int, int>> q2;
    q1.push({7, 0});

    while(!q1.empty() || !q2.empty())
    {
        vector<vector<bool>> visited(N, vector<bool>(N));
        if(!q1.empty())
        {
            while(!q1.empty())
            {
                auto cur = q1.front(); q1.pop();
                if(board[cur.X][cur.Y] != '.')
                    continue;

                for(int i = 0; i < 9; i++)
                {
                    int nx = cur.X + dx[i];
                    int ny = cur.Y + dy[i];

                    if(nx < 0 || ny < 0 || nx >= N || ny >= N)
                        continue;
                    if(board[nx][ny] != '.')
                        continue;
                    if(nx == 0 && ny == N-1)
                        return true;
                    if(visited[nx][ny])
                        continue;
                    visited[nx][ny] = true;
                    q2.push({nx, ny});
                }
            }
        }
        else 
        {
            while(!q2.empty())
            {
                auto cur = q2.front(); q2.pop();
                if(board[cur.X][cur.Y] != '.')
                    continue;

                for(int i = 0; i < 9; i++)
                {
                    int nx = cur.X + dx[i];
                    int ny = cur.Y + dy[i];

                    if(nx < 0 || ny < 0 || nx >= N || ny >= N)
                        continue;
                    if(board[nx][ny] != '.')
                        continue;
                    if(nx == 0 && ny == N-1)
                        return true;
                    if(visited[nx][ny])
                        continue;
                    visited[nx][ny] = true;
                    q1.push({nx, ny});
                }
            }
        }
        FallingWalls();
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if(board[i][j] != '.')
                walls[j].push_back(i);
        }
    }
    

    if(solution())
        cout << '1';
    else
        cout << '0';
}