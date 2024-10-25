#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, m, v; // n = row로 품
pii start;
int board[100][100];
bool visited[100][100];
bool pyroclastic[100][100];
vector<pair<int, pii>> volcano;
queue<pair<int, pii>> q;
queue<pair<int, pii>> q2;

int maxHeight = 0, minTime = 0;

void BFS()
{
    q.push({0, start});
    visited[start.X][start.Y] = true;
    
    while(q.empty() == false || q2.empty() == false)
    {
        if(q.empty() == false)
        {
            if(v > 0)
            {
                for(auto& e : volcano)
                {
                    if(--e.first == 0)
                    {
                        v--;
                        q2.push({-1, e.second});
                        pyroclastic[e.second.X][e.second.Y] = true;
                    }
                }
            }
            
            
            while(q.empty() == false)
            {
                auto cur = q.front(); q.pop();
                //cout << "1 : " << cur.first << ' ' << cur.second.X << ' ' << cur.second.Y << '\n';
                if(cur.first >= 0 && board[cur.second.X][cur.second.Y] > maxHeight)
                {
                    maxHeight = board[cur.second.X][cur.second.Y];
                    minTime = cur.first;
                }
                
                for(int i = 0; i < 4; i++)
                {
                    int nx = cur.second.X + dx[i];
                    int ny = cur.second.Y + dy[i];
                    
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                        continue;
                    if(cur.first >= 0)
                    {
                        if(visited[nx][ny])
                            continue;
                        visited[nx][ny] = true;
                        q2.push({cur.first+1, {nx, ny}});
                    }
                    else
                    {
                        if(pyroclastic[nx][ny])
                            continue;
                        pyroclastic[nx][ny] = true;
                        visited[nx][ny] = true;
                        q2.push({-1, {nx, ny}});
                    }
                }
            }
        }
        else //q2
        {
            if(v > 0)
            {
                for(auto& e : volcano)
                {
                    if(--e.first == 0)
                    {
                        v--;
                        q.push({-1, e.second});
                        pyroclastic[e.second.X][e.second.Y] = true;
                    }
                }
            }
            
            
            while(q2.empty() == false)
            {
                auto cur = q2.front(); q2.pop();
                //cout << "2 : " << cur.first << ' ' << cur.second.X << ' ' << cur.second.Y << '\n';
                if(cur.first >= 0 && board[cur.second.X][cur.second.Y] > maxHeight)
                {
                    maxHeight = board[cur.second.X][cur.second.Y];
                    minTime = cur.first;
                }
                
                for(int i = 0; i < 4; i++)
                {
                    int nx = cur.second.X + dx[i];
                    int ny = cur.second.Y + dy[i];
                    
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                        continue;
                    if(cur.first >= 0)
                    {
                        if(visited[nx][ny])
                            continue;
                        visited[nx][ny] = true;
                        q.push({cur.first+1, {nx, ny}});
                    }
                    else
                    {
                        if(pyroclastic[nx][ny])
                            continue;
                        pyroclastic[nx][ny] = true;
                        visited[nx][ny] = true;
                        q.push({-1, {nx, ny}});
                    }
                }
            }
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> v;
    cin >> start.X >> start.Y;
    start.X--; start.Y--;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }   
    }
    for(int i = 0; i < v; i++)
    {
        int x, y, t;
        cin >> x >> y >> t;
        x--; y--;
        visited[x][y] = true;
        volcano.push_back({t, {x, y}});
        if(t == 0)
        {
            v--;
            q.push({-1, {x, y}});
        }
    }
    BFS();
    cout << maxHeight << ' ' << minTime;
    return 0;
}
/*
14% 틀림 > 시작에서 제자리도 가능으로 바꾸니까 32%
*/