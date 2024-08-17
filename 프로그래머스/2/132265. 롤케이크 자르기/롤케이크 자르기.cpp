#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    unordered_map<int, int> leftCake;
    unordered_map<int, int> rightCake;
    for(int i = 0; i < topping.size(); i++)
    {
        if(rightCake.find(topping[i]) == rightCake.end())
            rightCake[topping[i]] = 1;
        else
            rightCake[topping[i]] += 1;
    }
    
    int rightRemoved = 0;
    
    for(const auto& e : topping)
    {
        if(leftCake.find(e) == leftCake.end())
            leftCake[e] = 1;
        else
            leftCake[e] += 1;
        
        rightCake[e] -= 1;
        if(rightCake[e] <= 0)
            rightRemoved++;
        if(leftCake.size() == (rightCake.size() - rightRemoved))
            answer++;
    }
    
    return answer;
}