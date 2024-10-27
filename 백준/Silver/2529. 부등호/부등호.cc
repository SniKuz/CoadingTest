#include <bits/stdc++.h>

using namespace std;

int n;
vector<char> signs;
vector<bool> checked(10);
long long minRes = LLONG_MAX, maxRes = 0;
string minRet = "", maxRet = "";

void Recursive(vector<int> targets)
{
    if(targets.size() > n)
    {
        bool possible = true;
        for(int i = 0; i < n; i++)
        {
            if(possible == false)
                return;
            switch(signs[i])
            {
                case '<':
                    {
                        if(targets[i] > targets[i+1])
                            possible = false;
                    }
                    break;
                case '>':
                    {
                        if(targets[i] < targets[i+1])
                            possible = false;
                    }
                    break;
            }
        }
        if(possible)
        {
            string temp;
            for(const auto& e: targets)
            {
                temp += to_string(e);
            }
            auto res = stoll(temp);
            if(maxRes < res)
            {
                maxRes = res;
                maxRet = temp;
            }
            if(minRes > res)
            {
                minRes = res;
                minRet = temp;
            }
        }
        return;
    }
    for(int i = 0; i < 10; i++)
    {
        if(checked[i] == false)
        {
            checked[i] = true;
            targets.push_back(i);
            Recursive(targets);
            targets.pop_back();
            checked[i] = false;
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    signs.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> signs[i];
    }
    Recursive({});
    cout << maxRet << '\n' << minRet;
    return 0;
}
