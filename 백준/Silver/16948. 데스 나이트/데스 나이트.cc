#include <bits/stdc++.h>
#define pii pair<int, int>
#define X first
#define Y second

using namespace std;

int dx[] = {-2, -2, 0, 0, 2, 2};
int dy[] = {-1, 1, -2, 2, -1, 1};

int n;
pii p1, p2;
vector<vector<bool>> visited(200, vector<bool>(200));

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    cin >> p1.X >> p1.Y >> p2.X >> p2.Y;

    queue<pair<int, pii>> q;
    q.push({0, p1});
    visited[p1.X][p1.Y]  = true;
    
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();

        for(int i = 0; i < 6; i++)
        {
            int nx = cur.second.X + dx[i];
            int ny = cur.second.Y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;
            if(nx == p2.X && ny == p2.Y)
            {
                cout << cur.first+1;
                return 0;
            }
            if(visited[nx][ny])
                continue;
            visited[nx][ny] = true;
            q.push({cur.first+1, {nx, ny}});
        }
    }
    cout << -1;
}