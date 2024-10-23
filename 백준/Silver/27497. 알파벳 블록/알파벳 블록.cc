#include <bits/stdc++.h>
#define data first
#define idx second
#define pci pair<char, int>

using namespace std;

int n;
deque<pci> dq;
vector<int> history;

int main() 
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int cmd; 
        char alpha;
        cin >> cmd;
        if(cmd != 3)
        {
            cin >> alpha;
        }
        
        switch(cmd)
        {
            case 1:
                {
                    dq.push_back({alpha, i});
                    history.push_back(i);
                }
                break;
            case 2:
                {
                    dq.push_front({alpha, i});
                    history.push_back(i);
                }
                break;
            case 3:
                {
                    if(dq.empty())
                    {
                        // do nothing
                    }
                    else if(dq.back().idx == history.back())
                    {
                        dq.pop_back();
                        history.pop_back();
                    }
                    else
                    {
                        dq.pop_front();
                        history.pop_back();
                    }
                }
                break;
        }
    }
    if(dq.empty())
    {
        cout << 0;
    }
    else
    {
        for(const auto& e : dq)
        {
            cout << e.data;
        }
    }
    return 0;
}
