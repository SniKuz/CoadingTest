#include <bits/stdc++.h>

using namespace std;

int tc;

int Check(const vector<int>& v, int root, int cur)
{
    int cnt = 1;
    while(cur != root)
    {
        cnt++;
        cur = v[cur];
    }
    return cnt;
}

void Search(int& team, const vector<int>& v, vector<bool>& invalid, vector<bool>& visited, int cur)
{
    visited[cur] = true;
    int next = v[cur];
    if(invalid[next] == false)
    {
        if(visited[next])
        {
            team += Check(v, cur, next);
        }
        else
        {
            Search(team, v, invalid, visited, next);
        }
    }
    
    visited[cur] = false;
    invalid[cur] = true;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> tc;
    for(int t = 0; t < tc; t++)
    {
        int n;
        cin >> n;
        int team = 0;
        vector<int> v(n+1);
        vector<bool> invalid(n+1);
        vector<bool> visited(n+1);
        for(int i = 1; i <= n; i++)
        {
            cin >> v[i];
            if(v[i] == i)
            {
                team++;
                invalid[i] = true;
            }
        }
        
        for(int i = 1; i <= n; i++)
        {
            if(invalid[i] == false)
            {
                Search(team, v, invalid, visited, i);
            }
        }
        cout << n - team << '\n';
    }
    return 0;
}
