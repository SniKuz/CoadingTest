// https://school.programmers.co.kr/learn/courses/30/lessons/72413

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> table(201, vector<int>(201, 2e8));
int answer = 2e9;

void PrintTable(int n)
{
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
            cout << table[i][j] << ' ';
        cout << '\n';
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    for(auto fare : fares)
    {
        table[fare[0]][fare[1]] = fare[2];
        table[fare[1]][fare[0]] = fare[2];
    }

    for(int i = 0; i <= n; i++) table[i][i] = 0;

    for(int k = 0; k <= n; k++)
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= n; j++)
                table[i][j] = min(table[i][j], table[i][k] + table[k][j]);
    
    for(int i = 0; i <= n; i++)
        answer = min(answer, (table[s][i] + table[i][a] + table[i][b]));
    
    return answer;
}

/*

*/