#include <bits/stdc++.h>
#define turn first
#define pos second
#define INF 200001

using namespace std;

int n, k;
vector<int> board(INF, -1);

int main()
{
    cin >> n >> k;
    queue<pair<int, int>> q; // turn, pos
    q.push({0, n});
    board[n] = 0;
    while(!q.empty() && board[k] == -1)
    {
        auto cur = q.front(); q.pop();

        if(cur.pos+1 < INF && board[cur.pos+1] == -1)
        {
            board[cur.pos+1] = cur.turn + 1;
            q.push({cur.turn+1, cur.pos+1});
        }
        if(cur.pos - 1 >= 0 && board[cur.pos-1] == -1)
        {
            board[cur.pos-1] = cur.turn + 1;
            q.push({cur.turn+1, cur.pos-1});
        }
        if(cur.pos*2 < INF && board[cur.pos*2] == -1)
        {
            board[cur.pos*2] = cur.turn + 1;
            q.push({cur.turn + 1, cur.pos*2});
        }
    }
    cout << board[k];
}