#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> input;
vector<int> v;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    input.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    for(auto itr = input.rbegin(); itr != input.rend(); itr++)
    {
        if(v.empty() || v.back() < *itr)
        {
            v.push_back(*itr);
        }
        else
        {
            *lower_bound(v.begin(), v.end(), *itr) = *itr;
        }
    }
    cout << n - v.size();
    return 0;
}
