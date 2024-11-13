#include <bits/stdc++.h>

using namespace std;

int m, n;
int sumVal = 0;
int minVal = INT_MAX;
set<int> keys;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    for(int i = 1; i <= 100; i++)
    {
        keys.insert(i*i);
    }
    for(; m <= n; m++)
    {
        if(keys.find(m) != keys.end())
        {
            sumVal += m;
            minVal = min(minVal, m);
        }
    }
    if(minVal == INT_MAX)  
        cout << -1;
    else
        cout << sumVal << '\n' << minVal << '\n';
    return 0;
}
