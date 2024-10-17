#include <bits/stdc++.h>

using namespace std;

int n;

vector<vector<int>> board(100001);
vector<int> parents(100001, -1);

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    parents[1] = 0;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        board[a].push_back(b);
        board[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        for(const auto& e : board[cur])
        {
            if(parents[e] > 0) continue;
            parents[e] = cur;
            q.push(e);
        }
    }
    for(int i = 2; i <= n; i++)
    {
        cout << parents[i] << '\n';
    }
    return 0;
}
