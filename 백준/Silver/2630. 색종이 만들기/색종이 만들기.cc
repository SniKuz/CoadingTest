#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<char>> board(128, vector<char>(128));
int blue = 0, white = 0;

bool CheckColor(int sr, int sc, int er, int ec)
{
    int color = board[sr][sc];
    for(int i = sr; i <= er; i++)
    {
        for(int j = sc; j <= ec; j++)
        {
            if(board[i][j] != color)
                return false;
        }
    }
    if(color == '1') blue++;
    else white++;
    return true;
}

void solution(int sr, int sc, int er, int ec)
{
    if(CheckColor(sr, sc, er, ec))
    {
        return;
    }
    int mr = (sr + er) / 2;
    int mc = (sc + ec) / 2;
    solution(sr, sc, mr, mc);
    solution(sr, mc+1, mr, ec);
    solution(mr+1, sc, er, mc);
    solution(mr+1, mc+1, er, ec);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    // Input
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    solution(0, 0, n-1, n-1);
    cout << white << '\n' << blue;
}