#include <bits/stdc++.h>

using namespace std;

int n;

vector<set<int>> v(501);
vector<int> times(501);
vector<int> dp(501, -1);

int solution(int idx)
{
    if(dp[idx] < 0)
    {
        int time = 0;
        set<int> pending;
        for(const auto& e : v[idx])
        {
            if(pending.find(e) != pending.end()) //이미 한 놈인가?
                continue;
            if(dp[e] < 0)
            {
                dp[e] = solution(e);
            }
            time = max(time, dp[e]);
            for(const auto& ele : v[e])
            {
                pending.insert(ele);
            }
        }
        dp[idx] = time + times[idx];
    }
    return dp[idx];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> times[i];
        int before;
        cin >> before;
        if(before == -1)
        {
            dp[i] = times[i];
        }
        else
        {
            while(before != -1)
            {
                v[i].insert(before);
                cin >> before;
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        cout << solution(i) << '\n';
    }
}