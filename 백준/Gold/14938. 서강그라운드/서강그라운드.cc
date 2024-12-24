#include <bits/stdc++.h>
#define MAX 98765432
using namespace std;

int n, m, r;
vector<int> items(101);
vector<vector<int>> board(101, vector<int>(101, MAX));
int res = 0;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> r;
    for(int i = 1; i <= n; i++)
        cin >> items[i];
    for(int i = 0; i < r; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(board[a][b] > c)
        {
            board[a][b] = c;
            board[b][a] = c;
        }
    }
    for(int i = 1; i <= n; i++)
        board[i][i] = 0;
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(board[i][j] > board[i][k] + board[k][j])
                {
                    board[i][j] = board[i][k] + board[k][j];
                }
            }
        }
    }
    
    for(int i = 1; i <= n; i++)
    {
        int item = 0;
        for(int j = 1; j <= n; j++)
        {
            if(board[i][j] <= m)
                item += items[j];
        }
        res = max(res, item);
    }
    cout << res;
    return 0;
}
