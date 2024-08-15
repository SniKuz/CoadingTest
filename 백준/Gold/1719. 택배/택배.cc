#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> board(201, vector<int>(201, 2e8));
vector<vector<int>> route(201, vector<int>(201));

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int s, e, c;
        cin >> s >> e >> c;
        if(board[s][e] > c)
        {
            board[s][e] = c;
            board[e][s] = c;
            route[s][e] = e;
            route[e][s] = s;
        }
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
                    route[i][j] = route[i][k];
                }
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j)
                cout << "- ";
            else
                cout << route[i][j] << ' ';
        }
        cout << '\n';
    }
}