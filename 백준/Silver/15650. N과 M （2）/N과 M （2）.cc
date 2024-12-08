#include <bits/stdc++.h>

using namespace std;

int n, m;
set<set<int>> ssi;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    vector<int> nums(n);
    for(auto itr = nums.rbegin(); itr != nums.rbegin() + m; itr++)
    {
        *itr = 1;
    }
    
    do
    {
        set<int> si;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 1)
            {
                si.insert(i+1);
            }
        }
        ssi.insert(si);
    } while(next_permutation(nums.begin(), nums.end()));
    
    for(const auto& si : ssi)
    {
        for(const auto& e : si)
        {
            cout << e << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
