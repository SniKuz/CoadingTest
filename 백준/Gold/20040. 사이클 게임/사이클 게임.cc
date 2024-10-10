#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> parents(500001, -1);
int cycle = -1;

int Find(int x)
{
    if(parents[x] < 0) return x;
    return parents[x] = Find(parents[x]);
}

void MakeUnion(int x, int y, int turn)
{
    x = Find(x);
    y = Find(y);
    if(x == y) 
    {
        if(cycle < 0)
        {
            cycle = turn;
        }
        return;
    }
    parents[x] += parents[y];
    parents[y] = x;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin  >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        MakeUnion(x, y, i);
    }
    if(cycle < 0) cout << 0;
    else cout << cycle;
    return 0;
}
