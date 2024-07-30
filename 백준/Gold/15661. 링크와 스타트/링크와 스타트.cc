#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> powers(20, vector<int>(20));
int res = 2e9;

void solution(vector<int> teamStart, vector<int> teamLink, int idx)
{
    if(idx >= n)
    {
        if(teamStart.size() < 1 || teamLink.size() < 1) return;

        int tsPoint = 0, tlPoint = 0;

        while(!teamStart.empty())
        {
            auto cur = teamStart.back(); teamStart.pop_back();
            for(const auto& e : teamStart)
            {
                tsPoint += powers[cur][e];
                tsPoint += powers[e][cur];
            }
        }
        while(!teamLink.empty())
        {
            auto cur = teamLink.back(); teamLink.pop_back();
            for(const auto& e : teamLink)
            {
                tlPoint += powers[cur][e];
                tlPoint += powers[e][cur];
            }
        }
        int pointGap = abs(tsPoint - tlPoint);
        if(res > pointGap)
            res = pointGap;
        return;
    }

    teamStart.push_back(idx);
    solution(teamStart, teamLink, idx+1);
    teamStart.pop_back();
    teamLink.push_back(idx);
    solution(teamStart, teamLink, idx+1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> powers[i][j];
        }
    }
    solution({}, {}, 0);
    cout << res;
}