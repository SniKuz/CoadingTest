#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int, int>
#define MAXSIZE (1<<6)+1

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, q;
int board[MAXSIZE][MAXSIZE];
int board2[MAXSIZE][MAXSIZE];
bool visited[MAXSIZE][MAXSIZE];
bool turn1 = true;

void print()
{
    if(turn1)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << board2[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    cout << "====\n";
}

void Rotate(int left, int top,int l)
{
    if(turn1)
    {
        for(int i = 0; i < l; i++)
        {
            for(int j = 0; j < l; j++)
            {
                board2[j+left][l-i-1+top] = board[i+left][j+top];
            }
        }
    }
    else
    {
        for(int i = 0; i < l; i++)
        {
            for(int j = 0; j < l; j++)
            {
                board[j+left][l-i-1+top] = board2[i+left][j+top];
            }
        }
    }
}

void Melt()
{
    vector<pii> target;
    if(turn1)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int ice = 0;
                for(int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= n)
                        continue;
                    if(board2[nx][ny] > 0)
                        ice++;
                }
                if(ice < 3) target.push_back({i, j});
            }
        }
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int ice = 0;
                for(int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= n)
                        continue;
                    if(board[nx][ny] > 0)
                        ice++;
                }
                if(ice < 3) target.push_back({i, j});
            }
        }
    }
    
    if(turn1)
    {
        for(const auto& melt : target)
        {
            if(board2[melt.X][melt.Y] > 0)
                board2[melt.X][melt.Y]--;
        }
    }
    else
    {
        for(const auto& melt : target)
        {
            if(board[melt.X][melt.Y] > 0)
                board[melt.X][melt.Y]--;
        }
    }
    
}

int BFS(int r, int c)
{
    int ret = 0;
    queue<pii> q;
    q.push({r, c});
    visited[r][c] = true;
    if(turn1)
    {
        while(q.empty() == false)
        {
            auto cur = q.front(); q.pop();
            ret++;
            
            for(int i = 0; i < 4; i++)
            {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                
                if(nx < 0 || ny < 0 || nx >= n || ny >= n)
                    continue;
                if(board2[nx][ny] == 0)
                    continue;
                if(visited[nx][ny])
                    continue;
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    else
    {
        while(q.empty() == false)
        {
            auto cur = q.front(); q.pop();
            ret++;
            
            for(int i = 0; i < 4; i++)
            {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                
                if(nx < 0 || ny < 0 || nx >= n || ny >= n)
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
    return ret;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    n = (1<<n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    for(int i = 0; i < q; i++)
    {
        int l;
        cin >> l;
        l = (1<<l);
        for(int j = 0; j < n; j += l)
        {
            for(int k = 0; k < n; k += l)
            {
                Rotate(j, k, l);
            }
        }
        Melt();
        turn1 = !turn1;
    }
    turn1 = !turn1;
    
    int ices = 0, maxIce = 0;
    if(turn1)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board2[i][j] > 0) 
                {
                    ices += board2[i][j];
                    if(visited[i][j] == false)
                        maxIce = max(maxIce, BFS(i, j));
                }
            }
        }
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] > 0) 
                {
                    ices += board[i][j];
                    if(visited[i][j] == false)
                        maxIce = max(maxIce, BFS(i, j));
                }    
            }
        }
    }
    
    // print();
    cout << ices << '\n' << maxIce;
    return 0;
}