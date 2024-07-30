#include <bits/stdc++.h>

#define start first
#define end second

using namespace std;

int k;
vector<int> v(1024);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k;
    int nodes = pow(2, k) - 1;
    for(int i = 0; i < nodes; i++)
    {
        cin >> v[i];
    }
    queue<pair<int, int>> q;
    queue<pair<int, int>> buf;
    q.push({0, nodes-1});
    while(!q.empty())
    {
        while(!q.empty())
        {
            auto cur = q.front(); q.pop();
            int mid = (cur.start + cur.end) / 2;
            cout << v[mid] << ' ';
            if(cur.start != cur.end)
            {
                buf.push({cur.start, mid-1});
                buf.push({mid+1, cur.end});
            }
        }
        cout << '\n';
        while(!buf.empty())
        {
            q.push(buf.front()); buf.pop();
        }
    }
}