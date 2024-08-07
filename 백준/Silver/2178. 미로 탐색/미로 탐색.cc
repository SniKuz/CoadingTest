#include <bits/stdc++.h>

#define X first
#define Y second

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

using namespace std;

int h, v;
vector<string> board(100);

int solution()
{
    queue<pair<int, pair<int, int>>> q;
    vector<vector<bool>> visited(h, vector<bool>(v));
    q.push({1, {0, 0}});
    visited[0][0] = true;

    while(!q.empty())
    {
        auto cur = q.front(); q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = cur.second.X + dx[i];
            int ny = cur.second.Y + dy[i];

            if(nx < 0 || ny < 0 || nx >= h || ny >= v)
                continue;
            if(visited[nx][ny])
                continue;
            if(board[nx][ny] == '0')
                continue;
            if(nx == h-1 && ny == v-1)
                return cur.first+1;
            visited[nx][ny] = true;
            q.push({cur.first+1, {nx, ny}});
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> h >> v;
    for(int r = 0; r < h; r++)
    {
        cin >> board[r];
    }
    cout << solution();
}