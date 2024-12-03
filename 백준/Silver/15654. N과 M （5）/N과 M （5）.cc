#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<int> datas;
set<vector<int>> s;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    datas.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> datas[i];
    }
    sort(datas.begin(), datas.end());
    
    do
    {
        vector<int> v(datas.begin(), datas.begin() + m);
        s.insert(v);
    } while(next_permutation(datas.begin(), datas.end()));
    
    for(const auto& l : s)
    {
        for(const auto& e : l)
        {
            cout << e << ' ';
        }
        cout << '\n';
    }
    return 0;
}
