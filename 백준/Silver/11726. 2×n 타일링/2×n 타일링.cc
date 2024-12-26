#include <bits/stdc++.h>
#define DIV 10007

using namespace std;

int n;
int dp[2000];

int main() 
{
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for(int i = 4; i <= n; i++)
    {
        dp[i] = (dp[i-1] + dp[i-2]) % DIV;
    }
    cout << dp[n];
    return 0;
}
