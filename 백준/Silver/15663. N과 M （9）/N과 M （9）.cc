#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> v;
set<vector<int>> s;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    v.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    
    do
    {
        vector<int> permutation(v.begin(), v.begin() + m);
        s.insert(permutation);
    } while(next_permutation(v.begin(), v.end()));
    
    for(const auto& group : s)
    {
        for(const auto& e : group)
        {
            cout << e  << ' ';
        }
        cout << '\n';
    }
    return 0;
}
