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
        int temp;
        cin >> temp;
        if(v.empty() || v.back() < temp)
        {
            v.push_back(temp);
        }
        else
        {
            *lower_bound(v.begin(), v.end(), temp) = temp;
        }
    }
    cout << v.size();
    return 0;
}
