#include <bits/stdc++.h>

using namespace std;

int cnt = 0;

int main() 
{
    for(int i = 0; i < 8; i++)
    {
        string str;
        cin >> str;
        for(int j = 0; j < 8; j++)
        {
            if(str[j] == 'F' && (i+j)%2 == 0)
                cnt++;
        }
    }
    cout << cnt;
    return 0;
}
