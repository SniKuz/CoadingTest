#include <bits/stdc++.h>

using namespace std;

int n;
int maxVal = 0;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    vector<int> ans(n);
    vector<int> inputs(n);
    
    for(int i = 0; i < n; i++)
    {
        cin >> inputs[i];
        maxVal = max(maxVal, inputs[i]);
    }
    maxVal++;
    
    ans[inputs.front()] = -1;
    set<int> visited;
    visited.insert(inputs.front());
    
    for(int i = 1; i < n; i++)
    {
        if (visited.find(inputs[i]) == visited.end())
        {
            ans[inputs[i]] = inputs[i-1];
        }
        visited.insert(inputs[i]);
    }
    
    cout << maxVal << '\n';
    for (int i = 0; i < maxVal; i++)
    {
        cout << ans[i] << ' ';
    }    
    return 0;
}