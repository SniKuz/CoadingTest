#include <bits/stdc++.h>
#define ll long long

using namespace std;
vector<vector<ll >> board(101, vector<ll >(101, INT_MAX));
int n, m;

ll res = INT_MAX;
pair<int, int> node;

int main() 
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        board[a][b] = 2;
        board[b][a] = 2;
    }
    for(int i = 1; i <= n; i++)
        board[i][i] = 0;
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(board[i][j] > board[i][k] + board[k][j])
                    board[i][j] = board[i][k] + board[k][j];
                    
    for(int i = n; i > 0; i--)
    {
        for(int j = i-1; j > 0; j--)
        {
            int cnt = 0;
            for(int k = n; k > 0; k--)
            {
                cnt += min(board[i][k], board[j][k]);
            }
            if(res >= cnt)
            {
                res = cnt;
                node.first = j;
                node.second = i;
            }
        }
    }
    cout << node.first << ' ' << node.second << ' ' << res;
    return 0;
}
