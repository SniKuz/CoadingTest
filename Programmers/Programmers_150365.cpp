// https://school.programmers.co.kr/learn/courses/30/lessons/150365

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> table(51, vector<int>(51, 0));
string answer = "";

string solution(int n, int m, int x, int y, int r, int c, int k) {
    table[x][y] = 1; table[r][c] = -1;

    int interval = k - (abs(r-x) + abs(c-y));
    if((interval)%2 != 0) return "impossible";

    if(x < r)
    {
        for(; x != r; x++)    
            answer += 'd';

    }
    if(y > c)
    {
        for(; y != c; y--)
            answer +='l';
    }
    if(y < c)
    {
        for(; y != c; y++)
            answer += 'r';
    }
    if(x > r)
    {
        for(; x != r; x--)
        {
            answer += 'u';
        }
    }

    // 이부분이 문제네 lllrrr이 가능하니. 반대로 또 llrlrr 도 가능하겠고
    /*
    left로 벽이 닿을때까지 가서. 벽에 닿았는데 interval을 다 못썼으면 lrlrlrlr
    */
    int temp = interval/2;
    int curX = c;
    
    cout << answer;
    while(temp > 0 && curX > 1)
    {
        answer += 'l';
        curX--;
        temp--;
    }
    while(temp > 0)
    {
        answer += "rl";
        temp -= 2;
    }
    if(temp == 0)
    {
       for(int i = 0; i < interval/2; i++)
        {
            answer += 'r';
        } 
    }
    
    return answer;
}

/*
down > left > right > up

6 6 2 6 6 5 11 ddddl + lllrrr

이게 무슨 문제지..? 노가다 문제 맞나? 한번 다시 고민 ㄱ
*/