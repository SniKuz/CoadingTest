#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

int big = -1;
pii pos;

int main() 
{
    for(int i = 1; i <= 9; i++)
    {
        for(int j = 1; j <= 9; j++)
        {
            int temp;
            cin >> temp;
            if(big < temp)
            {
                big = temp;
                pos = {i, j};
            }
        }
    }
    cout << big << '\n' << pos.first << ' ' << pos.second;
    return 0;
}
