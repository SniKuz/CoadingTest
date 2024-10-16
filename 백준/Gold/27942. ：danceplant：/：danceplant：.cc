#include <bits/stdc++.h>
#define top first
#define left second
#define bottom first
#define right second
#define pii pair<int, int>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1}; //UDLR

int n; // n%2==0
int board[3005][3005];

pair<pii, pii> eggplant; //top, left / bottom, right
int resCnt = 0;
string resCmd = "";

bool Select()
{
    int nextCnt = 0;
    char nextCmd = 'a';
    for(int i = 0; i < 4; i++)
    {
        switch (i) 
        {
            case 0: //U
                {
                    int tempCnt = 0;
                    int nx = eggplant.first.top - 1;
                    if(nx < 0) break;
                    for(int l = eggplant.first.left; l <= eggplant.second.right; l++)
                    {
                        tempCnt += board[nx][l];
                    }
                    if(nextCnt < tempCnt)
                    {
                        nextCnt = tempCnt;
                        nextCmd = 'U';
                    }
                }
                break;
            case 1: //D
                {
                    int tempCnt = 0;
                    int nx = eggplant.second.bottom + 1;
                    if(nx > n) break;
                    for(int l = eggplant.first.left; l <= eggplant.second.right; l++)
                    {
                        tempCnt += board[nx][l];
                    }
                    if(nextCnt < tempCnt)
                    {
                        nextCnt = tempCnt;
                        nextCmd = 'D';
                    }
                }
                break;
            case 2: //L
                {
                    int tempCnt = 0;
                    int ny = eggplant.first.left - 1;
                    if(ny < 0) break;
                    for(int b = eggplant.first.top; b <= eggplant.second.bottom; b++)
                    {
                        tempCnt += board[b][ny];
                    }
                    if(nextCnt < tempCnt)
                    {
                        nextCnt = tempCnt;
                        nextCmd = 'L';
                    }
                }
                break;
            case 3: //R
                {
                    int tempCnt = 0;
                    int ny = eggplant.second.right + 1;
                    if(ny > n) break;
                    for(int b = eggplant.first.top; b <= eggplant.second.bottom; b++)
                    {
                        tempCnt += board[b][ny];
                    }
                    if(nextCnt < tempCnt)
                    {
                        nextCnt = tempCnt;
                        nextCmd = 'R';
                    }
                }
                break;
        }
    }
    
    if(nextCnt <= 0)
        return false;
    
    resCmd += nextCmd;
    resCnt += nextCnt;
    if(nextCmd == 'U')
        eggplant.first.top--;
    else if(nextCmd == 'D')
        eggplant.second.bottom++;
    else if(nextCmd == 'L')
        eggplant.first.left--;
    else // R
        eggplant.second.right++;
    return true;
    
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> board[i][j];
        }
    }
    eggplant.first = {n/2, n/2}; eggplant.second = {(n/2)+1, (n/2)+1};

    while(Select())
        ;
    cout << resCnt << '\n' << resCmd;
}