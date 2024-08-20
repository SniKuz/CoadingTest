#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    unordered_map<string, int> group;
    for(const auto& order : orders)
    {
        for(int i = 2; i <= order.size(); i++)
        {
            int size = order.size();
            vector<int> c(size - i, 0);
            for(int j = 0; j < i; j++)
                c.push_back(1);
            do{
                set<char> temp;
                for(int j = 0; j < size; j++)
                {
                    if(c[j] != 0)
                    {
                        temp.insert(order[j]);
                    }
                }
                string tmp = "";
                for(const auto& e : temp)
                    tmp += e;
                //cout << tmp << ' ';
                if(group.find(tmp) != group.end())
                {
                    group[tmp]++;
                }
                else
                    group[tmp] = 1;
            } while(next_permutation(c.begin(), c.end()));
        }
    }
    map<int, vector<pair<int, string>>> m;
    for(const auto& kv : group)
    {
        if(kv.second < 2) continue;
        if(m.find(kv.first.size()) == m.end())
        {
            m[kv.first.size()] = {{kv.second, kv.first}};
        }
        else if(m[kv.first.size()].back().first == kv.second)
        {
            m[kv.first.size()].push_back({kv.second, kv.first});
        }
        else if(m[kv.first.size()].back().first < kv.second)
        {
            m[kv.first.size()] = {{kv.second, kv.first}};
        }
    }
    for(const auto& e : m)
    {
        for(const auto& s : course)
        {
            if(s == e.first)
            {
                for(const auto& n : e.second)
                {
                    answer.push_back(n.second);
                }
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}