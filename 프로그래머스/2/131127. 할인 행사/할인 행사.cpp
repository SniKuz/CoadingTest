#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> wantSet;
    for(int i = 0; i < want.size(); i++)
    {
        wantSet[want[i]] = number[i];
    }
    map<string, int> discountSet;
    for(const auto& e : discount)
    {
        discountSet[e] = 0;
    }
    for(int i = 0; i < 10; i++)
    {
        discountSet[discount[i]] += 1;
    }
    
    //solve
    int s = 0, e = 9;
    while(e < discount.size())
    {
        bool Buy = true;
        for(const auto& kv : wantSet)
        {
            if(discountSet[kv.first] < kv.second)
            {
                Buy = false;
                break;
            }
        }
        cout << '\n';
        if(Buy)
            answer++;
        
        discountSet[discount[s++]] -= 1;
        e++;
        if(e >= discount.size())
            break;
        else
            discountSet[discount[e]] += 1;
    }
    
    return answer;
}
/*
연속으로 10개를 만족하지 않으면 선택 X, 
선택할 수 있는 날짜 개수 구하기
*/