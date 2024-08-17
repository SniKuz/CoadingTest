#include <bits/stdc++.h>

using namespace std;

int solution(string s)
{
    if(s.empty() || s.size() % 2 != 0)
        return 0;

    vector<char> v;
    for(size_t i = 0; i < s.size() ; ++i)
    {
        if(v.empty() || v.back() != s[i])
            v.push_back(s[i]);
        else
            v.pop_back();
    }
    
    if(v.empty())
        return 1;
    return 0;
}