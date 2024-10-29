#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

int dx[] = {-1, 0, 1, 0}; // up left down right
int dy[] = {0, -1, 0, 1};

int n, m;
int a, b;
int k;
pii s, e;

int board[500][500];
bool visited[500][500];
int res = -1;

vector<pii> MakeBlocks(pii leftTop, int dir)
{
    vector<pii> ret;
    switch(dir)
    {
        case 0://up
            {
                for(int i = 0; i < b; i++)
                    ret.push_back({leftTop.X, leftTop.Y++});
            }
            break;
        case 1://left
            {       
                for(int i = 0; i < a; i++)
                    ret.push_back({leftTop.X++, leftTop.Y});
            }
            break;
        case 2://down
            {       
                leftTop.X += (a - 1);
                for(int i = 0; i < b; i++)
                        ret.push_back({leftTop.X, leftTop.Y++});
            }
            break;
        case 3://right
            {
                leftTop.Y += (b - 1);
                for(int i = 0; i < a; i++)
                    ret.push_back({leftTop.X++, leftTop.Y});
            }
            break;
    }
    return ret;
}

void BFS()
{
    queue<pair<int, pii>> q;
    q.push({0, s});
    visited[s.X][s.Y] = true;
    
    while(q.empty() == false)
    {
        auto cur = q.front(); q.pop();
        if(cur.second.X == e.X && cur.second.Y == e.Y)
        {
            res = cur.first;
            return;
        }
        
        for(int i = 0; i < 4; i++)
        {
            if(visited[cur.second.X + dx[i]][cur.second.Y + dy[i]])
                continue;
                
            bool validMove = true;
            for(const auto& block : MakeBlocks(cur.second, i))
            {
                int nx = block.X + dx[i];
                int ny = block.Y + dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                {
                    validMove = false;
                    break;
                }
                if(board[nx][ny] != 0)
                {
                    validMove = false;
                    break;
                }
            }
            if(validMove)
            {
                visited[cur.second.X + dx[i]][cur.second.Y + dy[i]] = true;
                q.push({cur.first+1, {cur.second.X + dx[i], cur.second.Y + dy[i]}});
            }
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> a >> b >> k;
    for(int i = 0; i < k ; i++)
    {
        int bx, by;
        cin >> bx >> by;
        bx--; by--;
        board[bx][by] = 1;
    }
    cin >> s.X >> s.Y;
    cin >> e.X >> e.Y;
    s.X--; s.Y--; e.X--; e.Y--;
    BFS();
    cout << res;
    return 0;
}