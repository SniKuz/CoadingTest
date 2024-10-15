#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

int dxQueen[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dyQueen[] = {-1, 1, 0, 1, -1, 0, 1, -1};
int dxKnight[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dyKnight[] = {-2, 2, -1, 1, -2, 2, -1, 1};

int n, m;
int q;
vector<pii> queens;
int k;
vector<pii> knights;
int p;
vector<pii> pawns;
vector<vector<int>> board(1001, vector<int>(1001, 0)); //1 장애물. 2 불안전 위치

void Input()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        queens.push_back({x, y});
    }
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        knights.push_back({x, y});
    }
    cin >> p;
    for(int i = 0; i < p; i++)
    {
        int x, y;
        cin >> x >> y;
        pawns.push_back({x, y});
    }
}

void CheckPawn()
{
    for(const auto& pawn : pawns)
    {
        board[pawn.X][pawn.Y] = 1;
    }
}
void CheckKnight()
{
    for(const auto& knight : knights)
    {
        board[knight.X][knight.Y] = 1;
        for(int i = 0; i < 8; i++)
        {
            int nx = knight.X + dxKnight[i];
            int ny = knight.Y + dyKnight[i];
            if(nx < 1 || ny < 1 || nx > n || ny > m)
                continue;
            if(board[nx][ny] == 1)
                continue;
            board[nx][ny] = 2;
        }
    }
}
void CheckQueen()
{
    for(const auto& queen : queens)
    {
        board[queen.X][queen.Y] = 1;
        for(int i = 0; i < 8; i++)
        {
            int nx = queen.X;
            int ny = queen.Y;
            while(true)
            {
                nx += dxQueen[i];
                ny += dyQueen[i];
                if(nx < 1 || ny < 1 || nx > n || ny > m)
                    break;
                if(board[nx][ny] == 1)
                    break;
                board[nx][ny] = 2;
            }
        }
    }
}

int main() 
{
    Input();
    CheckPawn();
    CheckKnight();
    CheckQueen();
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(board[i][j] == 0)
                cnt++;
        }
    }
    cout << cnt;
    return 0;
}
