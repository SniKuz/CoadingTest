#include <bits/stdc++.h>

using namespace std;

int n;
int v[305];
int dp[305][2]; //i번째 계단, j번째 연속해서 밟았는지

int main() 
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    dp[0][0] = v[0];
    dp[1][0] = v[1];
    dp[1][1] = v[0] + v[1];
    for(int i = 2; i <= n; i++)
    {
        dp[i][0] = max(dp[i-2][0], dp[i-2][1]) + v[i];
        
        dp[i][1] = dp[i-1][0] + v[i];
    }

    cout << max(dp[n-1][0], dp[n-1][1]);
    return 0;
}
