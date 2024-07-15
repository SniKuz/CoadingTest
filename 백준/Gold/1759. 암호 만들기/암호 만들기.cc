#include <bits/stdc++.h>

using namespace std;

int l, c;
vector<char> chars;
set<char> s_aeiou = {'a', 'e', 'i', 'o', 'u'};
vector<string> res;

void solution(int s, priority_queue<char,vector<char>, greater<char>> pq)
{
    if(pq.size() == l)
    {
        string print;
        int aeiouCnt = 0;
        int othersCnt = 0;
        while(!pq.empty())
        {
            char e = pq.top(); pq.pop();
            if(s_aeiou.find(e) == s_aeiou.end())
                othersCnt += 1;
            else
                aeiouCnt += 1;
            print += e;
        }
        if(aeiouCnt < 1 || othersCnt < 2) return;
        res.push_back(print);
        return;
    }
    if(s >= c) return;
    solution(s+1, pq);
    pq.push(chars[s]);
    solution(s+1, pq);
}

int main()
{
    cin >> l >> c;
    for(int i = 0; i < c; i++)
    {
        char alpha;
        cin >> alpha;
        chars.push_back(alpha);
    }
    solution(0, {});
    sort(res.begin(), res.end());
    for(const auto& s : res)
    {
        cout << s << '\n';
    }
}