#include <bits/stdc++.h>

using namespace std;

int targetLen;
int _target;
int answer = 0;

void solve(const vector<int>& numbers, int currentNum, int currentIndex)
{
    currentIndex++;
    if((currentIndex == targetLen) && (currentNum == _target)) answer++;
    if(currentIndex == targetLen) return;
    solve(numbers, currentNum + numbers[currentIndex], currentIndex);
    solve(numbers, currentNum - numbers[currentIndex], currentIndex);
}

int solution(vector<int> numbers, int target) {
    _target = target;
    targetLen = numbers.size();
    solve(numbers, numbers[0], 0);
    solve(numbers, -numbers[0], 0);
    return answer;
}

/*
재귀가 아니네. 왜냐하면 중복이 가능하잖아
*/