#include <bits/stdc++.h>

using namespace std;

int n, m;
string s;
int res = 0;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> s;
    string p = "";
    for(int i = 0; i < n; i++)
    {
        p.push_back('I');
        p.push_back('O');
    }
    p.push_back('I');
    
    int cur = s.find(p);
    while(cur != string::npos)
    {
        res++;
        cur = s.find(p, cur+1);
    }
    cout << res;
    return 0;
}
