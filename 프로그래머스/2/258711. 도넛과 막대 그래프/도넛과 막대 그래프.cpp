#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

bool CheckDonut(int i);
void CheckInf(int i);

vector<char> visited(1000001);
vector<int> outDegrees(1000001);
vector<int> inDegrees(1000001);
vector<vector<int>> cache(1000001);
int maxNum = 0;
vector<int> answer; // 무관한 정점, 도넛, 막대, 8자

vector<int> solution(vector<vector<int>> edges) {    

    // 1. inDegree가 0이고 outDegree가 2개이상이면 얘가 무조건 무관한 정점
    for(auto edge : edges)
    {
        outDegrees[edge[0]]++;
        inDegrees[edge[1]]++;
        cache[edge[0]].push_back(edge[1]);
        maxNum = maxNum > edge[0] ? maxNum : edge[0];
        maxNum = maxNum > edge[1] ? maxNum : edge[1];
    }
    maxNum++;
    for(int i = 1; i < maxNum; i++)
    {
        if(inDegrees[i] == 0 & outDegrees[i] > 1)
        {
            visited[i]++;
            answer = {i, 0, 0, 0};

            for(auto edge : cache[i])
            {
                inDegrees[edge]--;
            }
            break;
        }
    }

    //2. 무관한 정점을 없앴을 때 그래프들의 개수. inDegree가 1개도 없는게 막대그래프에 시작정점
    for(int i = 1; i < maxNum; i++)
    {
        if(visited[i] > 0) continue;

        if (inDegrees[i] == 0)
        {
            int node = i;
            while(!cache[node].empty())
            {
                visited[node]++;
                node = cache[node][0];
            }
            visited[node]++;
            answer[2]++;
        }
    }
    for(int i = 1; i < maxNum; i++)
    {
        if(visited[i] > 0) continue;

        if(CheckDonut(i))
        {
            answer[1]++;
        }
        else
            answer[3]++;    
    }

    return answer;
}

bool CheckDonut(int i)
{
    bool isDonut = true;
    visited[i]++;
    int node = cache[i][0];
    while(true)
    {
        visited[node]++;
        if(cache[node].size() > 1)
        {
            isDonut = false;
            if(visited[cache[node][0]] > 0 && visited[cache[node][1]] > 0)
            {
                break;
            }
            else
            {
                node = visited[cache[node][0]] > 0 ? cache[node][1] : cache[node][0];
            }
        }
        else if(node == i && isDonut)
        {
            break;
        }
        else
        {
            node = cache[node][0];
        }

    }

    return isDonut;
}