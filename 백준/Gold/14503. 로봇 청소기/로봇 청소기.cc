#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

//0 up 1 right 2 down 3 left
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0 ,-1};
vector<vector<int>> board(50, vector<int>(50));
int N, M;
int reverseDir[] = {2, 3, 0, 1};
int rotateDir[] = {3, 0, 1, 2};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    pair<int, int> cur;
    cin >> cur.X >> cur.Y;
    int dir;
    cin >> dir;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            cin >> board[i][j];
        }
    }
    int ret = 0;
    bool canMove = true;
    while(canMove)
    {
        if(board[cur.X][cur.Y] == 0) 
        {
            board[cur.X][cur.Y] = 2;
            ret += 1;
        }

        bool nextArea = false;
        for(int i = 0; i < 4; ++i)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(board[nx][ny] == 0)
            {
                nextArea = true;
                break;
            }
        }

        if(!nextArea)
        {
            int tmpDir = reverseDir[dir];
            int nx = cur.X + dx[tmpDir];
            int ny = cur.Y + dy[tmpDir];
            if(board[nx][ny] == 1)
            {
                canMove = false;
                break;
            }
            cur.X = nx; cur.Y = ny;
        }
        else
        {
            for(int i = 0; i < 4; ++i)
            {
                dir = rotateDir[dir];
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(board[nx][ny] == 0)
                {
                    cur.X = nx; cur.Y = ny;
                    break;
                }
            }
        }
    }
    cout << ret;
    return 0;
}