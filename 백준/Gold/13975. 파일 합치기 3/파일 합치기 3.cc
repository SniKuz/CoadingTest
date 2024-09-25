#include <bits/stdc++.h>
#define ll long long

using namespace std;

int t;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for(int j = 0; j < n; j++)
        {
            ll num;
            cin >> num;
            pq.push(num);
        }
        ll res = 0;
        while(pq.size() > 1)
        {
            auto x1 = pq.top(); pq.pop();
            auto x2 = pq.top(); pq.pop();
            pq.push(x1+x2);
            res += x1 + x2;
        }
        cout << res << '\n';
    }
}