#include <bits/stdc++.h>

using namespace std;

int tc;

int Find(vector<int>& parent, int a)
{
    if(parent[a] < 0) return a;
    return parent[a] = Find(parent, parent[a]);
}

void MakeUnion(vector<int>& parent, int a, int b)
{
    a = Find(parent, a);
    b = Find(parent, b);
    
    if(a == b) return;
    parent[a] += parent[b];
    parent[b] = a;
}

void solution(vector<vector<int>>& board, vector<int>& parent, int cur)
{
    for(const auto& e : board[cur])
    {
        if(Find(parent, cur) != Find(parent, e))
        {
            MakeUnion(parent, cur, e);
            solution(board, parent, e);
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> tc;
    for(int t = 1; t <= tc; t++)
    {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> board(n);
        for(int i = 0; i < k; i++)
        {
            int a, b;
            cin >> a >> b;
            board[a].push_back(b);
            board[b].push_back(a);
        }
        vector<int> parent(n, -1);
        for(int i = 0; i < n; i++)
        {
            solution(board, parent, i);
        }
        cout << "Scenario " << t << ":\n";
        int m;
        cin >> m;
        for(int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            if(Find(parent, a) == Find(parent, b))
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        cout << '\n';
    }
    return 0;
}
