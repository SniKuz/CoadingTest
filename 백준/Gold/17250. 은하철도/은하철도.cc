#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, m;
vector<ll> parents(100001);

int Find(int a)
{
    if(parents[a] < 0) return a;
    return parents[a] = Find(parents[a]);
}

void MakeUnion(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if(a == b) return;
    parents[a] += parents[b];
    parents[b] = a;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        ll val;
        cin >> val;
        parents[i] = -val;
    }
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        MakeUnion(a, b);
        cout << -parents[Find(a)] << '\n';
    }
    return 0;
}
