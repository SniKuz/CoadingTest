#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> decimal;

bool Decimal(int num)
{
    if(num == 1) return false;
    if(num == 2) return true;
    if(num == 3) return true;
    for(int i = 2; i*i <= num; i++)
    {
        if(num % i == 0)
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    while(n != 0)
    {
        int n2 = n * 2;
        for(int i = n + 1; i <= n2; i++)
        {
            if(Decimal(i))
                decimal.push_back(i);
        }
        sort(decimal.begin(), decimal.end());
        decimal.erase(unique(decimal.begin(), decimal.end()), decimal.end());
        cout << upper_bound(decimal.begin(), decimal.end(), n2) - lower_bound(decimal.begin(), decimal.end(), n+1) << '\n';
        cin >> n;
    }
}