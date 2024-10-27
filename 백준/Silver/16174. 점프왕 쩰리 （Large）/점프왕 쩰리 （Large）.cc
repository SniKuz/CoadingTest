#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int, int>
#define WIN "HaruHaru"
#define LOSE "Hing"

using namespace std;

int dx[] = {0, 1};
int dy[] = {1, 0};

int n;
int board[64][64];
bool visited[64][64];

void BFS()
{
    queue<pii> q;
    q.push({0, 0});
    visited[0][0] = true;
    
    while(q.empty() == false)
    {
        auto cur = q.front(); q.pop();
        auto jump = board[cur.X][cur.Y];
        for(int i = 0; i < 2; i++)
        {
            int nx = cur.X + dx[i] * jump;
            int ny = cur.Y + dy[i] * jump;
            if(nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;
            if(nx == n-1 && ny == n-1)
            {
                cout << WIN;
                return;
            }
            if(visited[nx][ny])
                continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    cout << LOSE;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    BFS();
    return 0;
}
