#include <bits/stdc++.h>

#define R first
#define C second

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int r, c, t;
vector<vector<int>> board(1000, vector<int>(1000));
vector<pair<int, int>> cleaner; // 0이 위쪽, 1이 아래쪽

void Input()
{
    cin >> r >> c >> t;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == -1)
                cleaner.push_back({i, j});
        }
    }
}


void Print(vector<vector<int>> v)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "======\n";
}

void Dust()
{
    vector<vector<int>> dustMove(r, vector<int>(c, 0));
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(board[i][j] > 0)
            {
                for(int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx < 0 || ny < 0 || nx >= r || ny >= c)
                        continue;
                    if(board[nx][ny] == -1)
                        continue;
                    dustMove[nx][ny] += board[i][j] / 5;
                    dustMove[i][j] -= board[i][j] / 5;
                }
            }
        }
    }
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            board[i][j] += dustMove[i][j];
        }
    }
}

void AirRotate()
{
    { //topside
        for(int i = cleaner[0].R; i > 0; i--)
        {
            board[i][0] = board[i-1][0];
        }
        for(int i = 0; i < c-1; i++)
        {
            board[0][i] = board[0][i+1];
        }
        for(int i = 0; i < cleaner[0].R; i++)
        {
            board[i][c-1] = board[i+1][c-1];
        }
        for(int i = c-1; i > 0; i--)
        {
            board[cleaner[0].R][i] = board[cleaner[0].R][i-1];
        }
        board[cleaner[0].R][cleaner[0].C + 1] = 0;
        board[cleaner[0].R][cleaner[0].C] = -1;
    }
    
    { //topside
        for(int i = cleaner[1].R; i < r-1; i++)
        {
            board[i][cleaner[1].C] = board[i+1][cleaner[1].C];
        }
        for(int i = 0; i < c-1; i++)
        {
            board[r-1][i] = board[r-1][i+1];
        }
        for(int i = r-1; i > cleaner[1].R; i--)
        {
            board[i][c-1] = board[i-1][c-1];
        }
        for(int i = c-1; i > 0; i--)
        {
            board[cleaner[1].R][i] = board[cleaner[1].R][i-1];
        }
        board[cleaner[1].R][cleaner[1].C + 1] = 0;
        board[cleaner[1].R][cleaner[1].C] = -1;
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Input();
    for(int i = 0; i < t; i++)
    {
        Dust();
        AirRotate();
    }
    int sum = 0;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(board[i][j] > 0)
                sum += board[i][j];
        }
    }
    cout << sum;
}