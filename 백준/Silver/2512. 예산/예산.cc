// https://www.acmicpc.net/problem/2512

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> budget;
int total = 0;
int maxBudget = 0;

void binarySearch(int left, int right)
{
    if(left == right)
        return;
    int mid = (left + right) / 2;
    int check = m;
    for(int i = 0; i < n; i++)
    {
        if(budget[i] <= mid)
            check -= budget[i];
        else
            check -= mid;
    }

    if(check >= 0) //can be
    {
        if(maxBudget < mid)
        {
            maxBudget = mid;
        }
        binarySearch(mid+1, right);
    }
    else
    {
        binarySearch(left, mid);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    budget.resize(n);
    for(int i = 0 ; i < n; i++)
    {
        cin >> budget[i];
        total += budget[i];
        if(maxBudget < budget[i])
            maxBudget = budget[i];
    }
    cin >> m;
    if(total > m)
    {
        maxBudget = 0;
        binarySearch(0, m);
    }
    cout << maxBudget;
}