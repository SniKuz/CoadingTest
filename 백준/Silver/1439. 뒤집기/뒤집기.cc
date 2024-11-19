#include <bits/stdc++.h>

using namespace std;

string str;
int cnt0 = 0, cnt1 = 0;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> str;
    int cur = 0;
    while(cur < str.size())
    {
        if(str[cur] == '0')
        {
            cnt0++;
            while(cur < str.size() && str[cur] == '0')
                cur++;
        }
        else
        {
            cnt1++;
            while(cur < str.size() && str[cur] == '1')
                cur++;
        }
    }
    cout << (cnt0 < cnt1 ? cnt0 : cnt1);
    return 0;
}
