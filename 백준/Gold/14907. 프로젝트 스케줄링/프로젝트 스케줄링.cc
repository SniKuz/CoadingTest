#include <bits/stdc++.h>

using namespace std;
vector<int> works(27);
vector<int> inputs(27);
vector<vector<char>> board(27);
set<char> start;
int totalWorks = 0;
int finishWorks = 0;
int tick = 0;

vector<string> split(string str)
{
    istringstream iss(str);
    string buf;
    vector<string> ret;
    
    while(getline(iss, buf, ' '))
    {
        ret.push_back(buf);
    }
    return ret;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    while(getline(cin, str, '\n'))
    {
        totalWorks++;
        vector<string> splitStr = split(str);
        works[splitStr[0][0] - 'A'] = stoi(splitStr[1]);
        if(splitStr.size() > 2)
        {
            inputs[splitStr[0][0] - 'A'] = splitStr[2].size();
            for(const char& e : splitStr[2])
            {
                board[e - 'A'].push_back(splitStr[0][0]);
            }
        }
        else
        {
            start.insert(splitStr[0][0]);
        }
    }
    
    while(finishWorks < totalWorks)
    {
        tick++;
        vector<char> endWork, newWork;
        for(const auto& w : start)
        {
            if(--works[w - 'A'] == 0)
            {
                finishWorks++;
                endWork.push_back(w);
                for(const auto& e : board[w - 'A'])
                {
                    if(--inputs[e - 'A'] == 0)
                    {
                        newWork.push_back(e);
                    }
                }
            }
        }
        for(const auto& e : endWork)
        {
            start.erase(e);
        }
        for(const auto& e : newWork)
        {
            start.insert(e);
        }
    }
    cout << tick;
    return 0;
}
