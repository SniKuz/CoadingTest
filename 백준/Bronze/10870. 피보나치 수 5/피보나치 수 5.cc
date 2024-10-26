#include <bits/stdc++.h>

using namespace std;

int n;
int dp[25];

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    for(int i = 4; i <= n; i++)
    {
        dp[i] = dp[i-1]+dp[i-2];
    }
    cout << dp[n];
    return 0;
}
