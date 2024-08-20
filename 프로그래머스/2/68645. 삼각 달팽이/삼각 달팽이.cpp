#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n) {
    int len = ((n+1)*n) / 2;
    vector<int> answer;
    vector<vector<int>> board(n, vector<int>(n, 0));
    int cnt = 0;
    int i = -1, j = 0;
    while(cnt < len)
    {
        while(i+1 < n && board[i+1][j] == 0)
        {
            board[++i][j] = ++cnt;
        }
        while(j+1 < n && board[i][j+1] == 0)
        {
            board[i][++j] = ++cnt;
        }
        while(board[i-1][j-1] == 0)
        {
            board[--i][--j] = ++cnt;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            answer.push_back(board[i][j]);
        }
    }
    return answer;
}