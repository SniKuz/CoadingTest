#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, l, r;
vector<vector<int>> board(50, vector<int>(50));
vector<vector<bool>> visited(50, vector<bool>(50, false));

bool cycle = true;
int cycleCnt = -1;

void Reset()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            visited[i][j] = false;
        }
    }
}

void dfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    int totalPeople = 0;
    vector<pair<int, int>> group;

    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        group.push_back(cur);
        totalPeople += board[cur.X][cur.Y];

        for(int i = 0; i < 4; i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;
            if(visited[nx][ny])
                continue;
            int temp = abs(board[cur.X][cur.Y] - board[nx][ny]);
            if(temp < l || temp > r)
                continue;
                
            visited[nx][ny] = true;
            q.push({nx, ny});
            cycle = true;

        }
    }
    int mean = totalPeople / group.size();
    for(const auto& g : group)
    {
        board[g.X][g.Y] = mean;
    }
}

void Search()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(!visited[i][j])
            {
                dfs(i, j);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> l >> r;
    for(int r = 0; r < n; r++)
    {
        for(int c = 0; c < n; c++)
        {
            cin >> board[r][c];
        }
    }
    
    
    while(cycle)
    {
        Reset();
        cycle = false;
        Search();
        cycleCnt++;
    }
    cout << cycleCnt;
}