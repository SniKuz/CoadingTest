#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    queue<ll> q;
    unordered_set<ll> mem;
    q.push(n);
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        if(cur == m)
        {
            cout << "YES";
            return 0;
        }
        if(cur == 1) continue;
        if(cur % 2 == 0)
        {
            if(mem.find(cur/2) == mem.end())
            {
                q.push(cur/2);
                mem.insert(cur/2);
            }
        }
        else
        {
            if(mem.find((cur-1)/2) == mem.end())
            {
                q.push((cur-1)/2);
                mem.insert((cur-1)/2);
            }
            if(mem.find((cur-1)/2 + 1) == mem.end())
            {
                q.push((cur-1)/2 + 1);
                mem.insert((cur-1)/2 + 1);
            }
        }
    }
    cout << "NO";
    return 0;
}