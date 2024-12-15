#include <bits/stdc++.h>

using namespace std;

int n;
string k;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    int even = 0, odd = 0;
    for(const auto& e : k)
    {
        if((e - '0') % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }
    if(even == odd)
    {
        cout << -1;
    }
    else if(even > odd)
    {
        cout << 0;
    }
    else // even < odd
    {
        cout << 1;
    }
    return 0;
}
