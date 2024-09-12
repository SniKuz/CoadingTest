#include <bits/stdc++.h>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    for(auto &c : myString)
    {
        c = tolower(c);
    }
    for(auto& c : pat)
    {
        c = tolower(c);
    }
    auto pos = strstr(myString.c_str(), pat.c_str());
    if(pos == nullptr)
        return 0;
    return 1;
}