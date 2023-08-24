// https://school.programmers.co.kr/learn/courses/30/lessons/1844

#include<vector>
#include <deque>

using namespace std;

int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};
vector<vector<bool>> visited(100, vector<bool>(100, false));

int solution(vector<vector<int> > maps)
{
    deque<pair<int,int>> que;
    que.push_back({0,0});
    int r = maps.size(), c = maps[0].size();

    while(!que.empty())
    {
        auto cur = que.front();
        que.pop_front();
        visited[cur.first][cur.second] = true;

        for(int i = 0; i < 4; i++)
        {
            int nextX = cur.first + dirX[i];
            int nextY = cur.second + dirY[i];

            if(nextX >= r || nextX < 0 || nextY >= c || nextY < 0) continue;
            if(maps[nextX][nextY] == 0) continue;
            if(visited[nextX][nextY]) continue;
            maps[nextX][nextY] += maps[cur.first][cur.second];
            if(nextX == r-1 && nextY == c-1) return maps[nextX][nextY];

            que.push_back({nextX, nextY});
            
        }
    }

    return -1;
}

/*
시간초과?
*/