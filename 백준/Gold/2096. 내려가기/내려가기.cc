#include <bits/stdc++.h>

using namespace std;

int n;
int board[3];
int maxDP[2][3], minDP[2][3];
short turn = 0;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i = 0; i < 3; i++)
    {
        cin >> board[i];
    }
    for(int i = 0; i < 3; i++)
    {
        maxDP[0][i] = board[i];
        minDP[0][i] = board[i];
    }
    
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> board[j];
        }
        
        short prevTurn = turn;
        turn = (turn + 1) % 2;
        for(int j = 0; j < 3; j++)
        {
            if(j == 0)
            {
                maxDP[turn][j] = board[j] + max(maxDP[prevTurn][j+1], maxDP[prevTurn][j]);
                minDP[turn][j] = board[j] + min(minDP[prevTurn][j+1], minDP[prevTurn][j]);
            }
            else if(j == 2)
            {
                maxDP[turn][j] = board[j] + max(maxDP[prevTurn][j-1], maxDP[prevTurn][j]);
                minDP[turn][j] = board[j] + min(minDP[prevTurn][j-1], minDP[prevTurn][j]);
            }
            else
            {
                maxDP[turn][j] = board[j] + max(maxDP[prevTurn][j-1], maxDP[prevTurn][j+1]);
                maxDP[turn][j] = max(maxDP[turn][j], board[j] + maxDP[prevTurn][j]);
                minDP[turn][j] = board[j] + min(minDP[prevTurn][j-1], minDP[prevTurn][j+1]);
                minDP[turn][j] = min(minDP[turn][j], board[j] + minDP[prevTurn][j]);
            }
        }
    }
    
    int maxRes = 0, minRes = 2e8;
    for(int j = 0; j < 3; j++)
    {
        if(maxRes < maxDP[turn][j])
            maxRes = maxDP[turn][j];
    }
    for(int j = 0; j < 3; j++)
    {
        if(minRes > minDP[turn][j])
            minRes = minDP[turn][j];
    }
    cout << maxRes << ' ' << minRes;
    return 0;
}