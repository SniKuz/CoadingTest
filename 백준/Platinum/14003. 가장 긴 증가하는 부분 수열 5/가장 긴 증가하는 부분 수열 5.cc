#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> inputs;
vector<int> buf;
vector<int> res;

void LookBack(int idx, int num)
{
    if (idx < 0) { return; }
    if (res[idx] == num)
    {
        LookBack(idx -1, num -1);
        cout << inputs[idx] << ' ';
    }
    else
    {
        LookBack(idx -1, num);
    }
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    inputs.resize(n);
    res.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> inputs[i];
    }
    
    for(int i = 0; i < n; i++)
    {
        if (buf.empty() || buf.back() < inputs[i])
        {
            buf.push_back(inputs[i]);
            res[i] = buf.size();
        }
        else
        {
            auto pos = lower_bound(buf.begin(), buf.end(), inputs[i]);
            *pos = inputs[i];
            res[i] = (pos - buf.begin() + 1);
        }
    }
    cout << buf.size() << '\n';
    LookBack(res.size(), buf.size());
    return 0;
}
