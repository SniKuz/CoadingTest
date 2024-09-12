#include <bits/stdc++.h>

using namespace std;

int m, n, l;
vector<int> cannons;
int res = 0;

void binary(int x, int y, int s, int e)
{
    int mid = (s+e+1) / 2;
    if(y + abs(x - cannons[mid]) <= l)
    {
        res++;
        return;
    }
    if(s >= e) return;
    if(x <= cannons[mid])
    {
        binary(x, y, s, mid-1);
    }
    else
    {
        binary(x, y, mid, e);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> m >> n >> l;
    for(int i = 0; i < m; i++)
    {
        int cannon;
        cin >> cannon;
        cannons.push_back(cannon);
    }
    sort(cannons.begin(), cannons.end());
    
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        binary(x, y, 0, m-1);
    }
    cout << res;
}