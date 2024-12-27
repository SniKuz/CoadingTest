#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v1, v2;
bool res = true;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    v1.resize(n); 
    for(int i = n-1; i >= 0; i--)
    {
        cin >> v1[i];
    }
    int cur = 1;
    while(v1.empty() == false || v2.empty() == false)
    {
        if(v1.empty() == false && v1.back() == cur)
        {
            v1.pop_back();
            cur++;
        }
        else if(v2.empty() == false && v2.back() == cur)
        {
            v2.pop_back();
            cur++;
        }
        else
        {
            while(v1.empty() == false && v1.back() != cur)
            {
                v2.push_back(v1.back()); v1.pop_back();
            }
            if(v1.empty() == false)
            {
                v1.pop_back();
                cur++;
            }
            else
            {
                res = false;
                break;
            }
        }
    }
    
    
    if(res)
        cout << "Nice";
    else
        cout << "Sad";
    
    return 0;
}
