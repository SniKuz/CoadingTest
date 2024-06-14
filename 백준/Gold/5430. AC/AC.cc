#include <bits/stdc++.h>

using namespace std;

deque<int> split(const string& str)
{
    string substr = str.substr(1, str.size()-2);
    istringstream iss(substr);
    string buffer;
    deque<int> ret;

    while(getline(iss, buffer, ','))
    {
        ret.push_back(stoi(buffer));
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int i = 0; i < T; ++i)
    {
        string cmds;
        cin >> cmds;
        int len;
        cin >> len;
        string testCase;
        cin >> testCase;
        auto ret = split(testCase);
        bool front = true;
        bool err = false;
        for(char cmd : cmds)
        {
            if(cmd == 'R')
            {
                front = !front; 
            }
            else // cmd == 'D'
            {
                if(ret.empty())
                {
                    err = true;
                    break;
                }
                else if(front)
                {
                    ret.pop_front();
                }
                else
                {
                    ret.pop_back();
                }
            }
        }

        if(err)
        {
            cout << "error\n";
        }
        else
        {
            string tmp = "[";
            if(ret.empty())
            {
                tmp += "]";
            }
            else if(front)
            {
                for(auto s = ret.begin(); s != ret.end(); s++)
                {
                    tmp += to_string(*s);
                    tmp += ',';
                }
                tmp[tmp.size()-1] = ']';
            }
            else
            {
                for(auto s = ret.rbegin(); s!=ret.rend(); s++)
                {
                    tmp += to_string(*s);
                    tmp += ',';
                }
                tmp[tmp.size()-1] = ']';
            }
            cout << tmp << '\n';
        }
    }

    return 0;
}