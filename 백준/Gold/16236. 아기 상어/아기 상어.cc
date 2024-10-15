#include <bits/stdc++.h>
#define Lv first
#define X first
#define Y second
#define pii pair<int, int>
#define pipii pair<int, pii>
#define INF 98765

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

pii sharkPos;
int sharkExp = 0;
int sharkLv = 2;

int board[20][20];

int n;
int res = 0;

int piiRange(pii x, pii y)
{
    return abs(x.X - y.X) + abs(x.Y - y.Y);
}

pipii NextTarget()
{
    priority_queue<pipii, vector<pipii>, greater<pipii>> nearFishs; // x작은거 y작은거순
    queue<pipii> q;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    q.push({0, sharkPos});
    visited[sharkPos.X][sharkPos.Y] = true;

    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        if(board[cur.second.X][cur.second.Y] > 0 && board[cur.second.X][cur.second.Y] < sharkLv)
        {
            nearFishs.push(cur);
        }
        
        for(int i = 0; i < 4; i++)
        {
            int nx = cur.second.X + dx[i];
            int ny = cur.second.Y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;
            if(board[nx][ny] > sharkLv)
                continue;
            if(visited[nx][ny])
                continue;
            visited[nx][ny] = true;
            q.push({cur.first+1, {nx, ny}});
        }
    }
    if(nearFishs.empty()) return {-1, {INF, INF}};
    return nearFishs.top();
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
            if(board[i][j] == 9)
            {
                sharkPos = {i ,j};
            }
        }
    }

    auto next = NextTarget();
    while(next.first > 0)
    {
        board[sharkPos.X][sharkPos.Y] = 0;
        res += next.first;
        sharkPos = next.second;
        board[sharkPos.X][sharkPos.Y] = 9;
        sharkExp++;
        if(sharkExp >= sharkLv && sharkLv < 7)
        {
            sharkExp = 0;
            sharkLv++;
        }
        next = NextTarget();
    }
    cout << res;
}
/*
자신의 크기보다 큰 물고기가 있으면 못지나감 > dfs로 해야하겠네
*/