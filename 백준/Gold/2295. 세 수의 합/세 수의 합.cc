#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> nums;
map<int, int> kz;
int res = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    nums.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    for(int k = 0; k < n; k++)
    {
        for(int z = 0; z < n; z++)
        {
            if(nums[k] >= nums[z])
                kz.insert({nums[k] - nums[z], nums[k]});
        }
    }
    for(int x = 0; x < n; x++)
    {
        for(int y = 0; y < n; y++)
        {
            int val = nums[x] + nums[y];
            if(kz.find(val) != kz.end() && res < kz[val])
                res = kz[val];
        }
    }
    cout << res;
}