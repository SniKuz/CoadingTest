#include <bits/stdc++.h>
#define DIV 1000000009

using namespace std;

int t;
unsigned int dp[1000001];
int idx = 4;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        for(; idx <= n; idx++)
        {
            dp[idx] = (dp[idx-1] + dp[idx-2] + dp[idx-3]) % DIV;
        }
        cout << dp[n] << '\n';
    }
}