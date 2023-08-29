// https://school.programmers.co.kr/learn/courses/30/lessons/118669?language=cpp

#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <iostream>

using namespace std;
int ansGate;
int ansIntensity = 2e9;
vector<vector<pair<int, int>>> map(50001, vector<pair<int, int>>()); // map[a] = {w1,b1}, {w2,b2},... : a-(w)->b
priority_queue<pair<int, int>> pq;
unordered_set<int> gatesS;
unordered_set<int> summitsS;



vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    //Init
    for(auto path : paths)
    {
        map[path[0]].push_back({-path[2], path[1]});
        map[path[1]].push_back({-path[2], path[0]});
    }
    for(auto gate : gates)
    {
        gatesS.insert(gate);
    }
    for(auto summit : summits)
    {
        summitsS.insert(summit);
    }
    

    for(auto gate : gates)
    {
        for(auto summit : summits)
        {
            vector<bool> visited(n, false);
            int tmpIntensity = -1;
            visited[gate] = true;
            for(auto next : map[gate])
            {
                pq.push(next);
            }

            while(!pq.empty())
            {
                auto current = pq.top();
                pq.pop();
                visited[current.second] = true;
                if(-current.first > tmpIntensity) tmpIntensity = -current.first;
                if(current.second == summit)
                {
                    if(ansIntensity == tmpIntensity) ansGate = ansGate < current.second ? ansGate : current.second;
                    else if(ansIntensity > tmpIntensity)
                    {
                        ansGate = current.second;
                        ansIntensity = tmpIntensity;
                    }
                    break;
                }

                for(auto next : map[current.second])
                {
                    if(summitsS.find(next.second) != summitsS.end()) 
                        if(summit == next.second) continue;
                    if(gatesS.find(next.second) != gatesS.end()) continue;
                    if(visited[next.second]) continue;
                    pq.push(next);
                }
            }
        }
    }
    return {ansGate, ansIntensity};
}

/*
summit과 gate를 반대로 쓴 죄.
시간초과가 뜬 죄
*/