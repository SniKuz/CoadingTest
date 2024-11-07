#include <bits/stdc++.h>

using namespace std;

int tc;

int GCA(int a, int b)
{
    if(b == 0) return a;
    return GCA(b, a%b);
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> tc;
    for(int t = 0; t < tc; t++)
    {
        int a, b;
        cin >> a >> b;
        if(a < b)
        {
            int temp = a;
            a = b;
            b = temp;
        }
        cout << (a*b) / GCA(a, b) << '\n';
    }
    return 0;
}
