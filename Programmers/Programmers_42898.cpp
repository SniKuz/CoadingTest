// https://school.programmers.co.kr/learn/courses/30/lessons/42898

// https://school.programmers.co.kr/learn/courses/30/lessons/42898

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int> > table(100, vector(100, 0));

int solution(int m, int n, vector<vector<int>> puddles) {
    for(auto puddle : puddles)
    {
        table[puddle[1]-1][puddle[0]-1] = -1;
    }

    for(int i = 0; i < m; i++)
    {
        if(table[0][i] == -1) break;
        table[0][i] = 1;
    }
    for(int i = 0; i < n; i++)
    {
        if(table[i][0] == -1) break;
        table[i][0] = 1;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(table[i][j] == -1) continue;
            if(i == 0 || j == 0) continue;
            if(table[i-1][j] != -1) table[i][j] = (table[i][j] + table[i-1][j]) % 1000000007;
            if(table[i][j-1] != -1) table[i][j] = (table[i][j] + table[i][j-1]) % 1000000007;
        }
    }
    
    return table[n-1][m-1];
}


/*
최단 경로의 개수. 그러니까 최단 경로가 몇이냐가 아니라 개수가 몇이냐 라는 문제
왜 안풀렸을까? 왜냐하면 puddle이나 m,n이 반대로 되어있어서 puddle 반대때문에

2번쨰로 왜 효율성이 다틀렸을까? 일부로 큰 값 뜨게 해서 마지막 return이 아니라 중간중간 계속 모듈러 연산을 해줘야함
*/