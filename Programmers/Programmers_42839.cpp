// link https://school.programmers.co.kr/learn/courses/30/lessons/42839

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

vector<char> papers;
vector<bool> used(8, false);
int papersSize;
int answer = 0;
set<int> prime;

bool PrimeCheck(int d)
{
    if(d<2) return false;
    for(int i = 2; i < (int)sqrt(d)+1; i++)
    {
        if(d%i==0) return false;
    }
    return true;
}
void MakeNumberByPapers(string s)
{
    for(int i = 0; i < papersSize; i++)
    {
        if(!used[i])
        {
            s+= papers[i];
            used[i] = true;
            if(PrimeCheck(stoi(s))){
                if(prime.find(stoi(s)) == prime.end())
                {
                    answer++;
                    prime.insert(stoi(s));
                }
            }
            MakeNumberByPapers(s);
            used[i] = false;
            s.pop_back();
        }
    }
}

int solution(string numbers) {
    for(auto number : numbers)
    {
        papers.push_back(number);
    }
    papersSize = papers.size();
    MakeNumberByPapers("");

    return answer;
}

/*
문제였던 부분 : primeCheck부분에서 i가 sqrt(val)+1했는데, (int)sqrt(val)+1로 바꾸니 해결
아마 제곱근에서 큰 값이 부정확해서?
*/