#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> board(32001);
vector<int> inputs(32001);

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
        board[s].push_back(e);
        inputs[e] += 1;
    }
    queue<int> q;
    for(int i = 1; i <= n; i++)
    {
        if(inputs[i] == 0)
            q.push(i);
    }
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        cout << cur << ' ';
        for(const auto& e : board[cur])
        {
            inputs[e] -= 1;
            if(inputs[e] == 0)
                q.push(e);
        }
    }
}