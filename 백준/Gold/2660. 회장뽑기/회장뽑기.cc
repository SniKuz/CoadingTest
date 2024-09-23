#include <bits/stdc++.h>
#define node first
#define depth second

using namespace std;

int n;
vector<vector<int>> board(51);
map<int, vector<int>> friendDepth;
int minDepth = 2e8;

void BFSFriend(int x)
{
    int xDepth = 0;
    vector<bool> visited(51);
    visited[x] = true;
    queue<pair<int, int>> q;
    q.push({x, 0});

    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        xDepth = cur.depth;
        for(const auto &next : board[cur.node])
        {
            if(!visited[next])
            {
                visited[next] = true;
                q.push({next, cur.depth+1});
            }
        }
    }
    friendDepth[xDepth].push_back(x);
    if(minDepth > xDepth) minDepth = xDepth;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    int a, b;
    cin >> a >> b;
    while(a != -1 && b != -1)
    {
        board[a].push_back(b);
        board[b].push_back(a);
        cin >> a >> b;
    }
    for(int i = 1; i <= n; i++)
    {
        BFSFriend(i);
    }

    cout << minDepth << ' ' << friendDepth[minDepth].size() << '\n';
    for(const auto &e : friendDepth[minDepth])
    {
        cout << e << ' ' ;
    }
}