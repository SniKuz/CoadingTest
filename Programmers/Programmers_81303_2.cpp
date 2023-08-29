// https://school.programmers.co.kr/learn/courses/30/lessons/81303

#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<bool> graph(1000001, true);
vector<int> buffer;
int graphSize;
int currentPos;
string answer = "";

void Split(string s, vector<string> &cmd)
{
    int prev = 0;
    int current = s.find(" ");
    while(current!= string::npos)
    {
        cmd.push_back(s.substr(prev, current - prev));
        prev = current + 1;
        current = s.find(" " , prev);
    }
    cmd.push_back(s.substr(prev, current));
}

// dir = -1 : up, 1 : down
void Move(int dir, int moveGauge)
{
    int temp = currentPos;
    int lastExistRow = currentPos;
    if(dir < 1)
    {
        while(temp >= 0 && moveGauge > 0)
        {
            if(graph[temp] == true)
            {
                moveGauge--;
                lastExistRow = temp;
            }
            temp--;
        }
        if(temp < 0 && moveGauge > 0) 
            if(lastExistRow == currentPos) Move(1, 1);
            else currentPos = lastExistRow;
        else currentPos = lastExistRow;
    }
    else
    {
        while(temp < graphSize && moveGauge > 0)
        {
            if(graph[temp] == true)
            {
                moveGauge--;
                lastExistRow = temp;
            }
            temp++;
        }
        if(temp == graphSize && moveGauge > 0) 
            if(lastExistRow == currentPos) Move(-1, 1);
            else currentPos = lastExistRow;
        else currentPos = lastExistRow;
    }
}

void RunCmd(string cmd)
{
    vector<string> sCmd;
    Split(cmd, sCmd);

    if(sCmd.size() > 1)
    {
        int move = stoi(sCmd[1]);
        if(sCmd[0] == "U")
            Move(-1,move+1);
        else
            Move(1, move+1);
    }
    else
    {
        if(sCmd[0] == "C")
        {
            graph[currentPos] = false;
            buffer.push_back(currentPos);
            Move(1, 1);
        }
        else // Z
        {
            auto pos = buffer.back();
            buffer.pop_back();
            graph[pos] = true;
        }
    }
}

string solution(int n, int k, vector<string> cmd) {
    graphSize = n;
    currentPos = k;

    for(auto c : cmd)
    {
        RunCmd(c);
    }

    for(int i = 0; i < n; i++)
    {
        if(graph[i] == true) answer += "O";
        else answer +="X";
    }
    return answer;
}

/*
효율성 5개 시간초과 나머지는 ㄱㅊ. 요구사항은 위에 해놓은게 다이긴 한듯?
*/