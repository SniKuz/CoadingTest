#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

vector<vector<vector<int>>> visited(11, vector<vector<int>>(11, vector<int>(4, 0))); //0 : left, 1 up, 2 right, 4 down comefrom

map<char, pair<int, int>> cmd = {{'U', {-1, 0}}, 
                                 {'D', {1, 0}}, 
                                 {'L', {0, -1}}, 
                                 {'R', {0, 1}}};
map<char, int> checkDir = {{'L', 0}, {'U', 1}, {'R', 2}, {'D', 3}};
map<char, char> oppositeDir = {{'L', 'R'}, {'R','L'}, {'U','D'}, {'D','U'}};

int solution(string dirs) {
    int answer = 0;
    pair<int, int> cur = {5, 5};
    for(const auto& dir : dirs)
    {
        int nextX = cur.x + cmd[dir].x;
        int nextY = cur.y + cmd[dir].y;
        if(nextX < 0 || nextX > 10 || nextY < 0 || nextY > 10)
            continue;
        
        if(visited[nextX][nextY][checkDir[dir]] == 0 && visited[cur.x][cur.y][checkDir[oppositeDir[dir]]] == 0)
        {
            answer++;
            visited[nextX][nextY][checkDir[dir]] = 1;
            visited[cur.x][cur.y][checkDir[oppositeDir[dir]]] = 1;
        }
        cur = {nextX, nextY};
    }
    
    return answer;
}