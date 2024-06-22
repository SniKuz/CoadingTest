#include <bits/stdc++.h>

using namespace std;

int dl[] = {1, -1};
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int L, R, C; // level row col

vector<vector<vector<char>>> board(30, vector<vector<char>>(30, vector<char>(30))); // [l][x][y]

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    char tmp;
    cin >> L >> R >> C;
    while(L != 0 && R != 0 && C != 0)
    {
        int startL, startR, startC;
        for(int l = 0; l < L; ++l)
        {
            for(int r = 0; r < R; ++r)
            {
                for(int c = 0; c < C; ++c)
                {
                    cin >> board[l][r][c];
                    if(board[l][r][c] == 'S')
                    {
                        startL = l; startR = r; startC = c;
                    }
                }
            }
        }

        vector< vector<vector<bool>> > visited(L, vector<vector<bool>>(R, vector<bool>(C, false)));
        queue< pair<pair<int, int>, pair<int, int>> > q;
        q.push({{0, startL}, {startR, startC}}); // min, level, x, y
        visited[startL][startR][startC] = true;
        bool found = false;
        while(!q.empty())
        {
            auto cur = q.front(); q.pop();

            for(int i = 0; i < 4; ++i)
            {
                int nx = cur.second.first + dx[i];
                int ny = cur.second.second + dy[i];

                if(nx < 0 || ny < 0 || nx >= R || ny >= C)
                    continue;
                if(visited[cur.first.second][nx][ny])
                    continue;
                if(board[cur.first.second][nx][ny] == '#')
                    continue;
                if(board[cur.first.second][nx][ny] == 'E')
                {
                    cout << "Escaped in " << cur.first.first+1 << " minute(s).\n";
                    found = true;
                    break;
                }
                visited[cur.first.second][nx][ny] = true;
                q.push({{cur.first.first + 1, cur.first.second}, {nx, ny}});
            }
            if(found) break;

            for(int i = 0; i < 2; ++i)
            {
                int nl = cur.first.second + dl[i];
                if(nl < 0 || nl >= L)
                    continue;
                if(visited[nl][cur.second.first][cur.second.second])
                    continue;
                if(board[nl][cur.second.first][cur.second.second] == '#')
                    continue;
                if(board[nl][cur.second.first][cur.second.second] == 'E')
                {
                    cout << "Escaped in " << cur.first.first+1 << " minute(s).\n";
                    found = true;
                    break;
                }
                visited[nl][cur.second.first][cur.second.second] = true;
                q.push({{cur.first.first + 1, nl}, {cur.second.first, cur.second.second}});
            }
            if(found) break;
        }
        if(!found) cout << "Trapped!\n";

        cin >> L >> R >> C;
    }

    return 0;
}