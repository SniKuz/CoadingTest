#include <bits/stdc++.h>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    vector<char> v;
    set<char> s;
    for(auto sk : skill)
    {
        v.push_back(sk);
        s.insert(sk);
    }
    
    for(auto skillTree : skill_trees)
    {
        int precede = 0;
        bool check = true;
        for(auto flow : skillTree)
        {
            if(s.find(flow) != s.end())
            {
                if(flow == v[precede])
                {
                    precede++;
                }
                else
                {
                    check = false;
                    break;
                }
            }
        }
        if(check) answer++;
    }
    return answer;
}