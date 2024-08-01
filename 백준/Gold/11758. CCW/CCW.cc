#include <bits/stdc++.h>

#define X first
#define Y second
#define p pair<int,int>

using namespace std;

p p1, p2, p3;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> p1.X >> p1.Y;
    cin >> p2.X >> p2.Y;
    cin >> p3.X >> p3.Y;
    
    p l1 = {p2.X - p1.X, p2.Y - p1.Y};
    p l2 = {p3.X - p2.X, p3.Y - p2.Y};

    float val = l1.X * l2.Y - l2.X * l1.Y;
    if(val == 0)
        cout << 0;
    else if(val > 0)
        cout << 1;
    else
        cout << -1;
}