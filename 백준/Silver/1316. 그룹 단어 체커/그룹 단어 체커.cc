#include <bits/stdc++.h>

using namespace std;

int n;
int res = 0;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        int cur = 0;
        int strSize = str.size();
        vector<bool> alpha(27);
        bool checker = true;
        while(cur < strSize)
        {
            auto curChar = str[cur];
            if(alpha[curChar - 'a'] == false)
            {
                alpha[curChar - 'a'] = true;
                while(cur < strSize && str[cur] == curChar)
                    cur++;
            }
            else
            {
                checker = false;
                break;
            }
        }
        if(checker)
        {
            res++;
        }
    }
    cout << res;
    return 0;
}
