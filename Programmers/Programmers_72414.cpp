// https://school.programmers.co.kr/learn/courses/30/lessons/72414

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> timeLine(360000,0);
string answer = "";
void SplitStringTime(string s, vector<string> &splitStringContainer)
{
    int prev = 0, current = s.find(":");
    while(current != string::npos)
    {
        splitStringContainer.push_back(s.substr(prev, current-prev));
        prev = current + 1;
        current = s.find(":", prev);
    }
    splitStringContainer.push_back(s.substr(prev, current));
}

int ChangeTimetoSecond(vector<string> time)
{
    int ret = 0;
    ret += stoi(time[0]) * 60 * 60;
    ret += stoi(time[1]) * 60;
    ret += stoi(time[2]);
    return ret;
}

void InitTime(string log)
{
    int temp = log.find("-");
    string start = log.substr(0, temp);
    string end = log.substr(temp+1);
    vector<string> startTime;
    vector<string> endTime;
    SplitStringTime(start, startTime);
    SplitStringTime(end, endTime);
    for(int i = ChangeTimetoSecond(startTime); i < ChangeTimetoSecond(endTime); i++)
    {
        timeLine[i]++;
        cout << i << ' ';
    }
}

string solution(string play_time, string adv_time, vector<string> logs) {
    
    for(auto log : logs)
    {
        InitTime(log);
    }
    return answer;
}
/*
이렇게 풀면 터짐
*/