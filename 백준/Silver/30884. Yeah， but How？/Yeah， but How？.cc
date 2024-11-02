#include <bits/stdc++.h>

using namespace std;

string input;
vector<char> v;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> input;
    for(const auto &e : input)
    {
        if(v.empty() == false && v.back() == '(' && e == ')')
        {
            v.push_back('1');
        }
        v.push_back(e);
    }
    int vSize = v.size();
    for(int i = 0; i < vSize; i++)
    {
        cout << v[i];
        if(i+1 < vSize && v[i] == ')' && v[i+1] == '(')
            cout << '+';
        
    }
    return 0;
}
