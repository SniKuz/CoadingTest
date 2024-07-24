#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> tall;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    tall.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> tall[i];
    }
    sort(tall.begin(), tall.end());
    priority_queue<int> pq;
    for(int i = 1; i < n; i++)
    {
        pq.push(tall[i] - tall[i-1]);
    }
    for(int i = 1; i < k; i++)
    {
        pq.pop();
    }
    unsigned long long res = 0;
    while(!pq.empty())
    {
        res += pq.top();
        pq.pop();
    }
    cout << res;
}