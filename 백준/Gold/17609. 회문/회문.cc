#include <bits/stdc++.h>

using namespace std;

int tc;

bool CheckPalin(const string& str, int l, int r)
{
    while(l < r)
    {
        if(str[l] == str[r])
        {
            l++;
            r--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

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
        int l = 0, r = str.size()-1;
        int res = 0;
        while(l < r)
        {
            if(str[l] == str[r])
            {
                l++;
                r--;
            }
            else
            {
                bool left = CheckPalin(str, l+1, r);
                bool right = CheckPalin(str, l, r-1);
                if(left || right)
                    res = 1;
                else
                    res = 2;
                break;
            }
        }
        cout << res << '\n';
    }
    return 0;
}