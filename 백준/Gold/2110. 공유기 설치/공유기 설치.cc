#include <bits/stdc++.h>

using namespace std;

int n, c;
vector<int> wifi;
int s = 0, e = 0;
int res = 0;

bool IsPossible(int mid)
{
    int cnt = 1;
    int prev = wifi[0];
    for(int i = 1; i < n; i++)
    {
        if(wifi[i] - prev >= mid)
        {
            cnt++;
            prev = wifi[i];
        }
    }
    return cnt >= c;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> c;
    wifi.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> wifi[i];
    }
    sort(wifi.begin(), wifi.end());
    e = wifi.back() - wifi.front();
    while(s < e)
    {
        int mid = (s+e+1) / 2;
        // cout << s << ' ' << mid << ' ' << e << '\n';
        if(IsPossible(mid))
        {
            res = mid;
            s = mid;
        }
        else
        {
            e = mid - 1;
        }
    }
    cout << res;
    return 0;
}