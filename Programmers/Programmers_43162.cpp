//https://school.programmers.co.kr/learn/courses/30/lessons/43162

#include <string>
#include <vector>
#include <iostream>

using namespace std;
int answer = 0;

int Find(int u, vector<int> &unionMap)
{
    if(unionMap[u] < 0) return u;
    unionMap[u] = Find(unionMap[u], unionMap);
    return unionMap[u];
}
void Merge(int u, int v, vector<int> &unionMap)
{
    u = Find(u, unionMap);
    v = Find(v, unionMap);
    if(u==v) return;
    unionMap[u] += unionMap[v];
    unionMap[v] = u;;
}
int solution(int n, vector<vector<int>> computers) {
    vector<int> unionMap(n, -1);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i==j) continue;
            if(computers[i][j] == 1)
            {
                Merge(i, j, unionMap);
            }
        }
    }
    for(auto u : unionMap)
    {
        cout << u << ' ';
        if(u < 0) answer++;
    }
    return answer;
}