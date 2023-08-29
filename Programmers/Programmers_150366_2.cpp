// https://school.programmers.co.kr/learn/courses/30/lessons/150366

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<string>> excel (51, vector<string>(51, ""));
vector<string> answer;
vector<vector<pair<int, int>>> merge(51, vector<pair<int, int>>(51));

void InitMerge()
{
    for(int i = 1; i < 51; i++)
    {
        for(int j = 1; j < 51; j++)
        {
            merge[i][j] = {i, j};
        }
    }
}

pair<int, int> Find(pair<int, int> path)
{
    pair<int, int> var = merge[path.first][path.second];
    if(var.first == path.first && var.second == path.second) return path;
    merge[path.first][path.second] = Find(merge[path.first][path.second]);
    return merge[path.first][path.second];
}

void Merge(pair<int, int> p1, pair<int, int> p2)
{
    pair<int, int> _p1 = Find(p1);
    pair<int, int> _p2 = Find(p2);
    if(_p1 == _p2) return;
    for(int i = 1; i < 51; i++)
        for(int j = 1; j < 51; j++)
        {
            if(merge[i][j] == _p2) merge[i][j] = _p1;
        }
    merge[_p2.first][_p2.second] = _p1;
}

void SplitString(string str, vector<string> &v)
{
    int prev = 0;
    int cur = str.find(" ");
    while(cur != string::npos)
    {
        v.push_back(str.substr(prev, cur - prev));
        prev = cur + 1;
        cur = str.find(" ", prev);
    }
    v.push_back(str.substr(prev, cur - prev));
}

void RunCmd(vector<string> cmd)
{
    if(cmd[0] == "UPDATE")
    {
        if(cmd.size() > 3)
        {
            int r = stoi(cmd[1]), c = stoi(cmd[2]);
            excel[r][c] = cmd[3];

            for(int i = 1; i < 51; i++)
            {
                for(int j = 1; j < 51; j++)
                {
                    if(merge[i][j] == merge[r][c])
                    {
                        excel[i][j] = cmd[3];
                    }
                }
            }
        }
        else
        {
            for(int i = 1; i < 51; i++)
                for(int j = 1; j < 51; j++)
                    if(excel[i][j] == cmd[1]) excel[i][j] = cmd[2];
        }
    }

    if(cmd[0] == "MERGE")
    {
        int r1 = stoi(cmd[1]), c1 = stoi(cmd[2]), r2= stoi(cmd[3]), c2 = stoi(cmd[4]);
        if(r1 == r2 && c1 == c2) return;
        Merge({r1, c1}, {r2, c2});
        string tempS = "UPDATE";
        vector<string> tempV;
        if(excel[r1][c1] == "")
        {
            tempS += " " + to_string(r1) + " " + to_string(c1) + " " + excel[r2][c2];
            SplitString(tempS, tempV);
            RunCmd(tempV);
        }
        else
        {
            tempS += " " + to_string(r2) + " " + to_string(c2) + " " + excel[r1][c1];
            SplitString(tempS, tempV);
            RunCmd(tempV);
        }
    }

    if(cmd[0] == "UNMERGE")
    {
        int r = stoi(cmd[1]), c = stoi(cmd[2]);
        for(int i = 1; i < 51; i++)
        {
            for(int j = 1; j < 51; j++)
            {
                if(i == r &&  j == c) continue;
                if(merge[i][j] == merge[r][c])
                {
                    excel[i][j] = "";
                    merge[i][j] = {i, j};
                }
            }
        }
        merge[r][c] = {r, c};
    }

    if(cmd[0] == "PRINT")
    {
        int r = stoi(cmd[1]), c = stoi(cmd[2]);
        auto temp = excel[r][c];
        if(temp == "") answer.push_back("EMPTY");
        else answer.push_back(temp);
    }
}

void PrintTable(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(excel[i][j] == "") cout << ". ";
            else cout << excel[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "==========\n";
}

void PrintMerge(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << merge[i][j].first << ' ' << merge[i][j].second << " | ";
        }
        cout << '\n';
    }
    cout << "==========\n";
}

vector<string> solution(vector<string> commands) {
    InitMerge();
    for(auto cmdLine : commands)
    {
        vector<string> cmd;
        SplitString(cmdLine, cmd);
        RunCmd(cmd);
    }
    return answer;
}


/*
예외케이스
merge와 unmerge에 문제가 있어 아래 반례를 추가하여 해결하였습니다.

["UPDATE 1 1 A", "UPDATE 2 2 B", "UPDATE 3 3 C", UPDATE 4 4 D", "MERGE 1 1 2 2", MERGE 3 3 4 4", "MERGE 1 1 3 3", "UNMERGE 1 1", "PRINT 1 1", "PRINT 2 2", PRINT 3 3", "PRINT 4 4"]

출력은
["A","EMPTY","EMPTY","EMPTY"]가 나와야합니다.

여기서 뜻은, 두 그룹(union)을 머지했을 때 그룹 내 모든 인원이 같아야해서 for을 리며 확인하는
원래 유니온 파인드에서는 1, 1, 1, 4, 4, 4 (1~6)이면 4가 1이랑 머지하면
1, 1, 1, 1 4, 4되서 5, 6번 골라도 1이니까 자기도 1로 바꾸고 하면되는데
뭐가 좀 허술하네 Find 잘 작성하면 될거 같기도. 일단 반례덕분에 품
*/