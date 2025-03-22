#include <bits/stdc++.h>
#define Val first
#define Pos second
#define pii pair<int, int>

using namespace std;

int n, l;
int inputs[5000001];
deque<pii> dq;


int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        cin >> inputs[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        if (dq.empty() == false && i == dq.front().Pos + l)
        {
            dq.pop_front();
        }
        while(dq.empty() == false && dq.back().Val > inputs[i])
        {
            dq.pop_back();
        }
        dq.push_back({inputs[i], i});
        cout << dq.front().Val << ' ';
    }
    
    return 0;
}
