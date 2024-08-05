#define endPos first
#define startPos second

#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    vector<pair<int, int>> v;

    for(int i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;
        v.push_back({e, s});
    }
    sort(v.begin(), v.end());
    int cnt = 1;
    auto lastE = v.front();
    for(int i = 1; i < v.size(); i++)
    {
        auto cur = v[i];
        if(cur.startPos >= lastE.endPos)
        {
            lastE = cur;
            cnt++;
        }
    }
    cout << cnt;
}