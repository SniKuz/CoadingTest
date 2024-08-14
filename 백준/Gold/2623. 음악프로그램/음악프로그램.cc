#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> board(1001);
vector<int> input(1001, 0);
vector<int> waiting;

void SearchNoInput()
{
    for(int i = 1; i <= n; i++)
    {
        if(input[i] == 0)
        {
            waiting.push_back(i);
            input[i] = -1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        vector<int> v;
        int singer;
        cin >> singer;
        for(int j = 0; j < singer; j++)
        {
            int temp;
            cin >> temp;
            for(const auto& e : v)
            {
                board[e].push_back(temp);
                input[temp]++;
            }
            v.push_back(temp);
        }
    }
    SearchNoInput();
    vector<int> res;
    while(!waiting.empty())
    {
        auto cur = waiting.back(); waiting.pop_back();
        res.push_back(cur);
        for(const auto& e : board[cur])
        {
            input[e]--;
        }
        SearchNoInput();
    }
    if(res.size() < n)
    {
        cout << '0';
    }
    else
    {
        for(const auto& e : res)
        {
            cout << e << '\n';
        }
    }
}