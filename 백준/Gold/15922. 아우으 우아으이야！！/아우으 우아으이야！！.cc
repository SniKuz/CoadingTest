#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    if(N == 1)
    {
        int x, y;
        cin >> x >> y;
        cout << y - x;
        return 0;
    }
    
    vector<pair<int, int>> v(100001);
    for(int i = 0; i < N; ++i)
    {
        int x, y;
        cin >> x >> y;
        v[i] = {x, y};
    }

    int ans = 0;
    int i = 0;
    while(i < N)
    {
        int s = v[i].first;
        int e = v[i].second;
        while(i+1 < N && e > v[i+1].first)
        {
            ++i;
            e = e < v[i].second ? v[i].second : e;
        }
        ans += e - s;
        i++;
    }
    cout << ans;

    return 0;
}