#include <bits/stdc++.h>

using namespace std;

int n, m, s;
vector<vector<int>> board(100001);
set<int> fanclub;

void DFS()
{
    if(fanclub.find(1) != fanclub.end())
    {
        cout << "Yes";
        return;
    }
    vector<int> v;
    vector<bool> visited(n+1);
    v.push_back(1);
    visited[1] = true;
    
    while(v.empty() == false)
    {
        auto cur = v.back(); v.pop_back();
        if(board[cur].size() == 0) // leaf
        {
            cout << "yes";
            return;
        }
        
        for(const auto& next : board[cur])
        {
            if(fanclub.find(next) != fanclub.end())
                continue;
            if(visited[next])
                continue;
            visited[next] = true;
            v.push_back(next);
        }
    }
    cout << "Yes";
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        board[u].push_back(v);
    }
    cin >> s;
    for(int i = 0; i < s; i++)
    {
        int fan;
        cin >> fan;
        fanclub.insert(fan);
    }
    DFS();
    return 0;
}