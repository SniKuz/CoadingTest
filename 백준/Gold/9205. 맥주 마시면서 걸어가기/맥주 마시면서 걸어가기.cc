#include <bits/stdc++.h>
#define coord pair<int, int>
#define X first
#define Y second

using namespace std;

int tc;

bool Reachable(coord a, coord b)
{
    return( abs(a.X - b.X) + abs(a.Y - b.Y)) <= 1000;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> tc;
    for (int t = 0; t < tc; t++)
    {
        int n;
        cin >> n;
        coord home, festival;
        vector<coord> CU(n);
        cin >> home.X >> home.Y;
        for (int i = 0; i < n; i++)
        {
            cin >> CU[i].X >> CU[i].Y;
        }
        cin >> festival.X >> festival.Y;
        
        queue<coord> q;
        q.push(home);
        bool reachable = false;
        vector<bool> visited(n);
        
        while (q.empty() == false)
        {
            auto cur = q.front(); q.pop();
            if (Reachable(cur, festival))
            {
                reachable = true;
                break;
            }
            for (int i = 0; i < n; i++)
            {
                if (visited[i] == false && Reachable(cur, CU[i]))
                {
                    visited[i] = true;
                    q.push(CU[i]);
                }
            }
        }
        
        cout << (reachable ? "happy\n" : "sad\n");
    }
    return 0;
}