#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

vector<vector<char>> board(12, vector<char>(6));
vector<vector<bool>> visited(12, vector<bool>(6, false));
bool isPuyo = false;

void BFS(int r, int c, set<pair<int, int>>& puyo)
{
    vector<pair<int, int>> ret;
    int cnt = 0;
    char target = board[r][c];
    vector<pair<int, int>> v;
    v.push_back({r, c});
    visited[r][c] = true;

    while(!v.empty())
    {
        auto cur = v.back(); v.pop_back();
        cnt += 1;
        ret.push_back({cur.X, cur.Y});

        for(int i = 0; i < 4; i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if(nx < 0 || ny < 0 || nx >= 12 || ny >= 6)
                continue;
            if(visited[nx][ny])
                continue;
            if(board[nx][ny] != target)
                continue;
            visited[nx][ny] = true;
            v.push_back({nx, ny});
        }
    }
    if(cnt >= 4)
    {
        isPuyo = true;
        for(const auto& pos : ret)
        {
            puyo.insert(pos);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            cin >> board[i][j];
        }
    }

    int turn = 0;
    do
    {
        // for(int i = 0; i < 12; i++)
        // {
        //     for(int j = 0; j <6; j++)
        //     {
        //         cout << board[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << "=======\n";

        isPuyo = false;
        set<pair<int, int>> puyo;
        for(int i = 11; i >= 0; i--)
        {
            for(int j = 5; j >= 0; j--)
            {
                if(!visited[i][j] && board[i][j] != '.')
                {
                    BFS(i, j, puyo);
                }
            }
        }

        if(isPuyo)
        {
            turn += 1;
            for(const auto& pos : puyo)
            {
                board[pos.X][pos.Y] = '.';
            }

            queue<char> q;
            for(int j = 0; j < 6; j++)
            {
                for(int i = 11; i >= 0; i--)
                {
                    if(board[i][j] != '.')
                    {
                        q.push(board[i][j]);
                    }
                }

                for(int i = 11; i >= 0; i--) 
                    board[i][j] = '.';
                int point = 11;
                while(!q.empty())
                {
                    auto cur = q.front(); q.pop();
                    board[point--][j] = cur;
                }
            }

            for(int i = 0; i < 12; i++)
            {
                for(int j = 0; j < 6; j++)
                {
                    visited[i][j] = false;
                }
            }
        }
    } while (isPuyo);

    cout << turn;

    return 0;
}