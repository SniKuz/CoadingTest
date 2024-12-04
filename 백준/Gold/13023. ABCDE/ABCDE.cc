#include <bits/stdc++.h>
#define MAX 2001

using namespace std;

int n, m;

vector<vector<int>> board(MAX);
vector<bool> visited(MAX);
bool clear = false;

void solution(int a, int cnt)
{
    if(clear) return;;
    if(cnt == 5)
    {
        cout << 1;
        clear = true;
        return;
    }
    for(const auto& next : board[a])
    {
        if(visited[next] == false)
        {
            visited[next] = true;
            solution(next, cnt+1);
            visited[next] = false;
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        board[a].push_back(b);
        board[b].push_back(a);
    }
    
    for(int i = 0; i < n; i++)
    {
        visited[i] = true;
        solution(i, 1);
        visited[i] = false;
    }
    if(clear == false)
        cout << 0;
    return 0;
}
