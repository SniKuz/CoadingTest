#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n;

vector<vector<char>> board(6, vector<char>(6, 'X'));
vector<vector<bool>> visited(6, vector<bool>(6, false));
vector<pair<int, int>> teacher;
bool res = false;

void solution(int cnt)
{
    if(res) return;
    if(cnt <= 0)
    {
        for(const auto& e : teacher)
        {
            for(int i = 0; i < 4; i++)
            {
                auto T = e;
                while(T.X >= 0 && T.Y >= 0 && T.X < n && T.Y < n)
                {
                    if(board[T.X][T.Y] == 'S')
                        return;
                    if(board[T.X][T.Y] == 'O')
                        break;
                    T.X += dx[i];
                    T.Y += dy[i];
                }
            }
        }
        cout << "YES";
        res = true;
        return;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(!visited[i][j])
            {
                visited[i][j] = true;
                board[i][j] = 'O';
                solution(cnt-1);
                visited[i][j] = false;
                board[i][j] = 'X';
            }
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            if(board[i][j] != 'X')
                visited[i][j] = true;
            if(board[i][j] == 'T')
                teacher.push_back({i, j});
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(!visited[i][j])
            {
                visited[i][j] = true;
                board[i][j] = 'O';
                solution(2);
                if(res)
                {
                    return 0;
                }
                visited[i][j] = false;
                board[i][j] = 'X';
            }
        }
    }
    cout << "NO";
    return 0;
}