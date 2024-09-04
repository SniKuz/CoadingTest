#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> board(501, vector<int>(501));
vector<vector<int>> dp(501, vector<int>(501));
int res = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cin >> board[i][j];
        }
    }
    dp[0][0] = board[0][0];
    dp[1][0] = board[1][0] + dp[0][0];
    dp[1][1] = board[1][1] + dp[0][0];
    for(int i = 2; i < n; i++)
    {
        dp[i][0] = board[i][0] + dp[i-1][0];
        for(int j = 1; j < i; j++)
        {
            dp[i][j] = board[i][j] + max(dp[i-1][j-1], dp[i-1][j]);
        }
        dp[i][i] = board[i][i] + dp[i-1][i-1];
    }
    for(int i = 0; i < n; i++)
    {
        if(res < dp[n-1][i])
            res = dp[n-1][i];
    }
    cout << res;
}