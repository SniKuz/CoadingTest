#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<vector<int>> board(101, vector<int>(101, 2e8));
int v1, v2, res = 2e8;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        board[i][i] = 0;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        board[a][b] = 1;
        board[b][a] = 1;
    }

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

    for(int i = n-1; i > 0; i--)
    {
        for(int j = i+1; j > 0; j--)
        {
            int ik = 0, jk = 0;
            for(int k = n; k > 0; k--)
            {
                if(board[i][k] < board[j][k])
                    ik += board[i][k] * 2;
                else
                    jk += board[j][k] * 2;
            }
            if(ik + jk <= res)
            {
                res = ik + jk;
                v1 = i;
                v2 = j;
            }
        }
    }
    cout << v1 << ' ' << v2 << ' ' << res;
}