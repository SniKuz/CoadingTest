#include <bits/stdc++.h>

#define R 0
#define G 1
#define B 2
#define X first
#define Y second

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

vector< vector<int> > maps(101, vector<int>(101));
vector< vector<int> > visitedRGB(101, vector<int>(101));
vector< vector<int> > visited(101, vector<int>(101));

int N;

int BFSRGB(int x, int y)
{
    vector< pair<int, int> > v;
    v.push_back({x, y});
    visitedRGB[x][y] = 1;
    int color = maps[x][y];

    while(!v.empty())
    {
        auto cur = v.back(); v.pop_back();
        
        for(int i = 0; i < 4; ++i)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || ny < 0 || nx == N || ny == N)
                continue;
            if(visitedRGB[nx][ny] != 0)
                continue;
            if(maps[nx][ny] != color)
                continue;
            visitedRGB[nx][ny] = 1;
            v.push_back({nx, ny});
        }
    }
    return 1;
}

int BFS(int x, int y)
{
    vector< pair<int, int> > v;
    v.push_back({x, y});
    visitedRGB[x][y] = 1;
    int color = maps[x][y];

    while(!v.empty())
    {
        auto cur = v.back(); v.pop_back();
        
        for(int i = 0; i < 4; ++i)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || ny < 0 || nx == N || ny == N)
                continue;
            if(visited[nx][ny] != 0)
                continue;
            if(color == B && maps[nx][ny] != B)
                continue;
            if(color != B && maps[nx][ny] == B)
                continue;
            visited[nx][ny] = 1;
            v.push_back({nx, ny});
        }
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    for(int x = 0; x < N; ++x)
    {
        for(int y = 0; y < N; ++y)
        {
            char w;
            cin >> w;
            if(w == 'R')
                maps[x][y] = R;
            else if(w == 'G')
                maps[x][y] = G;
            else
                maps[x][y] = B;
        }
    }
    
    int totalRGB = 0;
    int totalGB = 0;
    for(int x = 0; x < N; ++x)
    {
        for(int y = 0; y < N; ++y)
        {
            if(visitedRGB[x][y] == 0)
                totalRGB += BFSRGB(x, y);
            if(visited[x][y] == 0)
                totalGB += BFS(x, y);
        }
    }

    cout << totalRGB << '\n' << totalGB;
    return 0;
}