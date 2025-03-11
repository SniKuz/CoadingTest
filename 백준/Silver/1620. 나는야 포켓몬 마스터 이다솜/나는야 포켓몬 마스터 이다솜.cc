#include <bits/stdc++.h>

using namespace std;

int n, m;
map<string, int> poketmonName2Idx;
map<int, string> poketmonIdx2Name;

bool CheckIsNumber(const string& s)
{
    auto it = s.begin();
    while (it != s.end() && isdigit(*it))
    {
        it++;
    }
    return s.empty() == false && it == s.end();
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string poketmon;
        cin >> poketmon;
        poketmonName2Idx[poketmon] = i;
        poketmonIdx2Name[i] = poketmon;
    }
    
    for (int i = 0; i < m; i++)
    {
        string search;
        cin >> search;
        if (CheckIsNumber(search))
        {
            int idx = stoi(search);
            cout << poketmonIdx2Name[idx];
        }
        else
        {
            cout << poketmonName2Idx[search];
        }
        cout << '\n';
    }
    return 0;
}
