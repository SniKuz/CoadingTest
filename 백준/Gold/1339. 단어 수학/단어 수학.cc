#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> v(10);
map<char, int> weight;
int res = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        int cnt = pow(10, v[i].size());
        for(const auto& e : v[i])
        {
            if(weight.find(e) == weight.end())
                weight[e] = cnt;
            else
                weight[e] += cnt;
            cnt /= 10;
        }
    }
    priority_queue<pair<int, char>> pq;
    for(const auto& kv : weight)
    {
        pq.push({kv.second, kv.first});
    }
    int cnt = 9;
    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        weight[cur.second] = cnt--;
    }

    for(int i = 0; i < n; i++)
    {
        string temp = "";
        for(const auto& e : v[i])
        {
            temp += '0' + weight[e];
        }
        res += stoi(temp);
    }
    cout << res;
}