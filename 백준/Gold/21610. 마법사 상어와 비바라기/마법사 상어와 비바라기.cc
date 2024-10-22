#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

int dx[] = {0, -1, -1, -1, 0, 1, 1, 1}; // 1, 3, 5, 7
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

int n, m;
int board[51][51];
vector<pii> clouds;
set<pii> prevClouds;

void Move(int d, int s)
{
    for(auto &cloud : clouds)
    {
        for(int i = 0; i < s; i++)
        {
            cloud.X += dx[d];
            cloud.Y += dy[d];
            if(cloud.X < 0)
                cloud.X = n-1;
            else if(cloud.X >= n)
                cloud.X = 0;
            if(cloud.Y < 0)
                cloud.Y = n-1;
            else if(cloud.Y >= n)
                cloud.Y = 0;
        }
    }
}

void Rain()
{
    for(const auto& cloud : clouds)
    {
        board[cloud.X][cloud.Y]++;
    }
}

void WaterCopy()
{
    while(!clouds.empty())
    {
        auto cur = clouds.back(); clouds.pop_back();
        for(int i = 1; i < 8; i+=2)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;
            if(board[nx][ny] > 0)
            {
                board[cur.X][cur.Y]++;
            }
        }
        prevClouds.insert(cur);
    }
}

void CreateCloud()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] >= 2)
            {
                if(prevClouds.find({i, j}) == prevClouds.end())
                {
                    board[i][j] -= 2;
                    clouds.push_back({i, j});
                }
            }
        }
    }
    prevClouds.clear();
}

void print()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "======\n";
}

int main() 
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    clouds.push_back({n-1, 0});
    clouds.push_back({n-1, 1});
    clouds.push_back({n-2, 0});
    clouds.push_back({n-2, 1});
    for(int i = 0; i < m; i++)
    {
        int d, s;
        cin >> d >> s;
        d--;
        Move(d, s);
        Rain();
        WaterCopy();
        CreateCloud();
        //print();
    }
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            res += board[i][j];
        }
    }
    cout << res;
    return 0;
}