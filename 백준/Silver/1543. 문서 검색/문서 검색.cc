#include <bits/stdc++.h>

using namespace std;

string doc, word;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    getline(cin, doc);
    getline(cin, word);
    int cnt = 0;
    int wordLen = word.size();
    auto cur = doc.find(word);
    while(cur != string::npos)
    {
        cnt++;
        cur = doc.find(word, cur + wordLen);
    }
    cout << cnt;
    return 0;
}
