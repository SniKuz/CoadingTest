#include <bits/stdc++.h>

using namespace std;

string str;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> str;
    int strSize = str.size();
    int lower2upper = 'A' - 'a';
    int upper2lower = 'a' - 'A';
    for(int i = 0; i < strSize; i++)
    {
        if('Z' < str[i])
        {
            str[i] += lower2upper;
        }
        else
        {
            str[i] += upper2lower;
        }
    }
    cout << str;
    return 0;
}
