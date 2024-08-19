#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> check = {
    {{-1, -1}, {0, -1}, {-1, 0}, {0, 0}},
    {{-1, 0}, {0, 0}, {-1, 1}, {0, 1}},
    {{0, -1}, {0, 0}, {1, -1}, {1, 0}},
    {{0, 0}, {0, 1}, {1, 0}, {1, 1}}
};

int answer = 0;


bool Delete4(int r, int c, vector<string>& board)
{
    bool delSomething = false;
    set<pair<int, int>> target;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            for(const auto& e : check)
            {
                bool block = true;
                char cur = board[i][j];
                for(int k = 0; k < 4; k++)
                {
                    int nx = i + e[k].first;
                    int ny = j + e[k].second;
                    if(nx < 0 || ny < 0 || nx >= r || ny >= c)
                    {
                        block = false;
                        break;
                    }
                    else if(board[nx][ny] == '.')
                    {
                        block = false;
                        break;
                    }
                    else if(board[nx][ny] != cur)
                    {
                        block = false;
                        break;
                    }
                }
                if(block)
                {
                    for(int k = 0; k < 4; k++)
                    {
                        int nx = i + e[k].first;
                        int ny = j + e[k].second;
                        target.insert({nx, ny});
                    }
                }
            }
        }
    }
    
    for(const auto& t : target)
    {
        board[t.first][t.second] = '.';
        answer++;
        delSomething = true;
    }
    return delSomething;
}

void Fall(int r, int c, vector<string>& board)
{
    for(int j = 0; j < c; j++)
    {
        queue<char> q;
        for(int i = r-1; i >= 0; i--)
        {
            if(board[i][j] != '.')
            {
                q.push(board[i][j]);
            }
        }
        int i = r-1;
        while(!q.empty())
        {
            auto cur = q.front(); q.pop();
            board[i--][j] = cur;
        }
        for(; i >= 0; i--)
        {
            board[i][j] = '.';
        }
    }
}

int solution(int m, int n, vector<string> board) {
    
    while(Delete4(m, n, board))
    {
        Fall(m, n, board);
    }
    
    return answer;
}

