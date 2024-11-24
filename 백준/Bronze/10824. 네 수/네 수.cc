#include <bits/stdc++.h>

using namespace std;

string a, b, c, d;

int main() 
{
    cin >> a >> b >> c >> d;
    a += b;
    c += d;
    long long sum = stoll(a) + stoll(c);
    cout << sum;
    return 0;
}
