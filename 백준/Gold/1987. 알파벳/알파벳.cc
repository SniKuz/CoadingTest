#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int r, c;
vector<string> board(20);
int res = 0;
map<char, int> m;

void solution(int x, int y, int cnt)
{
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= r || ny >= c)
            continue;
        if(m[board[nx][ny]] != 0)
            continue;
        m[board[nx][ny]] = 1;
        solution(nx, ny, cnt+1);
        m[board[nx][ny]] = 0;
    }
    if(res < cnt)
        res = cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c;
    for(int i = 0; i < r; i++)
    {
        cin >> board[i];
        for(const auto& e : board[i])
            m[e] = 0;
    }
    m[board[0][0]] = 1;
    solution(0, 0, 1);
    cout << res;
}