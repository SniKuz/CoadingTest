#include <bits/stdc++.h>
#define Count first
#define Num second

using namespace std;

string start, finish;

int MakeItInt(string data)
{
    int ret = 0;
    for(int i = 0; i < data.length(); i++)
    {
        if (data[i] == '1')
        {
            ret += 1 << (data.length() - i - 1);
        }
    }
    return ret;
}

string MakeItString(int data)
{
    string ret = "";
    while (data != 0)
    {
        if (data % 2 == 0)
        {
            ret.push_back('0');
        }
        else
        {
            ret.push_back('1');
        }
        data /= 2;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> start >> finish;
    int goal = MakeItInt(finish);

    queue<pair<int, string>> q;
    q.push({0, start});
    set<int> visited;
    visited.insert(MakeItInt(start));
    while (q.empty() == false && MakeItInt(q.front().Num) != goal)
    {
        auto current = q.front(); q.pop();
        
        for(int i = 1; i < current.Num.length(); i++)
        {
            current.Num[i] = current.Num[i] == '0' ? '1' : '0';
            auto complement = MakeItInt(current.Num);
            if (visited.find(complement) == visited.end())
            {
                q.push({current.Count + 1, current.Num});
                visited.insert(complement);
            }
            current.Num[i] = current.Num[i] == '0' ? '1' : '0';
        }
        int currentNum = MakeItInt(current.Num);
        if (visited.find(currentNum + 1) == visited.end())
        {
            q.push({current.Count+1, MakeItString(currentNum + 1)});
            visited.insert(currentNum + 1);
        }
        if (currentNum != 0 && visited.find(currentNum - 1) == visited.end())
        {
            q.push({current.Count + 1, MakeItString(currentNum - 1)});
            visited.insert(currentNum - 1);
        }
        
    }
    cout << q.front().Count;
    return 0;
}