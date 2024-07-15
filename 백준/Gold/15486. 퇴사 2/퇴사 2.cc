#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1500000 + 51];
int T[1500000 + 1];
int P[1500000 + 1];
 
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; 
    cin >> n;
    
    for (int i = 1; i <= n; i++)
        cin >> T[i] >> P[i];
    
    for (int i = 1; i <= n; i++) {       
        dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i]);
        dp[i + 1] = max(dp[i + 1], dp[i]);
    }
 
    cout << dp[n + 1] << '\n';
}