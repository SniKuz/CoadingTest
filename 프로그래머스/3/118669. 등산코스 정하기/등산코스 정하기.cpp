#include <string>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

set<int> gateSet, summitSet;
vector<vector<pair<int, int>>> map(50001, vector<pair<int, int>>());
int ansSummit = 0, ansIntensity = 2e9;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {

    for(auto gate : gates)
        gateSet.insert(gate);
    for(auto summit : summits)
        summitSet.insert(summit);
    for(auto path : paths)
    {
        map[path[0]].push_back({-path[2], path[1]});
        map[path[1]].push_back({-path[2], path[0]});
    }    

    for(auto summit : summits)
    {
        vector<bool> visited(n, false);
        priority_queue<pair<int, int>> pq;

        for(auto s : summits)
            visited[s] = true;

        int intensity = -1;
        for(auto next : map[summit])
            pq.push(next);    

        while(!pq.empty())
        {
            auto current = pq.top(); pq.pop();
            visited[current.second] = true;
            intensity = intensity > -current.first ? intensity : -current.first;

            if(gateSet.find(current.second) != gateSet.end())
            {
                if(intensity == ansIntensity) 
                    ansSummit = ansSummit > summit ? summit : ansSummit;
                else if(ansIntensity > intensity) 
                {
                    ansSummit = summit;
                    ansIntensity = intensity;
                }
                break;
            }

            for(auto next : map[current.second])
            {
                if(visited[next.second]) continue;
                pq.push(next);
            }
        }       
    }
    return {ansSummit, ansIntensity};
}