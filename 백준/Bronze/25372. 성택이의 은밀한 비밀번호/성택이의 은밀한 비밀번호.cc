#include <bits/stdc++.h>

using namespace std;

int n;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        if(str.size() < 6 || str.size() > 9)
            cout << "no\n";
        else
            cout << "yes\n";
    }
    return 0;
}
