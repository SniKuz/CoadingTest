#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int dx[] = {1, 0 , -1, 0};
int dy[] = {0, 1, 0, -1};

int r, c;

vector<vector<int>> board(300, vector<int>(300));
vector<pair<int, int>> iceLand;

void Input()
{
    cin >> r >> c; 
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cin >> board[i][j];
            if(board[i][j] > 0)
                iceLand.push_back({i,j});
        }
    }
}

void IceMelt()
{
    vector<vector<int>> melt(r, vector<int>(c));
    for(const auto& ice : iceLand)
    {
        for(int i = 0; i < 4; i++)
        {
            int nx = ice.X + dx[i];
            int ny = ice.Y + dy[i];
            if(nx < 0 || ny < 0 || nx >= r || ny >= c)
                continue;
            if(board[nx][ny] > 0)
                continue;
            melt[ice.X][ice.Y] -= 1;
        }
    }

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            board[i][j] += melt[i][j];
            if(board[i][j] < 0) board[i][j] = 0;
        }
    }
}

int CheckLand2() // 2 two land, 1 one land, 0 no land
{
    int iceLandCnt = 0;
    vector<vector<bool>> visited(r, vector<bool>(c));
    queue<pair<int, int>> q;
    for(const auto& ice : iceLand)
    {
        if(iceLandCnt > 1) return iceLandCnt;
        if(board[ice.X][ice.Y] == 0)
            continue;
        if(visited[ice.X][ice.Y])
            continue;
        iceLandCnt++;
        visited[ice.X][ice.Y] = true;
        q.push({ice.X, ice.Y});
        while(!q.empty())
        {
            auto cur = q.front(); q.pop();

            for(int i = 0; i < 4; i++)
            {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if(nx < 0 || ny < 0 || nx >= r || ny >= c)
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
    return iceLandCnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Input();
    int time = 0;
    int cnt;
    while(true)
    {
        cnt = CheckLand2();
        if(cnt > 1)
        {
            cout << time;
            break;
        }
        else if(cnt == 0)
        {
            cout << 0;
            break;
        }
        IceMelt();
        time++;
    }
}