#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;
int res = 0;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
   cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    int l = 0, r = n-1;
    while(l < r)
    {
        res = max(res, (r-l-1) * min(v[l], v[r]));
        if(v[l] < v[r])
        {
            l++;
        }
        else if(v[l] == v[r])
        {
            l++; r--;
        }
        else
        {
            r--;
        }
    }
    cout << res;
    return 0;
}
