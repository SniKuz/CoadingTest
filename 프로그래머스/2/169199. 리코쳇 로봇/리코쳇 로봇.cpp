#include <bits/stdc++.h>
#define X first
#define Y second
#define pipii pair<int, pair<int, int>>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;
queue<pipii> q;
vector<vector<bool>> visited(100, vector<bool>(100, false));
pair<int, int> startPoint, endPoint;

void CheckPoint(vector<string> &board)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == 'R') startPoint = {i, j};
            if(board[i][j] == 'G') endPoint = {i, j};
        }
    }
}

int solution(vector<string> board) {
    n = board.size(); m = board.back().size();
    CheckPoint(board);
    
    q.push({0, startPoint});
    visited[startPoint.X][startPoint.Y] = true;
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        if(cur.second.X == endPoint.X && cur.second.Y == endPoint.Y)
        {
            return cur.first;
        }
        
        for(int i = 0; i < 4; i++)
        {
            int nx = cur.second.X;
            int ny = cur.second.Y;
            while(true)
            {
                nx += dx[i];
                ny += dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                {
                    nx -= dx[i];
                    ny -= dy[i];
                    break;
                }
                if(board[nx][ny] == 'D')
                {
                    nx -= dx[i];
                    ny -= dy[i];
                    break;
                }
            }
            if(visited[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push({cur.first+1, {nx ,ny}});
        }
    }
    
    return -1;
}