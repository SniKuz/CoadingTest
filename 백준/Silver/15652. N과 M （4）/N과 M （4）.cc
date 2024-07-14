#include <bits/stdc++.h>

using namespace std;

int n, m;

void solve(int s, int e, int cnt, vector<int> v)
{
    if(cnt == 0)
    {
        for(const auto& e : v)
        {
            cout << e << ' ';
        }
        cout << '\n';
        return;
    }
    cnt -= 1;
    for(int i = s; i <= e; i++)
    {
        v.push_back(i);
        solve(i, e, cnt, v);
        v.pop_back();
    }
}

int main()
{
    cin >> n >> m;
    solve(1, n, m, {});
}