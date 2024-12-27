#include <bits/stdc++.h>
#define DIV 10'007

using namespace std;

int n;
vector<int> dp(1005);

int main() 
{
    cin >> n;
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 5;
    for(int i = 4; i <= n; i++)
    {
        dp[i] = (dp[i-1] + dp[i-2]*2) % DIV;
    }
    cout << dp[n];
    return 0;
}
