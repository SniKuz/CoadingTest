#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        
        if(v.empty() || v.back() < input)
        {
            v.push_back(input);
        }
        else
        {
            *lower_bound(v.begin(), v.end(), input) = input;
        }
    }
    cout << v.size();
    return 0;
}
