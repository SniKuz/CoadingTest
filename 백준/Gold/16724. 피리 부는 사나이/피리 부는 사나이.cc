#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

int n, m;
vector<string> board(1000);
bool visited[1000][1000];
bool prevs[1000][1000];
map<char, pii> dir = {
    {'D', {1, 0}}, {'U', {-1, 0}}, {'L', {0, -1}}, {'R', {0, 1}}
};

void solution(int& res, pii cur)
{
    prevs[cur.X][cur.Y] = true;
    pii next = {cur.X + dir[board[cur.X][cur.Y]].X, cur.Y + dir[board[cur.X][cur.Y]].Y};
    if(visited[next.X][next.Y] && prevs[next.X][next.Y] == false)
    {
        
    }
    else if(visited[next.X][next.Y] == false && prevs[next.X][next.Y])
    {
        res++;
    }
    else
    {
        solution(res, next);
    }
    prevs[cur.X][cur.Y] = false;
    visited[cur.X][cur.Y] = true;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> board[i];
    }
    
    int res = 0;
    for(int i = 0; i < n ; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(visited[i][j] == false)
            {
                solution(res, {i, j});
            }
        }
    }
    cout << res;
    return 0;
}

/*
    1차시도 : 바로 실패. -> 이번 루트(prevs)에서 이전에 방문한 곳이 아닌데 visited에서 방문했어야 다른 루트임을 알 수 있음?
    2차시도 : 1% 시간초과 -> 9466번 텀 프로젝트 처럼 visited(전체 루트 체크), prevs(이번 루트 체크)로 나눠서 방문 여부 체크 변경
*/