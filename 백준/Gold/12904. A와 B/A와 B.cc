#include <bits/stdc++.h>

using namespace std;

string s, t;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> s >> t;
    while(s.compare(t) != 0 && !t.empty())
    {
        if(t.back() == 'A')
        {
            t.pop_back();
        }
        else
        {
            t.pop_back();
            reverse(t.begin(), t.end());
        }
    }
    if(t.compare(s) == 0)
        cout << 1;
    else
        cout << 0;
    return 0;
}