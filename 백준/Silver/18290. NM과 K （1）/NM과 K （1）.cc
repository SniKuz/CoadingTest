#include <bits/stdc++.h>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, m, k;
int board[10][10];
int visited[10][10];
int res = -987654321;

void BF(int r, int c, int turn, int sum)
{
    if(turn >= k)
    {
        res = max(res, sum);
        return;
    }
    for(int i = r; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(i == r && j < c)
                continue;
            if(visited[i][j] == 0)
            {
                visited[i][j]++;
                for(int d = 0; d < 4; d++)
                {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                        continue;
                    visited[nx][ny]++;
                }
                
                sum += board[i][j];
                BF(i, j, turn+1, sum);
                sum -= board[i][j];
                
                visited[i][j]--;
                for(int d = 0; d < 4; d++)
                {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                        continue;
                    visited[nx][ny]--;
                }
            }
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    BF(0, 0, 0, 0);
    cout << res;
    return 0;
}
