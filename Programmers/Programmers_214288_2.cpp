
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<pair<int, int>>> waitingQues(5);
vector<int> mentos(5);
int answer = 0;

int CheckWaitingTime(int category)
{
    int totalWaitingTime = 0;
    int mentoNum = mentos[category];
    vector<pair<int, int>> consultings(mentoNum);

    for(auto counselor : waitingQues[category])
    {
        if(mentoNum > 0) consultings[--mentoNum] = counselor;
        else
        {
            int firstFinshMento;
            int finishTime = 2e9;
            bool noWaitingTime = false;

            for(int i = 0; i < consultings.size(); i++)
            {
                int consultingFinishTime = consultings[i].first + consultings[i].second;
                if(consultingFinishTime < counselor.first)
                {
                    consultings[i] = counselor;
                    noWaitingTime = true;
                    break;
                }
                else if(finishTime > consultingFinishTime)
                {
                    finishTime = consultingFinishTime;
                    firstFinshMento = i;
                }
            }
            if(noWaitingTime) continue;
            totalWaitingTime += finishTime - counselor.first;
            consultings[firstFinshMento].first = consultings[firstFinshMento].first + consultings[firstFinshMento].second;
            consultings[firstFinshMento].second = counselor.second;
        }
    }
    return totalWaitingTime;
}

int solution(int k, int n, vector<vector<int>> reqs) {
    //1. init
    for(auto req : reqs)
    {
        waitingQues[req[2]-1].push_back({req[0], req[1]});
    }
    for(int i = 0; i < k; i++)
    {
        mentos[i] = 1;
    }
    n -= k;

    //2. check bestImproved solution category when mento+1
    for(int i = 0; i < n; i++)
    {
        int bestImprovedQue = -1;
        int bestImprovedTime = -1;
        for(int j = 0; j < k; j++)
        {
            int beforeWaitingTIme = CheckWaitingTime(j);
            mentos[j]++;
            int afterWaitingTime = CheckWaitingTime(j);
            mentos[j]--;

            if(bestImprovedTime < abs(beforeWaitingTIme - afterWaitingTime))
            {
                bestImprovedQue = j;
                bestImprovedTime = abs(beforeWaitingTIme - afterWaitingTime);
            }
        }
        mentos[bestImprovedQue]++;
    }
    
    //3. check all line Waiting time
    for(int i = 0; i < k; i++)
    {
        answer += CheckWaitingTime(i);
    }
    return answer;
}

/*
1번에 있는걸 천천히 다시 써보면서 점검해서 정리한 코드. 통과함

-풀이-
1. 각 상담 유형에 맞게 분리.
2. 상담유형별로 멘토가 1명 늘어날 때 가장 개선되는 곳에 멘토 +1
3. 멘토 n명이 꽉 채워질 때 까지 1~2를 반복
*이 방법에 추가로 DP를 섞어서 푼 사람도 있는듯
*/