#include <bits/stdc++.h>
#define MAX 1025

using namespace std;

int n, m;

vector<vector<int>> board(MAX, vector<int>(MAX));
vector<vector<int>> prefixBoard(MAX, vector<int>(MAX));

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            prefixBoard[i][j] = board[i-1][j-1] + prefixBoard[i-1][j] + prefixBoard[i][j-1] - prefixBoard[i-1][j-1];
        }
    }
    
    for(int i = 0; i < m; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << prefixBoard[x2][y2] - prefixBoard[x1-1][y2] - prefixBoard[x2][y1-1] + prefixBoard[x1-1][y1-1] << '\n';
    }
    return 0;
}
