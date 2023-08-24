// BFS that work in 0, 1 edge shortest route
// O(v+e)
//1. 덱의 front에서 pop
//2. 인접 노드 확인
//3. 현재 노드까지 소비 비용 + 인접 노드 가중치 < 인접 노드까지 가는데 소비된 비용이면 갱신
//4. 노드가 갱신된 상태에서 만약 인접한 그 노드를 향하는 가중치가 0이면 front, 1이면 rear push
//5. 반복

#include <iostream>
#include <algorithm>
#include <cstring>
#include <deque>
using namespace std;

int n, k;
int dist[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> k;
    memset(dist, -1, sizeof(dist));
    // -1 = edge가 0

    deque<int> dq;
    dq.push_back(n);
    dist[n] = 0;

    while(!dq.empty())
    {
        int v = dq.front(); dq.pop_front();
        
        if(v*2 <= 100000 && dist[v*2] == -1)
        {
            dq.push_front(v*2);
            dist[v*2] = dist[v];
        }

        if(v-1>=0 && dist[v-1] == -1)
        {
            dq.push_back(v-1);
            dist[v-1] = dist[v]+1;
        }

        if(v+1 <= 100000 && dist[v+1] == -1)
        {
            dq.push_back(v+1);
            dist[v+1] = dist[v] + 1;
        }
    }
    cout << dist[k];
}