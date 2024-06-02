# include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> solution(100001);
    int N = 0;
    cin >> N;
    bool firstPositive = false;
    for(int i = 0; i < N; ++i)
    {
        cin >> solution[i];
    }
    int cur, ans = 2e9;
    int l = 0, r = N-1;
    while(l < r)
    {
        int cur = solution[l] + solution[r];
        ans = abs(ans) < abs(cur) ? ans : cur;

        if(cur > 0) r--;
        else if(cur < 0) l++;
        else break;
    }
    cout << ans;
    return 0;
}