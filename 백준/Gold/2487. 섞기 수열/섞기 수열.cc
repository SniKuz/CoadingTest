#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> nums;
vector<bool> visited;
vector<int> cnts;
int res = 1;

void CheckRotate()
{
    for(int i = 1; i <= n; i++)
    {
        if(visited[i]) continue;
        
        int cnt = 1;
        int cur = nums[i];
        visited[cur] = true;
        while(i != cur)
        {
            cur = nums[cur];
            visited[cur] = true;
            cnt++;
        }
        res *= (cnt / gcd(cnt, res));
    }
}

int lcd(int a, int b)
{
    if(b == 0) return a;
    return lcd(b, a%b);
}

int gcd(int a, int b)
{
    return a*b/lcd(a,b);
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    nums.resize(n+1);
    visited.resize(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }
    
    CheckRotate();
    cout << res;
    return 0;
}
/*
최초 9% 2번째 28% > 
*/