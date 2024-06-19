#include <bits/stdc++.h>

#define MAX 1000001
using namespace std;

int N, L;
vector<pair<int, int>> v;
vector<int> road(MAX); 

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> L;

    for(int i = 0; i < N; ++i)
    {
        int s, e;
        cin >> s >> e;
        v.push_back({s, e});
    }
    sort(v.begin(), v.end());

    int cnt = 0;
    int cur = 0;
    for(int i = 0; i < N; ++i)
    {
        if(v[i].first <= cur && cur < v[i].second)
        {
            int val = (v[i].second - cur) / L;
            int left = (v[i].second - cur) % L;

            cnt += val;
            cur += val * L;
            
            if(left > 0)
            {
                cnt += 1;
                cur += L;
            }
        }
        else if(cur < v[i].first)
        {
            cur = v[i].first;
            --i;
        }
    }
    cout << cnt;
    return 0;
}