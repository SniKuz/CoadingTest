#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    int answer = 0;
    int s = 0, e = 0;
    int sum = 0;
    while(e <= n)
    {
        if(sum == n)
        {
            answer++;
        }
        if(sum < n)
        {
            sum += ++e;
        }
        else if(sum >= n)
        {
            sum -= ++s;
        }
    }
    return answer;
}

