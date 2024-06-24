#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int N;
multiset<ll> s;
bool found = false;

void Solution(ll current, multiset<ll> currentSet, vector<ll> container)
{
    if(found) return;
    if(currentSet.find(current) == currentSet.end()) return;
    container.push_back(current);
    currentSet.erase(current);
    if(currentSet.size() == 0)
    {
        found = true;
        for(const auto& val : container)
            cout << val << ' ';
    }
    if(current % 3 == 0)
        Solution(current/3, currentSet, container);
    Solution(current*2, currentSet, container);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    vector<ll> v(N);
    for(int i = 0; i < N; ++i)
    {
        cin >> v[i];
        s.insert(v[i]);
    }

    vector<ll> tmpV;
    for(int i = 0; i < N; ++i)
    {
        Solution(v[i], s, tmpV);
    }

    return 0;
}