#include <bits/stdc++.h>

using namespace std;

int n, k;
int res = -INT_MAX;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> k;
    vector<int> prefix(n+1, 0);
    for(int i = 1; i <= n; i++)
    {
        int input;
        cin >> input;
        prefix[i] = prefix[i-1] + input;
    }
    for(int i = k; i <= n; i++)
    {
        res = max(res, prefix[i] - prefix[i-k]);
    }
    cout << res;
    return 0;
}
