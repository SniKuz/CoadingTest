#include <bits/stdc++.h>
using namespace std;

int tc;

int main() 
{
    cin >> tc;
    for(int t = 0; t < tc; t++)
    {
        string input;
        cin >> input;
        cout << input.front() << input.back() << '\n';
    }
    return 0;
}
