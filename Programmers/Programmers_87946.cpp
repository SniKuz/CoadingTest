#include <string>
#include <vector>
#include <iostream>

using namespace std;
bool visited[8] = {false, };
int ans = 0;

void BF(int k, vector<vector<int>> dungeons, int cnt)
{
    ans = max(ans, cnt);
    for(int i = 0; i < dungeons.size(); i++)
    {
        if(!visited[i] && dungeons[i][0] <=k)
        {
            visited[i] = true;
            cnt++;
            BF(k-dungeons[i][1], dungeons, cnt);
            cnt--;
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    BF(k, dungeons, 0);
    return ans;
}
/*
완전탐색
던전은 많아도 8개
sort로 하기에는 맞지가 않음. 크기도 작으니
*/