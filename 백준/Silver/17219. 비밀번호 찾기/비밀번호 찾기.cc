#include <bits/stdc++.h>

using namespace std;

int n, m;
map<string, string> passwords;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        string site, pw;
        cin >> site >> pw;
        passwords[site] = pw;
    }
    for(int i = 0; i < m; i++)
    {
        string site;
        cin >> site;
        cout << passwords[site] << '\n';
    }
    return 0;
}
