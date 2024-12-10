#include <bits/stdc++.h>

using namespace std;

string str1, str2;

int solution(const string& a, const string& b)
{
    int aSize = a.size(), bSize = b.size();
    vector<vector<int>> dp(bSize+1, vector<int>(aSize+1));
    int maxVal = 0;
    for(int i = 0; i < bSize; i++)
    {
        for(int j = 0; j < aSize; j++)
        {
            if(a[j] == b[i])
            {
                dp[i+1][j+1] = dp[i][j] + 1;
                maxVal = max(maxVal, dp[i+1][j+1]);
            }
        }
    }
    return maxVal;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> str1 >> str2;
    cout << solution(str1, str2);
    return 0;
}