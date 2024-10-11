#include <bits/stdc++.h>
#define X first
#define Y second
#define pipii pair<int, pair<int, int>>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n;
vector<string> board(50);
vector<vector<int>> blackDoor(50, vector<int>(50, INT_MAX));
int res = INT_MAX;

void BFS()
{
    queue<pipii> q;
    if(board[0][0] == '1')
    {
        q.push({0, {0,0}});
    }
    else 
    {
        q.push({1, {0,0}});
        blackDoor[0][0] = 1;
    }       
    
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int nx = cur.second.X + dx[i];
            int ny = cur.second.Y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;
            if(nx == n-1 && ny == n-1)
            {
                if(board[nx][ny] == '0')
                    res = min(res, cur.first+1);
                else
                    res = min(res, cur.first);
            }
            if(board[nx][ny] == '0') // black
            {
                if(blackDoor[nx][ny] > cur.first + 1)
                {
                    blackDoor[nx][ny] = cur.first + 1;
                    q.push({blackDoor[nx][ny], {nx, ny}});
                }
            }
            else
            {
                if(blackDoor[nx][ny] == INT_MAX)
                {
                    blackDoor[nx][ny] = cur.first;
                    q.push({cur.first, {nx, ny}});
                }
                else
                {
                    if(blackDoor[nx][ny] > cur.first)
                    {
                        blackDoor[nx][ny] = cur.first;
                        q.push({cur.first, {nx, ny}});
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
    cout.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> board[i];
    }
    BFS();
    cout << res;
    return 0;
}
