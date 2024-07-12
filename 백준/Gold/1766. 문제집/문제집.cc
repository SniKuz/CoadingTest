#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<priority_queue<int, vector<int>, greater<int>>> graph(32001);
vector<int> input(32001);
vector<bool> visited(32001);

int main()
{
    cin >> n >> m;
    
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push(b);
        input[b] += 1;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 1; i <= n; i++)
    {
        if(input[i] == 0)
        {
            pq.push(i);
        }
    }

    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        visited[cur] = true;
        cout << cur << ' ';

        while(!graph[cur].empty())
        {
            auto next = graph[cur].top(); graph[cur].pop();
            input[next] -= 1;
            if(visited[next])
                continue;
            if(input[next] != 0)
                continue;
            pq.push(next);
        }
    }
}