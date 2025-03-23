#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

int n;
vector<pii> lectures;
priority_queue<int, vector<int>, greater<int>> pq;

int main() 
{
    cin >> n;
    lectures.resize(n);
    for (int i = 0; i < n; i++)
    {
        int idx, start, finish;
        cin >> idx >> start >> finish;
        lectures[i] = {start, finish};
    }
    
    sort(lectures.begin(), lectures.end());
    
    int res = 1;
    for (int i = 0; i < n; i++)
    {
        if (pq.empty())
        {
            pq.push(lectures[i].second);
        }
        else
        {
            if (pq.top() > lectures[i].first)
            {
                res++;
            }
            else
            {
                pq.pop();
            }
            pq.push(lectures[i].second);
        }
    }
    cout << res;
    return 0;
}
