// https://school.programmers.co.kr/learn/courses/30/lessons/214288

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<pair<int, int>>> waitingQues(6);
vector<int> mentos(6);
int answer = 0;

int CheckWaitingTime(int category)
{
    int totalWaitingTime = 0;
    int mentoNum = mentos[category];
    vector<pair<int, int>> consultings(mentoNum);

    for(auto counselor : waitingQues[category])
    {
        if(mentoNum > 0)
        {
            consultings[--mentoNum] = counselor;
        }
        else
        {
            int fastestMento;
            int waitingTIme = 2e9;
            for(int i = 0; i < consultings.size(); i++)
            {
                if(waitingTIme > consultings[i].first + consultings[i].second - counselor.first)
                {
                    
                    waitingTIme = consultings[i].first + consultings[i].second - counselor.first;
                    fastestMento = i;
                }
            }
            //2
            totalWaitingTime += waitingTIme > 0 ? waitingTIme : 0;
            consultings[fastestMento].first = consultings[fastestMento].first + consultings[fastestMento].second;
            consultings[fastestMento].second = counselor.second;
        }
    }
    return totalWaitingTime;
}

int solution(int k, int n, vector<vector<int>> reqs) {
    for(auto req : reqs)
    {
        waitingQues[req[2]-1].push_back({req[0], req[1]});
    }
    for(int i = 0; i < k; i++) {
        mentos[i] = 1;
        n--;
    }
    
    
    for(int i = 0; i < n; i++)
    {
        int bestImproveQue = -1;
        int bestImproveTime = -1;
        for(int j = 0; j < k; j++)
        {
            int beforeWaitingTIme = CheckWaitingTime(j);
            mentos[j] += 1;
            int afterWaitingTime = CheckWaitingTime(j);
            mentos[j] -=1;
            if(bestImproveTime > afterWaitingTime - beforeWaitingTIme)
            {
                bestImproveQue = j;
                bestImproveTime = afterWaitingTime - beforeWaitingTIme;
            }
            cout << beforeWaitingTIme << ' ' << afterWaitingTime <<'\n';
        }
        mentos[bestImproveQue] += 1;
    }
    
    for(int i = 0; i < k; i++)
    {
        answer += CheckWaitingTime(i);
    }
    return answer;
}

/*
n명의 멘토, 1~k로 분류되는 상담유형. 멘토는 자신이 담당한 유형만 가능
참가자가 대기 시간 = 참가자 상담요청 ~ 상담 시작 시간
먼저 상담을 요청한 참가자가 우선시됨 > 큐

묹 : 참가자의 상담 요청 정보가 주어질 떄, 참가자가 대기 시간을 최소로 하는 멘토들 구성. 단 각 유형별로 적어도 1명은 있어야 함

k : 1~5
k <= n <= 20
3 <= reqs <= 300
reqs[i] = [시작 시간, 상담 시간, 상담유형], 여기서 시작 시간은 중복되지 않음
========
그리디 문제인데..
1. 각 k에 1명씩 있는 상태로 CheckWaitTIme(); > k*O(n)
2. 가장 나쁜곳에 +1
3. 1~2를 반복
4. 더 이상 n이 없으면 CheckWaitTime 다 하고 더함. 그게 answer
K^2*O(n) 

================풀이 피드백 1=============
가장 오래 걸리는 시간대에 +1을 하는게 무조건 효율이 좋다 생각했는데, 그건 아닌가?1명을 추가했을 떄 가장 효율이 좋은곳을 찾는게 이득인가?
=============풀이 피드백 2=============
음수가 생길 수 있음. 이걸 생각 못했네

*/