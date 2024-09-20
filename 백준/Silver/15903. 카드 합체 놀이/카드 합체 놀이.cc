#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, m;
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        pq.push(temp);
    }
    while(m > 0)
    {
        m--;
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        ll ab = a + b;
        pq.push(ab); pq.push(ab);
    }
    ll res = 0;
    while(pq.empty() == false)
    {
        auto cur = pq.top(); pq.pop();
        res += cur;
    }
    cout << res;
}