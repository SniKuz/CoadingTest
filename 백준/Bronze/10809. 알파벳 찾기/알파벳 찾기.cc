#include <bits/stdc++.h>

using namespace std;

vector<int> alpha(26, -1);

int main() 
{
    string input;
    cin >> input;
    int idx = 0;
    for(const auto& c : input)
    {
        if(alpha[c - 'a'] == -1)
        {
            alpha[c - 'a'] = idx;
        }
        idx++;
    }
    for(const auto& e : alpha)
    {
        cout << e << ' ' ;
    }
    return 0;
}
