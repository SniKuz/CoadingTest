#include <bits/stdc++.h>
#define X first
#define Y second
#define pipii pair<int, pair<int, int>>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;
pair<int, int> s, e, l;
int minLeverRoute = INT_MAX;
int minEndRoute = INT_MAX;

void PointInit(vector<string> &board)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == 'S') s = {i ,j};
            if(board[i][j] == 'E') e = {i ,j};
            if(board[i][j] == 'L') l = {i ,j};
        }
    }
}

int solution(vector<string> board) {
    n = board.size(); m = board.back().size();
    PointInit(board);
    
    queue<pipii> q;
    vector<vector<bool>> visited(n, vector<bool>(m));
    q.push({0, s});
    visited[s.X][s.Y] = true;
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        if(cur.second.X == l.X && cur.second.Y == l.Y)
        {
            minLeverRoute = cur.first;
            break;
        }
        
        for(int i = 0; i < 4; i++)
        {
            int nx = cur.second.X + dx[i];
            int ny = cur.second.Y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if(board[nx][ny] == 'X')
                continue;
            if(visited[nx][ny])
                continue;
            visited[nx][ny] = true;
            q.push({cur.first+1, {nx, ny}});
        }
    }
    
    if(minLeverRoute == INT_MAX) return -1;
    q = queue<pipii>();
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            visited[i][j] = false;
    
    q.push({0, l});
    visited[l.X][l.Y] = true;
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        if(cur.second.X == e.X && cur.second.Y == e.Y)
        {
            minEndRoute = cur.first;
            break;
        }
        
        for(int i = 0; i < 4; i++)
        {
            int nx = cur.second.X + dx[i];
            int ny = cur.second.Y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if(board[nx][ny] == 'X')
                continue;
            if(visited[nx][ny])
                continue;
            visited[nx][ny] = true;
            q.push({cur.first+1, {nx, ny}});
        }
    }
    if(minEndRoute == INT_MAX) return -1;
    return minLeverRoute + minEndRoute;
}