#include <bits/stdc++.h>

using namespace std;

int n;
deque<char> dq;
int cnt = 80;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        dq.push_back(c);
    }

    while(!dq.empty())
    {
        char target;
        if(dq.front() != dq.back() || dq.size() <= 2)
        {
            if(dq.front() < dq.back())
            {
                target = dq.front(); dq.pop_front();
            }
            else
            {
                target = dq.back(); dq.pop_back();
            }
        }
        else
        {
            auto front = dq.begin();
            auto back = dq.end(); back--;
            while(front != back && *front == *back)
            {
                front++;
                back--;
            }
            if(front == back)
            {
                target = dq.front(); dq.pop_front();
            }
            else
            {
                if(*front < *back)
                {
                    target = dq.front(); dq.pop_front();
                }
                else
                {
                    target = dq.back(); dq.pop_back();
                }
            }
        }
        cout << target;
        if(--cnt == 0)
        {
            cout << '\n';
            cnt = 80;
        }
    }
}