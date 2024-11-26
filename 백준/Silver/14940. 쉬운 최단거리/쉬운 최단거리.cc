#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;
vector<vector<int>> board(1000, vector<int>(1000));
vector<vector<int>> Map(1000, vector<int>(1000, -1));
pii start;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m ; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 2)
                start = {i, j};
        }
    }
    
    queue<pair <int, pii> > q;
    q.push({0, {start.X, start.Y}});
    Map[start.X][start.Y] = 0;
    
    while(q.empty() == false)
    {
        auto cur = q.front(); q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int nx = cur.second.X + dx[i];
            int ny = cur.second.Y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if(board[nx][ny] == 0)
                continue;
            if(Map[nx][ny] >= 0)
                continue;
            Map[nx][ny] = cur.first + 1;
            q.push({Map[nx][ny], {nx, ny}});
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(Map[i][j] >= 0)
                cout << Map[i][j] << ' ';
            else
            {
                if(board[i][j] == 0)
                    cout << 0 << ' ';
                else
                    cout << -1 << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}
