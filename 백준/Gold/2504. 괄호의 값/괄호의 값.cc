#include <bits/stdc++.h>

using namespace std;

struct Node
{
    char bracketType;
    int num;
};

string input;
vector<Node> v;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> input;
    for(const auto& bracket: input)
    {
        if(bracket == '(' || bracket == '[')
        {
            Node node = {bracket, 0};
            v.push_back(node);
        }
        else
        {
            if(bracket == ')')
            {
                int cnt = 0;
                while(!v.empty() && v.back().bracketType != '(')
                {
                    if(v.back().bracketType =='[')
                    {
                        cout << 0;
                        return 0;
                    }
                    cnt += v.back().num; v.pop_back();
                }
                if(v.empty())
                {
                    cout << 0;
                    return 0;
                }
                v.pop_back();
                if(cnt != 0)
                {
                    Node node = {' ', cnt*2};
                    v.push_back(node);
                }
                else
                {
                    Node node = {' ', 2};
                    v.push_back(node);
                }
            }
            else
            {
                int cnt = 0;
                while(!v.empty() && v.back().bracketType != '[')
                {
                    if(v.back().bracketType =='(')
                    {
                        cout << 0;
                        return 0;
                    }
                    cnt += v.back().num; v.pop_back();
                }
                if(v.empty())
                {
                    cout << 0;
                    return 0;
                }
                v.pop_back();
                if(cnt != 0)
                {
                    Node node = {' ', cnt*3};
                    v.push_back(node);
                }
                else
                {
                    Node node = {' ', 3};
                    v.push_back(node);
                }
            }
        }
    }
    int res = 0;
    for(const auto& e : v)
    {
        if(e.bracketType != ' ')
        {
            cout << 0;
            return 0;
        }
        res += e.num;
    }
    cout << res;
    return 0;
}