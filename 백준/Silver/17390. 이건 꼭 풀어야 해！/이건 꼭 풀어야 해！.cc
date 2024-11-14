#include <bits/stdc++.h>

using namespace std;

int n, q;
vector<int> v;
vector<int> prefix;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> q;
    v.resize(n);
    prefix.resize(n+1);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for(int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i-1] + v[i-1];
    }
    for(int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l-1] << '\n';
    }
    return 0;
}
