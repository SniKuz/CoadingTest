#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> m;
    for(const auto& p : participant)
    {
        if(m.find(p) == m.end())
            m[p] = 1;
        else
            m[p] += 1;
    }
    for(const auto& c : completion)
    {
        m[c] -= 1;
    }
    for(const auto& [key, val] : m)
    {
        if(val > 0)
            return key;
    }
    
    return 0;
}