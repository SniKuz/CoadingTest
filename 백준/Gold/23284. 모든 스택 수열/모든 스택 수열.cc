#include <bits/stdc++.h>

using namespace std;

int n;

vector<vector<int>> board;

void BF(int idx, vector<int> v, vector<int> res)
{
    if(idx > n)
    {
        if(v.size() + res.size() == n)
        {
            vector<int> temp;
            for(const auto& e : res)
                temp.push_back(e);
            for(auto itr = v.rbegin(); itr != v.rend(); itr++)
                temp.push_back(*itr);
            board.push_back(temp);
        }
        return;
    }
    
    // 지금까지 넣은거 다 pop하고 다시 넣음 > 다하면 안되고 차근차근해야함. 먼저 v에 push_back(idx)하거 BF돌리고, v에서 빼고 넣고 돌리고
    v.push_back(idx);
    BF(idx+1, v, res);
    v.pop_back();
    int vSize = v.size();
    for(int i = 0; i < vSize; i++)
    {
        res.push_back(v.back());
        v.pop_back();
        v.push_back(idx);
        BF(idx+1, v, res);
        v.pop_back();
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    BF(1, {}, {});
    while(board.empty() == false)
    {
        auto e = board.back(); board.pop_back();
        for(int i = 0; i < n; i++)
            cout << e[i] << ' ';
        cout << '\n';
    }
    return 0;
}