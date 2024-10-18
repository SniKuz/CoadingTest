#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<long , long>

using namespace std;

int n;
pii s, e;
int res = -1;
long long resLen = LLONG_MAX;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    cin >> s.X >> s.Y >> e.X >> e.Y;
    for(int i = 1; i <= n; i++)
    {
        int m;
        cin >> m;
        long long intermediate = 0;
        long long prevNx = s.X, prevNy = s.Y;
        for(int j = 0; j < m; j++)
        {
            long long nx, ny;
            cin >> nx >> ny;
            intermediate  += abs(nx-prevNx) + abs(ny-prevNy);
            prevNx = nx; prevNy = ny;
        }
        intermediate  += abs(e.X-prevNx) + abs(e.Y-prevNy);
        if(resLen > intermediate)
        {
            resLen = intermediate;
            res = i;
        }
    }
    cout << res;
    return 0;
}
