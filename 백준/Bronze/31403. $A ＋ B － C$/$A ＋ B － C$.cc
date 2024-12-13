#include <bits/stdc++.h>

using namespace std;

string a, b, c;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> a >> b >> c;
    cout << stoi(a) + stoi(b) - stoi(c) << '\n';
    a += b;
    cout << stoi(a) - stoi(c);
    return 0;
}
