#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v(1000);
vector<int> L;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for(int i = n-1; i >= 0; i--)
    {
        if(L.empty() || (L.back() < v[i]))
        {
            L.push_back(v[i]);
        }
        else if(L.back() > v[i])
        {
            auto itr = lower_bound(L.begin(), L.end(), v[i]);   
            *itr = v[i];
        }
    }
    cout << L.size();
}