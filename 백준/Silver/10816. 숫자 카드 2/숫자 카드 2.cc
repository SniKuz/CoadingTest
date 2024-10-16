#include <bits/stdc++.h>

using namespace std;

int n, m;
map<int, int> dict;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        dict[val]++;
    }
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int key;
        cin >> key;
        cout << dict[key] << ' ';
    }
    return 0;
}
