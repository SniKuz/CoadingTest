#include <bits/stdc++.h>
#define key first
#define value second

using namespace std;

int n;
map<string ,int> extension;

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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        auto file = split(str, '.');
        extension[file.back()]++;
    }
    for(const auto& ex : extension)
    {
        cout << ex.key << ' ' << ex.value << '\n';
    }
    return 0;
}
