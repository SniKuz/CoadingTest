#include <bits/stdc++.h>
#define ll long long

using namespace std;

int g;
bool possible = false;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> g;
    ll s = 1, e = 1;
    while(e <= g)
    {
        ll w = e*e - s*s;
        if(w >= g)
        {
            if(w == g)
            {
                cout << e << '\n';
                possible = true;
            }
            s++;
        }
        else
        {
            e++;
        }
    }
    if(possible == false)
        cout << -1;
    return 0;
}
