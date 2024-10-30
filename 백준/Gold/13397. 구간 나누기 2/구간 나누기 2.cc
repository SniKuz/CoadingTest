#include <bits/stdc++.h>

using namespace std;

int n, m;
int board[5001];
int s = 0, e = 0;
int res = INT_MAX;

bool Check(int mid)
{
    int cnt = 1;
    int minVal = INT_MAX, maxVal = 0;
    int prev;
    for(int i = 0; i < n ; i++)
    {
        minVal = min(minVal, board[i]);
        maxVal = max(maxVal, board[i]);
        if(maxVal - minVal > mid)
        {
            cnt++;
            maxVal = board[i];
            minVal = board[i];
        }
    }
    return cnt <= m;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> board[i];
        e = max(e, board[i]);
    }
    while(s < e)
    {
        int mid = (s+e+1) / 2;
        //cout << mid << ' ';
        if(Check(mid))
        {
            res = min(res, mid);
            e = mid - 1;
        }
        else
        {
            s = mid;
        }
        //cout << '\n';
    }
    if(Check(s))
        res = min(res, s);
    cout << res;
    return 0;
}
/*
이 최솟값으로 몇개의 구간을 만들 수 있냐?로 변경 
*/