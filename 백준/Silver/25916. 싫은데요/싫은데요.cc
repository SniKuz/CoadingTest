#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, m;
vector<int> v(500001);
ll totalW = 0;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    int s = 0, e = 0;
    ll curW = 0;
    while(s <= e && e < n)
    {
        if(curW + v[e] <= m)
        {
            curW += v[e++];
        }
        else if(s == e && v[e] > m)
        {
            s++; e++;
        }
        else
        {
            curW -= v[s++];
        }
        totalW = max(totalW, curW);
    }
    cout << totalW;
    return 0;
}
