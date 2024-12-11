#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

vector<string> board(9);
vector<pii> emptyPlace;
bool finish = false;
int decimal[10];

void Print()
{
    for(const auto& line : board)
        cout << line << '\n';
}

void Init()
{
    memset(decimal, 0, sizeof(decimal));
}

bool CheckRow(int r)
{
    Init();
    for(int j = 0; j < 9; j++)
    {
        auto num = board[r][j];
        if(num == '0')
            continue;
        else if(++decimal[num - '0'] > 1)
            return false;
    }
    return true;
}
bool CheckCol(int c)
{
    Init();
    for(int j = 0; j < 9; j++)
    {
        auto num = board[j][c];
        if(num == '0')
            continue;
        if(++decimal[num - '0'] > 1)
            return false;
    }
    return true;
}
bool CheckBox(int r, int c)
{
    Init();
    int lr = r/3 * 3;
    int lc = c/3 * 3;
    int rr = lr + 3;
    int rc = lc + 3;
    
    for(int i = lr; i < rr; i++)
    {
        for(int j = lc; j < rc; j++)
        {
            auto num = board[i][j];
            if(num == '0')
                continue;
            if(++decimal[num - '0'] > 1)
            {
                return false;
            }
        }
    }
    return true;
}

void Sudoku(int cur, int emptySize)
{
    if(finish) return;
    int r = emptyPlace[cur].first, c = emptyPlace[cur].second;
    // cout << cur << " : " << r << ' ' << c << '\n';
    for(int i = 1; i <= 9; i++)
    {
        board[r][c] = '0' + i;
        // Print();
        if(CheckRow(r) && CheckCol(c) && CheckBox(r, c))
        {
            if(cur == emptySize-1)
            {
                Print();
                finish = true;
                return;
            }

            Sudoku(cur+1, emptySize);
        }
    }
    board[r][c] = '0';
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for(int i = 0; i < 9; i++)
    {
        cin >> board[i];
        for(int j = 0; j < 9; j++)
        {
            if(board[i][j] == '0')
                emptyPlace.push_back({i, j});
        }
    }
    Sudoku(0, emptyPlace.size());
    return 0;
}