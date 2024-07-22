#include <bits/stdc++.h>

#define cost first
#define nodes second

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int n;

vector<vector<int>> board(125, vector<int>(125));

void Solution(int idx)
{
    queue<pair<int, pair<int, int>>> q;
    vector<vector<int>> dist(125, vector<int>(125, 2e9));
    q.push({board[0][0], {0,0}});
    dist[0][0] = board[0][0];

    while(!q.empty())
    {
        auto cur = q.front(); q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = cur.nodes.first + dx[i];
            int ny = cur.nodes.second + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;

            int nc =  cur.cost + board[nx][ny];
            if(dist[nx][ny] > nc)
            {
                dist[nx][ny] =  nc;
                q.push({nc, {nx, ny}});
            }
        }
    }
    cout << "Problem " << idx << ": " << dist[n-1][n-1] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    int cnt = 0;
    while(n != 0)
    {
        cnt++;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> board[i][j];
            }
        }
        Solution(cnt);
        cin >> n;
    }
}