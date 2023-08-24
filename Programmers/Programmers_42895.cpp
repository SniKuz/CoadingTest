// https://school.programmers.co.kr/learn/courses/30/lessons/42895

#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> cache[9];


int solution(int N, int number) {
    int tmp = N;
    for(int i = 1 ; i <= 8; i++)
    {
        if(number == tmp) return i;
        cache[i].push_back(tmp);
        tmp += N * pow(10, i);
    }

    for(int i = 2; i <= 8; i++)
    {
        for(int j = 1; j < i; j++)
        {
            for(auto x : cache[i-j])
            {
                if(x==0) continue;
                for(auto y : cache[j])
                {
                    if(y==0) continue;
                    cache[i].push_back(x*y), cache[i].push_back(x/y), cache[i].push_back(x+y), cache[i].push_back(x-y);

                }
            }
        }
        for(auto k : cache[i]) if(k == number) return i;
    }


    return -1;
}

/*
1<=N<=9
1<=number<=32000
최솟값이 8보다 크면 return -1

(정답 아이디어 봄)
사용횟수 x회라면 N = 5, number 12일때
x가 1회라는건 5밖에 없음
x가 2회면 55 or N(1)-N(1)간의 사칙연산
x가 3회면 555 or N(2)-N(1) or N(1)- N(2)간 사칙연산
...

N=5, num = 12일떄
1회면 5
2회면 55, 5/5, 5-5, 5+5, 5*5
3회면 555, 5/5+5, 5/5-5 ....
F(x) = F(x-1)F(1) + F(x-2)F(2) + ... + F(1)F(x-1)간 사칙연산이라네요...

나중에 다 지우고 다시 풀어봐. 위에 설명ㅇ 코드도 참고해서 푼거라 제대로한게 아님
https://kim519620.tistory.com/entry/N%EC%9C%BC%EB%A1%9C-%ED%91%9C%ED%98%84-feat-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-42895%EB%B2%88
*/