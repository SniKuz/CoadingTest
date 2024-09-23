#include <bits/stdc++.h>
#define INF 2e8

using namespace std;

int v, e;
vector<vector<int>> board(401, vector<int>(401, INF));
int res = INF;

int main()
{
    cin >> v >> e;
    for(int i = 0; i < e; i++)
    {
       int a, b, c;
       cin >> a >> b >> c;
       board[a][b] = c;
    }

    for(int k = 1; k <= v; k++)
    {
        for(int i = 1; i <= v; i++)
        {
            for(int j = 1; j <= v; j++)
            {
                if(board[i][j] > board[i][k] + board[k][j])
                    board[i][j] = board[i][k] + board[k][j];
            }
        }
    }
    for(int i = 1; i <= v; i++)
    {
        int minRoute = INF;
        for(int j = 1; j <= v; j++)
        {
            if(i == j) continue;
            if(minRoute > board[i][j] + board[j][i])
                minRoute = board[i][j] + board[j][i];
        }
        if(minRoute < res)
            res = minRoute;
    }
    if(res == INF)
        cout << -1;
    else
        cout << res;
}