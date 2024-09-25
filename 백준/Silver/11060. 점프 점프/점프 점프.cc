#include <bits/stdc++.h>

using namespace std;

int n;
int board[1001] = {0,};
vector<int> dp(1201, INT_MAX);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> board[i];
    }
    dp[0] = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j <= board[i]; j++)
        {
            if(dp[i] != INT_MAX && dp[i+j] > dp[i] + 1)
            {
                dp[i+j] = dp[i] + 1;
            }
        }
    }

    if(dp[n-1] == INT_MAX)
        cout << -1;
    else
        cout << dp[n-1];
}