#include <bits/stdc++.h>

using namespace std;

#define leftTime first
#define planNum second

vector<string> Split(string str)
{
    istringstream iss(str);
    string buffer;
    vector<string> ret;
    
    while(getline(iss, buffer, ':'))
    {
        ret.push_back(buffer);
    }
    return ret;
}

int GetTime(string str)
{
    auto time = Split(str);
    return stoi(time[0]) * 60 + stoi(time[1]);
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    
    sort(plans.begin(), plans.end(), 
         [](vector<string> a, vector<string> b) 
         { 
             auto aTime = GetTime(a[1]); 
             auto bTime = GetTime(b[1]);
             return aTime < bTime;
         });
    
    int startTime = GetTime(plans[0][1]);
    int endTime = GetTime(plans.back()[1]);
    vector<pair<int, int>> stack; // leftTime, plansNum
    int currentIndex = 0;
    int NextTime = startTime;
    for(int i = startTime; i < endTime; ++i)
    {
        if(!stack.empty())
        {
            stack.back().leftTime -= 1;
            if(stack.back().leftTime == 0)
            {
                answer.push_back(plans[stack.back().planNum][0]);
                stack.pop_back();
            }
        }
        if(NextTime == i)
        {
            stack.push_back({stoi(plans[currentIndex][2]), currentIndex++});
            NextTime = GetTime(plans[currentIndex][1]);
        }
    }
    
    if(!stack.empty())
    {
        stack.back().leftTime -= 1;
        if(stack.back().leftTime == 0)
        {
            answer.push_back(plans[stack.back().planNum][0]);
            stack.pop_back();
        }
    }
    stack.push_back({stoi(plans[currentIndex][2]), currentIndex});
    
    while(!stack.empty())
    {
        answer.push_back(plans[stack.back().planNum][0]);
        stack.pop_back();
    }
    return answer;
}

/*
for i 로 초마다 체크?하면 너무 느린가
*/