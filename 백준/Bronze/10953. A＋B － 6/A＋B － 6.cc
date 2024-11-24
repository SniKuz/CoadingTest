#include <bits/stdc++.h>

using namespace std;

int tc;

vector<string> split(string str, char target = ' ')
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
    cin >> tc;
    for(int t = 0; t < tc; t++)
    {
        string str;
        cin >> str;
        auto num = split(str, ',');
        cout << stoi(num.front()) + stoi(num.back()) << '\n';
    }
    return 0;
}
