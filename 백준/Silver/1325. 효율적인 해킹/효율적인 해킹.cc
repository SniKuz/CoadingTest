#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> board(10001);
set<int> ret;
int maxHack = 0;

void BFS(int s)
{
    vector<int> v;
    vector<bool> visited(n+1);
    v.push_back(s);
    visited[s] = true;
    int hack = 0;

    while(!v.empty())
    {
        auto cur = v.back(); v.pop_back();
        hack += 1;

        for(const auto& next : board[cur])
        {
            if(visited[next])
                continue;
            visited[next] = true;
            v.push_back(next);
        }
    }
    if(maxHack < hack)
    {
        ret.clear();
        ret.insert(s);
        maxHack = hack;
    }
    else if(maxHack == hack)
    {
        ret.insert(s);
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;
        board[e].push_back(s);
    }
    for(int i = 1; i <= n; i++)
    {
        BFS(i);
    }
    for(const auto& e : ret)
    {
        cout << e << ' ';
    }
}