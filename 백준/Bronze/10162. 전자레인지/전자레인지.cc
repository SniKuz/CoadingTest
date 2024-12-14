#include <bits/stdc++.h>

using namespace std;

int t;
int a = 0, b = 0, c= 0;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t >= 300)
    {
        a++;
        t -= 300;
    }
    while(t >= 60)
    {
        b++;
        t -= 60;
    }
    while(t >= 10)
    {
        c++;
        t -= 10;
    }

    if(t != 0)
    {
        cout << -1;
    }
    else
    {
        cout << a << ' ' << b << ' ' << c;
    }
    return 0;
}
