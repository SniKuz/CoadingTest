#include <bits/stdc++.h>

using namespace std;

string m;
vector<bool> s(21, false);

vector<string> Split(const string& str, char target = ' ')
{
    istringstream iss(str);
    string buf;
    vector<string> ret;

    while(getline(iss, buf, target))
    {
        ret.push_back(buf);
    }
    return ret;
}


int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    getline(cin, m);
    int intM = stoi(m);
    string str;
    for(int i = 0; i < intM; i++)
    {
        getline(cin, str);
        vector<string> cmds = Split(str);

        if(cmds.front().compare("add") == 0)
        {
            s[stoi(cmds.back())] = true;
        }
        else if(cmds.front().compare("remove") == 0)
        {
            s[stoi(cmds.back())] = false;
        }
        else if(cmds.front().compare("check") == 0)
        {
            if(s[stoi(cmds.back())])
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if(cmds.front().compare("toggle") == 0)
        {
            s[stoi(cmds.back())] = !s[stoi(cmds.back())];
        }
        else if(cmds.front().compare("all") == 0)
        {
            for(int j = 1; j <= 20; j++)
            {
                s[j] = true;
            }
        }
        else // empty
        {
            for(int j = 1; j <= 20; j++)
            {
                s[j] = false;
            }
        }
    }
    return 0;
}
