#include <bits/stdc++.h>

using namespace std;

int tc;
int idx = 4;
int dp[12];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int c = 0; c < tc; c++)
    {
        int n;
        cin >> n;
        for(; idx <= n; idx++)
        {
            dp[idx] = dp[idx-1] + dp[idx-2] + dp[idx-3];
        }
        cout << dp[n] << '\n';
    }
}