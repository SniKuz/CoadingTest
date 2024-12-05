#include <bits/stdc++.h>

using namespace std;

int tc;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> tc;
    for(int t = 0; t < tc; t++)
    {
        int n, m;
        set<int> dict;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            int val;
            cin >> val;
            dict.insert(val);
        }
        cin >> m;
        for(int i = 0; i < m; i++)
        {
            int target;
            cin >> target;
            if(dict.find(target) != dict.end())
            {
                cout << 1 << '\n';
            }
            else
            {
                cout << 0 << '\n';
            }
        }
    }
    return 0;
}
