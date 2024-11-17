#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> v;
vector<int> prefix;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    v.resize(n);
    prefix.resize(n+1);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        prefix[i+1] = prefix[i] + v[i];
    }
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l-1] << '\n';
    }
    return 0;
}
