#include <bits/stdc++.h>

using namespace std;

int tc;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> tc;
    for(int t = 0; t < tc; t++)
    {
        string str;
        cin >> str;
        bool printIt = false;
        auto copyStr = str;
        int cnt = 0;
        do
        {
            if(cnt++ == 1)
            {
                cout << str << '\n';
                printIt = true;
                break;
            }
        } while(next_permutation(str.begin(), str.end()));
        if(!printIt) cout << copyStr << '\n';
    }
    return 0;
}