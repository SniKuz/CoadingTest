#include <bits/stdc++.h>

using namespace std;

int tc;

void Cycle(int start, vector<int> &nums, vector<bool> &visited)
{
    visited[start] = true;
    int cur = start;
    
    while(nums[cur] != start)
    {
        cur = nums[cur];
        visited[cur] = true;
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> tc;
    for(int t = 0; t < tc; t++)
    {
        int n;
        cin >> n;
        vector<int> nums(n+1);
        for(int i = 1; i <= n; i++)
            cin >> nums[i];
            
        int cnt = 0;
        vector<bool> visited(n+1);
        for(int i = 1; i <= n; i++)
        {
            if(visited[i] == false)
            {
                cnt++;
                Cycle(i, nums, visited);
            }   
        }
        cout << cnt << '\n';
    }
    return 0;
}
