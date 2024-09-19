#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> A;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        if(A.empty() || A.back() < temp)
        {
            A.push_back(temp);
        }
        else
        {
            auto p = lower_bound(A.begin(), A.end(), temp);
            *p = temp;
        }
    }
    cout << A.size();
}