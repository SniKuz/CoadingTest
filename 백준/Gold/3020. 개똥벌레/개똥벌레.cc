#include <bits/stdc++.h>

using namespace std;

int N, H;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> H;
    vector<int> down, up;
    int d, u;
    for(int i = 0; i < N/2; ++i)
    {
        cin >> d >> u;
        down.push_back(d); up.push_back(u);
    }

    sort(down.begin(), down.end());
    sort(up.begin(), up.end());
    int min = 2e9, cnt = 0;
    for(int i = 0; i < H; ++i)
    {
        int curDown = lower_bound(down.begin(), down.end(), i) - down.begin();;
        int curUp = lower_bound(up.begin(), up.end(), H - i + 1) - up.begin();
        int cur = N - curDown - curUp;

        if(cur < min)
        {
            min = cur;
            cnt = 1;
        }
        else if(cur == min) cnt++;
    }

    cout << min << ' ' << cnt;

    return 0;
}