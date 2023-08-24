//https://school.programmers.co.kr/learn/courses/30/lessons/43164

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

map<string, vector<string>> table;
map<string, vector<bool>> used;
vector<string> route;
int cnt = 0;
int ticketSize;
vector<string> answer;

void DFS(string cur)
{
    route.push_back(cur);
    cnt++;
    
    
    if(cnt == ticketSize){
        if(answer.empty()) answer = route;
        for(auto i : used)
        {
            cout << i.first << ":" ;
            for(auto j : i.second)
                cout << j << ' ';
            cout <<'\n';
        }
        for(auto r : route)
            cout << r << ' ';
        cout << "\n=========\n";
        return ;
    }
    for(int i = 0; i < table[cur].size(); i++)
    {
        if(!used[cur][i])
        {
            used[cur][i] = true;
            DFS(table[cur][i]);
            used[cur][i] = false;
        }
    }
    cnt--;
    route.pop_back();
    return ;
}

vector<string> solution(vector<vector<string>> tickets) {
    ticketSize = tickets.size()+1;
    for(auto ticket : tickets)
    {
            table[ticket[0]].push_back(ticket[1]);
            used[ticket[0]].push_back(false);
    }

    for(auto &line : table)
    {
        sort(line.second.begin(), line.second.end());
    }

    DFS("ICN");

    return answer;
}

/*
주어진 항공권을 모두 써야함...
무조건 정답이 있음
*/