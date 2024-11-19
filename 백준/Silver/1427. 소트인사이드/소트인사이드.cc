#include <bits/stdc++.h>

using namespace std;

string str;
vector<int> v;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> str;
    for(const auto& c : str)
    {
        v.push_back(c - '0');
    }
    sort(v.begin(), v.end());
    for(auto itr = v.rbegin(); itr != v.rend(); itr++)
    {
        cout << *itr;
    }
    return 0;
}
