#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> parents(300001, -1);

int Find(int x)
{
    if(parents[x] < 0) return x;
    return parents[x] = Find(parents[x]);
}

void MakeUnion(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if(x == y) return;
    parents[x] += parents[y];
    parents[y] = x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i = 0; i < n-2; i++)
    {
        int a, b;
        cin >> a >> b;
        MakeUnion(a, b);
    }
    vector<int> res;
    for(int i = 1; i <= n; i++)
    {
        if(parents[i] < 0)
            res.push_back(i);
    }
    for(const auto &node : res)
    {
        cout << node << ' ';
    }
}