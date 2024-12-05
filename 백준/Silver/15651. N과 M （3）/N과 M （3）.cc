#include <bits/stdc++.h>

using namespace std;

set<vector<int>> s;
int n, m;

void BF(vector<int> v, int cnt)
{
    if(cnt == m)
    {
        s.insert(v);
        return;
    }
    for(int i = 1; i <= n; i++)
    {
        v.push_back(i);
        BF(v, cnt+1);
        v.pop_back();
    }
}
int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    
    BF({}, 0);
    
    for(const auto& group : s)
    {
        for(const auto& e : group)
        {
            cout << e << ' ';
        }
        cout << '\n';
    }
    return 0;
}
