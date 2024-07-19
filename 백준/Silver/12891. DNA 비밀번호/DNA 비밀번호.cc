#include <bits/stdc++.h>

using namespace std;

struct Password
{
    int a=0, c=0, g=0, t=0;
    int aN=0, cN=0, gN=0, tN=0;
    bool IsPassword()
    {
        return a >= aN && c >= cN && g >= gN && t >= tN;
    }
};

Password pw;
int s, p;
int res = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> p;
    string str;
    cin >> str;
    cin >> pw.aN >> pw.cN >> pw.gN >> pw.tN;
    for(int i = 0; i < p; i++)
    {
        if(str[i] == 'A')
            pw.a += 1;
        else if(str[i] == 'C')
            pw.c += 1;
        else if(str[i] == 'G')
            pw.g += 1;
        else
            pw.t += 1;
    }
    if(pw.IsPassword()) res += 1;
    for(int i = p; i < s; i++)
    {
        if(str[i-p] == 'A')
            pw.a -= 1;
        else if(str[i-p] == 'C')
            pw.c -= 1;
        else if(str[i-p] == 'G')
            pw.g -= 1;
        else
            pw.t -= 1;

        if(str[i] == 'A')
            pw.a += 1;
        else if(str[i] == 'C')
            pw.c += 1;
        else if(str[i] == 'G')
            pw.g += 1;
        else
            pw.t += 1;

        if(pw.IsPassword()) res += 1;
        
    }
    cout << res;
}