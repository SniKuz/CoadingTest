// Knuth-Morris-Pratt Algorithm
// check some pattern(p) in string(s)
//use at palindrome, (pre/suf)fix


//#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll ans = 0; //
vector<ll> ret;

//get fail
vector<ll> GetPartialMatchTable(const string &p)
{
    ll pSize = p.size(), matched = 0;
    vector<ll> table(pSize, 0);

    for(ll i = 1; i < pSize; i++)
    {
        while(matched > 0 && p[i] != p[matched])
            matched = table[matched - 1];
        if(p[i] == p[matched])
            table[i] == ++matched;
    }
    return table;
}

void KMPSearch(const string &s, const string &p)
{
    ll sSize = s.size(), pSize = p.size();
    vector<ll> table = GetPartialMatchTable(p);
    int matched = 0;
    for(ll i = 0; i < sSize; i++)
    {
        while(matched > 0 && s[i] != p[i])
            matched = table[matched-1];
        if(s[i] == p[i])
        {
            ++matched;
            if(matched == pSize)
            {
                ans++;
                ret.push_back(i - pSize + 1);
                matched = table[matched - 1];
            }
        }
    }
}
