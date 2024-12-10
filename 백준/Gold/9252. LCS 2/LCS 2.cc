#include <bits/stdc++.h>
#define cnt first
#define str second
#define pii pair<int, int>

using namespace std;

string str1, str2;
pii res;

void solution(const string& a, const string& b)
{
    int aSize = a.size(), bSize = b.size();
    vector<vector<pair<int, pii>>> dp(bSize+1, vector<pair<int, pii>>(aSize+1, {0, {-1, -1}}));
    for(int i = 0; i < bSize; i++)
    {
        for(int j = 0; j < aSize; j++)
        {
            if(a[j] == b[i])
            {
                dp[i+1][j+1].cnt = dp[i][j].cnt + 1;
                dp[i+1][j+1].str = {i, j};
            }
            else
            {
                if(dp[i+1][j].cnt > dp[i][j+1].cnt)
                {
                    dp[i+1][j+1].cnt = dp[i+1][j].cnt;
                    dp[i+1][j+1].str = dp[i+1][j].str;
                }
                else
                {
                    dp[i+1][j+1].cnt = dp[i][j+1].cnt;
                     dp[i+1][j+1].str = dp[i][j+1].str;
                }
            }
        }
    }
    cout << dp[bSize][aSize].cnt << '\n';
    string resStr;
    auto cur = dp[bSize][aSize].str;
    while(cur.first != -1 && cur.second != -1)
    {
        resStr.push_back(a[cur.second]);
        cur = dp[cur.first][cur.second].str;
    }
    for(auto itr = resStr.rbegin(); itr != resStr.rend(); itr++)
        cout << *itr;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> str1 >> str2;
    solution(str1, str2);
    return 0;
}