//https://school.programmers.co.kr/learn/courses/30/lessons/43163

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<char>> spellings(50);
vector<bool> visited(50, false);
string _target;
int answer = 987654321;
int cnt = -1;

vector<string> test;

bool CheckWord(string a, string b)
{
    int check = 0;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] != b[i]) check++;
        if(check > 1) return false;
    }
    return true;
}

void DFS(string curName, vector<string> words)
{
    cnt++;
    test.push_back(curName);
    
    if(curName == _target)
    {
        answer = min(answer, cnt);
        
    }
    for(int i = 0; i < words.size(); i++)
    {
        if(!visited[i] && CheckWord(curName, words[i]))
        {
            visited[i] = true;
            DFS(words[i], words);
            visited[i] = false;
        }
    }
    
    test.pop_back();
    cnt--;
}

int solution(string begin, string target, vector<string> words) {
    
    _target = target;
    for(int i = 0; i < words.size(); i++)
    {
        for(auto c : words[i])
            spellings[i].push_back(c);
    }
    DFS(begin, words);
    return answer == 987654321 ? 0 : answer;
}