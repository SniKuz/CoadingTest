#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
int ans = 0;

int solution(vector<int> scoville, int K) {
    priority_queue<int> pq;
    for(auto i : scoville)
    {
        pq.push(-i);
    }

    while(pq.top() > -K && pq.size() > 1)
    {
        int tmp1, tmp2;
        tmp1 = -pq.top();
        pq.pop();
        tmp2 = -pq.top();
        pq.pop();
        pq.push(-(tmp1 + (tmp2*2)));
        ans++;
    }

    return pq.top() > -K ? -1 : ans;
}

/*
C++ stl 우선순위큐가 내림차순이라 음수로 넣어서 변경. 파이썬도 오름차순
근데 파이썬에서 음수로 바꿔서 했어서 이렇게 했는데
priority_queue<int, vector<int>, greater<int>> 이렇게 한 사람도 있네
*/