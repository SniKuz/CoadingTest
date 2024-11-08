#include <bits/stdc++.h>

using namespace std;

int GCA(int a, int b)
{
    if(b == 0) return a;
    return GCA(b, a%b);
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b;
    cin >> a >> b;
    if(a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    int gca = GCA(a, b);
    cout << gca << '\n' << (a*b) / gca;
    return 0;
}
