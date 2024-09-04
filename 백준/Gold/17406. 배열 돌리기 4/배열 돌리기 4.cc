#include <bits/stdc++.h>

using namespace std;

struct rotateCmd{
    int r, c, s;
};

int n, m, k;
int res = 2e8;

void Rotate(int r, int c, int s, vector<vector<int>> &board)
{

    for(int i = 1; i <= s; i++)
    {
        int sx = r-i, sy = c-i;
        int ex = r+i, ey = c+i;
        int temp = board[sx][sy];

        for(int j = sx; j < ex; j++)
        {
            board[j][sy] = board[j+1][sy];
        }
        for(int j = sy; j < ey; j++)
        {
            board[ex][j] = board[ex][j+1];
        }
        for(int j = ex; j > sx; j--)
        {
            board[j][ey] = board[j-1][ey];
        }
        for(int j = ey; j > sy; j--)
        {
            board[sx][j] = board[sx][j-1];
        }
        board[sx][sy+1] = temp;
    }
}

void solve(vector<vector<int>> &board)
{
    for(int i = 0; i < n; i++)
    {
        int cnt = 0;
        for(int j = 0; j < m; j++)
        {
            cnt += board[i][j];
        }
        if(res > cnt)
            res = cnt;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m >> k;
    vector<vector<int>> board(50, vector<int>(50));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    vector<int> idx(k);
    vector<rotateCmd> cmds;
    for(int i = 0; i < k; i++)
    {
        rotateCmd rc;
        cin >> rc.r >> rc.c >> rc.s;
        rc.r -= 1; rc.c -= 1;
        cmds.push_back(rc);
        idx[i] = i;
    }

    do
    {
        auto copyBoard = board;
        for(const auto& i : idx)
        {
            Rotate(cmds[i].r, cmds[i].c, cmds[i].s, copyBoard);
        }
        solve(copyBoard);
    } while (next_permutation(idx.begin(), idx.end()));
    cout << res;
}