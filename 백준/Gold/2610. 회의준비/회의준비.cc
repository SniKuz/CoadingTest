#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> board(101, vector<int>(101, 2e8));
int groupCnt = 0;
set<int> targets;
vector<int> parents(101, -1);
map<int, vector<int>> groups;

int Find(int x)
{
    if(parents[x] < 0) return x;
    return parents[x] = Find(parents[x]);
}

void MakeUnion(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if(x == y) return;
    parents[x] += parents[y];
    parents[y] = x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;
        board[s][e] = 1;
        board[e][s] = 1;
        MakeUnion(s, e);
    }
    for(int i = 1; i <= n; i++)
    {
        board[i][i] = 0;
        if(parents[i] < 0)
            groupCnt++;
        groups[Find(i)].push_back(i);
    }

    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(board[i][j] > board[i][k] + board[k][j])
                    board[i][j] = board[i][k] + board[k][j];
            }
        }
    }

    for(const auto& kv : groups)
    {
        int targetNode = 0;
        int cnt = 2e8;
        for(const auto& val : kv.second)
        {
            int minCnt = 0;
            for(const auto& node : kv.second)
            {
                if(minCnt < board[val][node])
                    minCnt = board[val][node];
            }
            if(cnt > minCnt)
            {
                cnt = minCnt;
                targetNode = val;
            }
        }
        targets.insert(targetNode);
    }

    cout << groupCnt << '\n';
    for(const auto& e : targets)
    {
        cout << e << '\n';
    }
}