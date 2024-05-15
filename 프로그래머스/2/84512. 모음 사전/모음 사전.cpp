#include <bits/stdc++.h>

using namespace std;

map<string, int> dict;
int cnt = 0;

void MakeDict(vector<string> alphabets, string currentStr, int currentNum)
{
    if(currentNum == 5) return;
    
    for(auto alphabet : alphabets)
    {
        dict[currentStr + alphabet] = ++cnt;
        MakeDict(alphabets, currentStr + alphabet, currentNum + 1);
    }
}

int solution(string word) {
    vector<string> alphabets = {"A", "E", "I", "O", "U"};
    MakeDict(alphabets, "", 0);
    return dict[word];
}