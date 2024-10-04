#include <bits/stdc++.h>

using namespace std;

int D, K;
bool over = false;

bool IsPossible(int x, int y)
{
    for(int i = 3; i <= D; i++)
    {
        if(i%2 != 0)
        {
            x += y;
        }
        else
        {
            y += x;
        }
    }
    if(D%2 == 0)
    {
        if(y == K)
            return true;
        return false;
    }
    else
    {
        if(x == K)
            return true;
        return false;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> D >> K;
    for(int i = 1; i <= K; i++)
    {
        for(int j = i; j <= K; j++)
        {
            if(IsPossible(i, j))
            {
                cout << i << '\n' << j;
                over = true;
                break;
            }
        }
        if(over) break;
    }
}