//https://school.programmers.co.kr/learn/courses/30/lessons/42883

#include <string>
#include <vector>

using namespace std;

vector<char> nums;

string solution(string number, int k) {
    string answer = "";

    for(auto n : number)
    {
        if(k == 0){
            nums.push_back(n);
            continue;
        } 
        if(nums.empty()) nums.push_back(n);
        else if(nums.back() < n)
        {
            while(!nums.empty() && nums.back() < n)
            {
                nums.pop_back();
                k--;
            }
            nums.push_back(n);
        }
        else{
            nums.push_back(n);
        }
    }

    for(auto n : nums)
        answer += n;
    return answer;
}


/*
7758
*/