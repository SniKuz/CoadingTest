#include <bits/stdc++.h>
#define INF 1000000000

using namespace std;

int n;
vector<int> nums;
string expressionStr = "+-*/";

int minRes = INF+1;
int maxRes = -INF - 1;

void BF(int cur, int val, vector<int> expression)
{
    if(val < -INF) val = -INF;
    else if(val > INF) val = INF;

    if(cur == nums.size())
    {
        minRes = minRes < val ? minRes : val;
        maxRes = maxRes > val ? maxRes : val;
        return;
    }
    for(int i = 0; i < 4; i++)
    {
        if(expression[i] > 0)
        {
            expression[i]--;
            switch (expressionStr[i])
            {
            case '+':
                {
                    BF(cur+1, val + nums[cur], expression);
                }
                break;
            case '-':
                {
                    BF(cur+1, val - nums[cur], expression);
                }
                break;
            case '*':
                {
                    BF(cur+1, val * nums[cur], expression);
                }
                break;
            case '/':
                {
                    if(val < 0)
                        BF(cur+1, -(-val / nums[cur]), expression);
                    else
                        BF(cur+1, val / nums[cur], expression);
                }
                break;
            default:
                break;
            }
            expression[i]++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    vector<int> expression(4);
    for(int i = 0; i < 4; i++)
    {
        cin >> expression[i];
    }
    BF(1, nums.front(), expression);
    cout << maxRes << '\n' << minRes;
}