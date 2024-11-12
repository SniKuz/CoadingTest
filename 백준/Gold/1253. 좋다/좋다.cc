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
        cin >> v[i];
    sort(v.begin(), v.end());
    
    for(int i = n-1; i >= 0; i--)
    {
        int l = 0, r = n-1;
        while(l < r)
        {
            if(i == r)
            {
                r--;
                continue;
            }
            if(i == l)
            {
                l++;
                continue;
            }
            
            int val = v[l] + v[r];
            if(val == v[i])
            {
                res++;
                break;
            }
            else if(val > v[i])
            {
                r--;
            }
            else
            {
                l++;
            }
        }
    }

    cout << res;
    return 0;
}
