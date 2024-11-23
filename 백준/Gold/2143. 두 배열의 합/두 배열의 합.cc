#include <bits/stdc++.h>
#define ll long long

using namespace std;

int t, n, m;
vector<ll> A, B;
map<ll, ll> aM, bM;
ll ans = 0;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    cin >> n;
    A.resize(n+1);
    for(int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        A[i] = A[i-1] + temp;
    }
    for(int i = 0; i <= n; i++)
    {
        for(int j = i+1; j <= n; j++)
        {
            aM[A[j] - A[i]]++;
        }
    }
    cin >> m;
    B.resize(m+1);
    for(int i = 1; i <= m; i++)
    {
        int temp;
        cin >> temp;
        B[i] = B[i-1] + temp;
    }
    for(int i = 0; i <= m; i++)
    {
        for(int j = i+1; j <= m; j++)
        {
            bM[B[j] - B[i]]++;
        }
    }
    
    for(const auto& e : aM)
    {
        auto bCur = bM.find(t - e.first);
        if(bCur != bM.end())
        {
            ans += bCur->second * e.second;
        }
    }
    cout << ans;
    return 0;
}