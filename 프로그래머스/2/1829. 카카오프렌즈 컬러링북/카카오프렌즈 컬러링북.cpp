#include <vector>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int largestArea = 0, areaNum = 0;
    vector<vector<int>> visited(m, vector<int>(n, 0));
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};

    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            int count = 0, element = -1;
            vector<pair<int, int>> stack;
            if(visited[i][j] == 0 && picture[i][j] != 0)
            {
                ++areaNum;
                stack.push_back({i,j});
                element = picture[i][j];
                ++count;
                visited[i][j] = 1;
            }
            while(!stack.empty())
            {
                auto current = stack.back(); stack.pop_back();
                
                for(int k = 0; k < 4; ++k)
                {
                    if(current.first + dx[k] < 0 || current.first + dx[k] >= m) continue;
                    if(current.second + dy[k] < 0 || current.second + dy[k] >= n) continue;
                    if(visited[current.first + dx[k]][current.second + dy[k]] != 0) continue;

                    if(picture[current.first + dx[k]][current.second + dy[k]] == element)
                    {
                        stack.push_back({current.first + dx[k], current.second + dy[k]});
                        visited[current.first + dx[k]][current.second + dy[k]] = 1;
                        ++count;
                    }
                }
            }
            largestArea = largestArea > count ? largestArea : count; 
        }
    }
    return {areaNum, largestArea};
}