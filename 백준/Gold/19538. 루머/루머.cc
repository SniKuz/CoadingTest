#include <bits/stdc++.h>
#define Time first
#define Node second
#define pii pair<int, int>
#define MAXVAL 200001

using namespace std;

int n, m;
vector<vector<int>> board(MAXVAL);
vector<int> rumors;
vector<pii> believePer(MAXVAL); //믿는 인원, 총 주변인 수
vector<int> res(MAXVAL, -1);

void Search()
{
    queue<int> q, q2;
    int t = 0;
    for(const auto& e: rumors)
    {
        q.push(e);
        res[e] = 0;
    }
    while(q.empty() == false || q2.empty() == false)
    {
        t++;
        if(q.empty() == false)
        {
            while(q.empty() == false)
            {
                auto cur = q.front(); q.pop();
                
                for(const auto& e : board[cur])
                {
                    believePer[e].first++;
                    if(res[e] < 0 && believePer[e].first >= believePer[e].second/2)
                    {
                        q2.push(e);
                        res[e] = t;
                    }
                }
            }
        }
        else
        {
            while(q2.empty() == false)
            {
                auto cur = q2.front(); q2.pop();
                
                for(const auto& e : board[cur])
                {
                    believePer[e].first++;
                    if(res[e] < 0 && believePer[e].first >= believePer[e].second/2)
                    {
                        q.push(e);
                        res[e] = t;
                    }
                }
            }
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int friends;
        cin >> friends;
        while(friends != 0)
        {
            board[i].push_back(friends);
            board[friends].push_back(i);
            believePer[i].second++;
            believePer[friends].second++;
            cin >> friends;
        }
    }
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int ru;
        cin >> ru;
        rumors.push_back(ru);
    }
    Search();
    for(int i = 1; i <= n; i++)
    {
        cout << res[i] << ' ';
    }
    return 0;
}
