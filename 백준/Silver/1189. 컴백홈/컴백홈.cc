#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

int dx[] = {1, 0, -1 ,0};
int dy[] = {0, 1, 0, -1};

int r, c, k;
vector<string> board(5);
vector<vector<bool>> _visited(5, vector<bool>(5));
int res = 0;

void solution(int dist, pii cur, vector<vector<bool>> visited)
{
    if(cur.X == 0 && cur.Y == c-1)
    {
        if(dist == k)
            res++;
        return;
    }
    
    for(int i = 0; i < 4; i++)
    {
        int nx = cur.X + dx[i];
        int ny = cur.Y + dy[i];
        
        if(nx < 0 || ny < 0 || nx >= r || ny >= c)
            continue;
        if(board[nx][ny] == 'T')
            continue;
        if(visited[nx][ny])
            continue;
            
        visited[nx][ny] = true;
        solution(dist+1, {nx, ny}, visited);
        visited[nx][ny] = false;
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> r >> c >> k;
    for(int i = 0; i < r; i++)
    {
        cin >> board[i];
    }
    
    _visited[r-1][0] = true;
    solution(1, {r-1, 0}, _visited);
    cout << res;
    
    return 0;
}
