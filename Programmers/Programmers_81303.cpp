// https://school.programmers.co.kr/learn/courses/30/lessons/81303

#include <string>
#include <cstring>
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

void Command(string s)
{
    vector<string> cmd;
    Split(s, cmd);
    if(cmd.size() > 1)
    {
        int move = stoi(cmd[1]);
        if(cmd[0] == "U")
        {   
            while(currentPos > 0 && move > 0)
            {
                currentPos--;
                if(graph[currentPos] == true) move--;
            }
        }
        else 
        {
            while(currentPos < graphSize && move > 0)
            {
                currentPos++;
                if(graph[currentPos] == true) move--;
            }
        }
    }
    else
    {
        if(cmd[0] == "C")
        {
            graph[currentPos] = false;
            buffer.push_back(currentPos);

            bool rear = false;
            for(int temp = currentPos+1; temp <=graphSize; temp++)
            {
                if(graph[temp] == true)
                {
                    currentPos = temp;
                    break;
                }
                if(temp == graphSize) rear = true;
            }
            if(rear)
            {
                Command("D 1");
            }
        }
        else //Z
        {
            auto pos = buffer.back();
            buffer.pop_back();
            graph[pos] = true;
        }
    }
    cout << currentPos <<'\n';
}

string solution(int n, int k, vector<string> cmd) {
    graphSize = n-1;
    currentPos = k;

    for(auto c : cmd)
    {
        Command(c);
    }

    for(int i = 0; i < n; i++)
    {
        if(graph[i] == true) answer += "O";
        else answer +="X";
    }
    return answer;
}

/*

미완*/