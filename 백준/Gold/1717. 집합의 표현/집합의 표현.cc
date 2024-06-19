#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> members(1000001);

int FindUnion(int a)
{
    if(members[a] == a) return a;
    return members[a] = FindUnion(members[a]);
}

void MakeUnion(int a, int b)
{
    a = FindUnion(a);
    b = FindUnion(b);
    if(a > b) members[a] = b;
    else members[b] = a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 1; i <= N; ++i)
    {
        members[i] = i;
    }

    for(int i = 0; i < M; ++i)
    {
        int cmd, a, b;
        cin >> cmd >> a >> b;
        if(cmd == 0)
        {
            MakeUnion(a, b);
        }
        else // check same Union
        {
            if(FindUnion(a) == FindUnion(b))
                cout << "yes" << '\n';
            else
                cout << "no" << '\n';
        }
    }
    return 0;
}