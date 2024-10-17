#include <bits/stdc++.h>

using namespace std;

int n;

queue<int> q;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string cmd;
        cin >> cmd;
        if(cmd.compare("push")==0)
        {
            int x;
            cin >> x;
            q.push(x);
        }
        else if(cmd.compare("pop")==0)
        {
            if(q.empty()) cout << -1 << '\n';
            else
            {
                cout << q.front() << '\n';
                q.pop(); 
            }
        }
        else if(cmd.compare("size")==0)
        {
            cout << q.size() << '\n';
        }
        else if(cmd.compare("empty")==0)
        {
            if(q.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(cmd.compare("front")==0)
        {
            if(q.empty()) cout << -1 << '\n';
            else cout << q.front() << '\n';
        }
        else if(cmd.compare("back")==0)
        {
            if(q.empty()) cout << -1 << '\n';
            else cout << q.back() << '\n';
        }
    }
    return 0;
}
