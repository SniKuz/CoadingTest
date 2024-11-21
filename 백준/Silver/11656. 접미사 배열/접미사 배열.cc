#include <bits/stdc++.h>

using namespace std;

string str;
set<string> dict;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> str;
    for(int i = 0; i < str.size(); i++)
    {
        dict.insert(str.substr(i));
    }
    for(const auto& e : dict)
    {
        cout << e << '\n';
    }
    return 0;
}
