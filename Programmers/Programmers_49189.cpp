// https://school.programmers.co.kr/learn/courses/30/lessons/49189

#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

vector<vector<int>> table(20001, vector<int>(20001, -1));
vector<bool> visited(20001, false);
int answer = 0;

int solution(int n, vector<vector<int>> edge) {
    n += 1;
    for(auto e : edge)
    {
        table[e[0]][e[1]] = 1;
        table[e[1]][e[0]] = 1;
    }

    deque<int> que;
    visited[1] = true;
    que.push_back(1);

    while(!que.empty())
    {
        int cur = que.front();
        que.pop_front();

        for(int i = 1; i < n; i++)
        {
            if(visited[i] || table[cur][i] == -1) continue;
            visited[i] = true;
            que.push_back(i);
            table[i][i] += table[cur][cur];
        }
    }

    int furthest = 0;
    for(int i = 0; i < n; i++)
    {
        furthest = table[i][i] < furthest ? table[i][i] : furthest;
    }
    for(int i = 0; i < n; i++)
    {
        if(table[i][i] == furthest) answer++;
    }
    return answer;
}