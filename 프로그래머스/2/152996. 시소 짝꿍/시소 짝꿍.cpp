#include <bits/stdc++.h>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    vector<long long> v(1001,0);
    for(const auto& w : weights)
    {
        v[w]++;
    }
    for(int i = 100; i <= 1000; i++)
    {
        answer += v[i]*(v[i]-1)/2;
        if(v[i] != 0 && i*2 <= 1000)
        {
            answer += v[i] * v[i*2];
        }
        if(v[i] != 0 && i*3/2 <= 1000)
        {
            double temp = i*3/2.0;
            long long tmp = i*3/2;
            if(temp == tmp)
                answer += v[i] * v[i*3/2];
        }
        if(v[i] != 0 && i*4/3 <= 1000)
        {
            double temp = i*4/3.0;
            long long tmp = i*4/3;
            if(temp == tmp)
                answer += v[i] * v[i*4/3];
        }
    }
    return answer;
}

/*
같은 무게는 무조건 쌍
2배, 3/2배, 4/3배 차이도 무조건 쌍
몸무게는 모두 정수
개수 싹다 저장하고 앞에서부터 체크
소수점 처리 필요
*/