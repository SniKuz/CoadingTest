#include <bits/stdc++.h>
#define workTime first
#define node second

using namespace std;

int tc;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for(int t = 0; t < tc; t++)
    {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> times(n+1);
        vector<vector<int>> board(n+1);
        vector<int> inputs(n+1); // 이 건물을 짓기 전에 지어야 하는 남은 건물
        int maxTime = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> times[i];
            if(maxTime < times[i]) maxTime = times[i];
        }
        for(int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            board[x].push_back(y);
            inputs[y]++;
        }
        int w; //win 건물
        cin >> w;
        
        // check start buildings
        list<pair<int, int>> buildings;
        for(int i = 1; i <= n; i++)
        {
            if(inputs[i] == 0)
            {
                buildings.push_back({times[i], i});
                //cout << buildings.back().first << ' ' << buildings.back().second << '\n';
            }
        }
        
        // solution
        bool solve = false;
        for(int i = 0; i <= maxTime * n; i++)
        {
            auto cur = buildings.begin();
            vector<pair<int,int>> newNodes;
            while(cur != buildings.end())
            {
                if(--(*cur).workTime == 0)
                {
                    if((*cur).node == w)
                    {
                        cout << i+1 << '\n';
                        solve = true;
                        break;
                    }
                    else
                    {
                        for(const auto &next : board[(*cur).node])
                        {
                            if(--inputs[next] == 0)
                            {
                                newNodes.push_back({times[next], next});
                            }
                        }
                        cur = buildings.erase(cur);
                    }
                }
                else
                {
                    cur++;
                }
            }
            if(solve) break;
            for(const auto &next : newNodes)
            {
                buildings.push_back(next);
            }
        }
        if(!solve) cout << 0 << '\n';
    }
    return 0;
}