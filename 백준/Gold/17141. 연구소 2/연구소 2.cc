#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0 ,-1};

int n, m;
vector<vector<int>> board(50, vector<int>(50));
vector<pii> virus;
int virusCnt = 0;
vector<pii> emptyCells;
int emptyCellCnt = 0;
int res = INT_MAX;

void Reset()
{
    for(const auto& e : emptyCells)
    {
        board[e.X][e.Y] = 0;
    }
    for(const auto& e : virus)
    {
        board[e.X][e.Y] = 2;
    }
}

void solution(const vector<int>& target)
{
    int destoryCnt = 0;
    int turn = -1;
    vector<pii> v1, v2;
    for(int i = 0; i < virusCnt; i++)
    {
        if(target[i] == 1)
        {
            v1.push_back(virus[i]);
            board[virus[i].X][virus[i].Y] = 1;
        }
    }
    
    while((v1.empty() == false || v2.empty() == false) && res > turn)
    {
        if(v1.empty() == false)
        {
            while(v1.empty() == false)
            {
                auto cur = v1.back(); v1.pop_back();
                destoryCnt++;
                
                for(int i = 0; i < 4; i++)
                {
                    int nx = cur.X + dx[i];
                    int ny = cur.Y + dy[i];

                    if(nx < 0 || ny < 0 || nx >= n || ny >= n)
                        continue;
                    if(board[nx][ny] == 1)
                        continue;

                    board[nx][ny] = 1;
                    v2.push_back({nx, ny});
                }
            }
        }
        else
        {
            while(v2.empty() == false)
            {
                auto cur = v2.back(); v2.pop_back();
                destoryCnt++;

                for(int i = 0; i < 4; i++)
                {
                    int nx = cur.X + dx[i];
                    int ny = cur.Y + dy[i];

                    if(nx < 0 || ny < 0 || nx >= n || ny >= n)
                        continue;
                    if(board[nx][ny] == 1)
                        continue;

                    board[nx][ny] = 1;
                    v1.push_back({nx, ny});
                }
            }
        }
        turn++;
    }
    if(destoryCnt == emptyCellCnt + virusCnt)
        res = min(res, turn);
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 2)
            {
                virus.push_back({i, j});
            }
            else if(board[i][j] == 0)
            {
                emptyCells.push_back({i, j});
            }
        }
    }
    
    virusCnt = virus.size();
    emptyCellCnt = emptyCells.size();
    vector<int> target(virusCnt);
    for(auto itr = target.rbegin(); itr != target.rbegin() + m; itr++)
        *itr = 1;
    do
    {
        solution(target);
        Reset();
    } while(next_permutation(target.begin(), target.end()));

    if(res == INT_MAX)
        cout << -1;
    else
        cout << res;
    return 0;
}
