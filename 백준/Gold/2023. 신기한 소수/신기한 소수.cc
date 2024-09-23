#include <bits/stdc++.h>

using namespace std;

int n;
int startDecimal[] = {2, 3, 5, 7};
int linkDecimal[] = {1, 3, 5, 7, 9};
unordered_set<int> decimals;
priority_queue<int, vector<int>, greater<int>> pq;

bool IsDecimal(int x)
{
    if(x == 1) return false;
    if(decimals.find(x) != decimals.end())
        return true;

    for(int i = 2; i * i <= x; i++)
    {
        if(x % i == 0)
            return false;
    }
    return true;
}

void DFS(int x, int l)
{
    if(l == n)
    {
        if(IsDecimal(x))
            pq.push(x);
        return;
    }
    for(const auto& num : linkDecimal)
    {
        int temp = x * 10 + num;
        if(IsDecimal(temp))
        {
            DFS(temp, l+1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    decimals.insert(2);
    decimals.insert(3);

    for(int i = 0; i < 4; i++)
    {
        DFS(startDecimal[i], 1);
    }

    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        cout << cur << '\n';
    }
}