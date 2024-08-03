
#include <bits/stdc++.h>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int t, r, c;
vector<vector<char>> board(101, vector<char>(101));
vector<vector<bool>> visited(101, vector<bool>(101));

void dfs(int i, int j)
{
    queue<pair<int, int>> q;
    q.push({i, j});

    while(!q.empty())
    {
        auto cur = q.front(); q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || ny < 0 || nx >= r || ny >= c)
                continue;
            if(visited[nx][ny])
                continue;
            if(board[nx][ny] == '.')
                continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    for(int i = 0 ; i < t; i++)
    {
        cin >> r >> c;
        

        for(int j = 0; j < r; j++)
            for(int k = 0; k < c; k++)
            {
                cin >> board[j][k];
                visited[j][k] = false;
            }
        int cnt = 0;
        for(int j = 0; j < r; j++)
            for(int k = 0; k < c; k++)
            {
                if(board[j][k] == '#' && !visited[j][k])
                {
                    dfs(j, k);
                    cnt++;
                }
            }
        cout << cnt << '\n';
    }
}