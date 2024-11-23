#include <bits/stdc++.h>

using namespace std;

set<string> s;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    cin >> str;
    int strSize = str.size();
    for(int i = 0; i < strSize; i++)
    {
        for(int j = 1; j <= strSize - i; j++)
        {
            s.insert(str.substr(i, j));
        }
    }
    cout << s.size();
    return 0;
}
