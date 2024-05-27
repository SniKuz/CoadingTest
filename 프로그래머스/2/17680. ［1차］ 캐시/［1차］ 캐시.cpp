#include <bits/stdc++.h>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if(cacheSize == 0) return cities.size() * 5;
    int answer = 0;
    
    unordered_map<string, int> m;
    for(auto& city : cities)
    {
        for(int i = 0; i < city.size(); i++)
            city[i] = tolower(city[i]);
        
        if(m.find(city) == m.end())
        {
            if(m.size() < cacheSize)
            {
                m[city] = 0;
            }
            else
            {
                pair<string, int> target {"", -1};
                for(const auto& [key, value] : m)
                {
                    if(target.second < value)
                    {
                        target.first = key;
                        target.second = value;
                    }
                }
                m.erase(target.first);
                m[city] = 0;
            }
            answer += 5;
        }
        else
        {
            m[city] = 0;
            answer += 1;
        }
        for(auto& [key, value] : m)
            ++value;
    }
    
    return answer;
}