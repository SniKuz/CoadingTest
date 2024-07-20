#include <bits/stdc++.h>

using namespace std;

int n, m, q;
vector<int> ptrs(1, 0);
map<string, int> checkCmd = {{"assign", 0}, {"reset", 1}, {"swap", 2}};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m >> q;
    for(int i = 0; i < m; i++)
    {
        int target;
        cin >> target;
        ptrs.push_back(target);
    }
    for(int i = 0; i < q; i++)
    {
        string cmd;
        int a, b;
        cin >> cmd;
        cin >> a;
        if(checkCmd[cmd] == 0)
        {
            cin >> b;
            ptrs[a] = ptrs[b];
        }
        else if(checkCmd[cmd] == 2)
        {
            cin >> b;
            int temp = ptrs[a];
            ptrs[a] = ptrs[b];
            ptrs[b] = temp;
        }
        else
        {
            ptrs[a] = 0;
        }
    }
    set<int> s;
    for(const auto& e : ptrs)
    {
        if(e != 0)
            s.insert(e);
    }
    cout << s.size() << '\n';
    for(const auto& e : s)
    {
        cout << e << '\n';
    }
}