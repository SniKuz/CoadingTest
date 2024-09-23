#include <bits/stdc++.h>
#define X first
#define Y second
#define pipii pair<int, pair<int, int>>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;
vector<vector<int>> board(100, vector<int>(100));
vector<vector<bool>> visited(100, vector<bool>(100));
map<int, vector<pair<int, int>>> islands;
vector<int> parents(7, -1);
priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
int res = 0;

int Find(int x)
{
    if(parents[x] < 0) return x;
    return parents[x] = Find(parents[x]);
}

void MakeUnion(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if(x == y) return;
    parents[x] += parents[y];
    parents[y] = x;
}

void CheckIsland(int r, int c)
{
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = true;
    int islandsSize = islands.size()+1;

    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        islands[islandsSize].push_back(cur);
        board[cur.X][cur.Y] = islandsSize;
        
        for(int i = 0; i < 4; i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if(board[nx][ny] == 0)
                continue;
            if(visited[nx][ny])
                continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

void Island()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] != 0 && visited[i][j] == false)
                CheckIsland(i, j);
        }
    }
}

void Bridge()
{
    for(const auto &island : islands)
    {
        for(const auto &pos : island.second) //island pos
        {
            for(int i = 0; i < 4; i++)
            {
                int cnt = 0;
                auto cur = pos;
                cur.X += dx[i];
                cur.Y += dy[i];
                while(cur.X >= 0 && cur.Y >= 0 && cur.X < n && cur.Y < m && board[cur.X][cur.Y] == 0)
                {
                    cur.X += dx[i];
                    cur.Y += dy[i];
                    cnt++;
                }
                if(cur.X < 0 || cur.Y < 0 || cur.X >= n || cur.Y >= m)
                    continue;
                if(board[pos.X][pos.Y] == board[cur.X][cur.Y])
                    continue;
                if(cnt <= 1)
                    continue;
                pq.push({cnt, {board[pos.X][pos.Y], board[cur.X][cur.Y]}});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> board[i][j] ;
        }
    }
    Island();
    Bridge();

    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        int a = Find(cur.second.first);
        int b = Find(cur.second.second);
        if (a == b) continue;
        MakeUnion(a, b);
        res += cur.first;
    }

    bool check = false;
    for(const auto& p : parents)
    {
        if(-p == islands.size())
        {
            check = true;
            break;
        }
    }

    if(check == false)
        cout << -1;
    else
        cout << res;
}