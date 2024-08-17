#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> priorities, int location) {
    int ans = 0;
    queue<int> q;
    priority_queue<int> pq;
    for(const auto& e : priorities)
    {
        q.push(e);
        pq.push(e);
    }
    
    while(true)
    {
        auto cur = q.front(); q.pop();
        if(cur == pq.top())
        {
            if(location == 0)
                return ans + 1;
            pq.pop();
            ans++;
        }
        else
        {
            q.push(cur);
        }
        location -= 1;
        if(location < 0)
            location = q.size() - 1;
    }
    
    return ans;
}