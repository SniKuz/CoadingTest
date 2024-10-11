#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

map<pii, set<int>> builds;

bool Check()
{
    for(const auto &build : builds)
    {
        auto pos = build.first;
        auto types = build.second;
        for(const auto &type : types)
        {
            if(type == 0) // 기둥
            {
                if(pos.Y == 0) continue;
                if(builds[{pos.X-1, pos.Y}].find(1) != builds[{pos.X-1, pos.Y}].end() || builds[{pos.X, pos.Y}].find(1) != builds[{pos.X, pos.Y}].end()) continue;
                if(builds[{pos.X, pos.Y-1}].find(0) != builds[{pos.X, pos.Y-1}].end()) continue;
                return false;
            }
            else
            {
                if(builds[{pos.X, pos.Y-1}].find(0) != builds[{pos.X, pos.Y-1}].end() || builds[{pos.X+1, pos.Y-1}].find(0) != builds[{pos.X+1, pos.Y-1}].end()) continue;
                if(builds[{pos.X-1, pos.Y}].find(1) != builds[{pos.X-1, pos.Y}].end() && builds[{pos.X+1, pos.Y}].find(1) != builds[{pos.X+1, pos.Y}].end()) continue;
                return false;
            }
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    for(const auto &cmd : build_frame)
    {
        int x = cmd[0], y = cmd[1], type = cmd[2], cd = cmd[3];
        if(cd == 0) // delete
        {
            builds[{x, y}].erase(type);
            if(Check() == false)
            {
                builds[{x, y}].insert(type);
            }
        }
        else // create
        {
            builds[{x, y}].insert(type);
            if(Check() == false)
                builds[{x, y}].erase(type);
        }
    }
    
    vector<vector<int>> answer;
    for(const auto & build : builds)
    {
        auto pos = build.first;
        auto types = build.second;
        for(const auto &type : types)
            answer.push_back({pos.X, pos.Y, type});
    }
    sort(answer.begin(), answer.end());
    return answer;
}

/*
벽면 벗어낙 ㅔ설치하는 경우 없음
바닥에 보 설치도 안함
구조물이 겹치게는 안함(기둥 같은 곳 2개 설치X)
x,y 지점에 기둥, 보 둘다 설치 가능

*/