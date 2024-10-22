#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> price;
vector<int> cars;
queue<int> waitingQ;
priority_queue<int,vector<int>, greater<int>> pq; //비어있는 주차장 번호
map<int, int> parking; //해당 번호가 어디 주차장 쓰고 있는지?
int res = 0;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    price.resize(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> price[i];
        pq.push(i);
    }
    cars.resize(m+1);
    for(int i = 1; i <= m; i++)
    {
        cin >> cars[i];
    }
    for(int i = 0; i < 2*m; i++)
    {
        int cmd; cin >> cmd;
        if(cmd > 0)
        {
            if(pq.empty())
            {
                waitingQ.push(cmd);
            }
            else
            {
                auto pos = pq.top(); pq.pop();
                parking[cmd] = pos;
            }
        }
        else
        {
            cmd = -cmd;
            res += price[parking[cmd]] * cars[cmd];
            if(waitingQ.empty() == false)
            {
                auto next = waitingQ.front(); waitingQ.pop();
                parking[next] = parking[cmd];
                
            }
            else
            {
                pq.push(parking[cmd]);
            }
            parking[cmd] = 0;
        }
    }
    cout << res;
    return 0;
}
