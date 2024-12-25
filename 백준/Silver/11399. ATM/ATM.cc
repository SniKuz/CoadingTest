#include <bits/stdc++.h>

using namespace std;

int n;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    vector<int> time(n);
    for(int i = 0; i < n; i++)
        cin >> time[i];
    sort(time.begin(), time.end());
    vector<int> prefix(n+1);
    int res = 0;
    for(int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i-1] + time[i-1];
        res += prefix[i];
    }
    cout << res;
    return 0;
}
