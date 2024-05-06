#include <bits/stdc++.h>

using namespace std;

vector<string> Split(string str)
{
    istringstream iss(str);
    string buffer;
    vector<string> ret;
    
    while(getline(iss, buffer, ' '))
    {
        ret.push_back(buffer);
    }
    return ret;
}

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    map<string, int> nameIndex;
    map<string, int> presentIndex;
    int cnt = 0;
    for(const auto& tmp : friends)
    {
        nameIndex[tmp] = cnt++;
        presentIndex[tmp] = 0;
    }
    vector<vector<int>> swapGifts(51, vector<int>(51));
    for(const auto& gift : gifts)
    {
        auto A2B = Split(gift);
        swapGifts[nameIndex[A2B[0]]][nameIndex[A2B[1]]]++;
        presentIndex[A2B[0]]++; presentIndex[A2B[1]]--;
    }
    
    vector<int> nextGifts(51, 0);
    for(const auto& give : friends)
    {
        for(const auto& get : friends)
        {
            if(give == get) continue;
            if(swapGifts[nameIndex[give]][nameIndex[get]] > swapGifts[nameIndex[get]][nameIndex[give]])
                nextGifts[nameIndex[give]]++;
            else if(swapGifts[nameIndex[give]][nameIndex[get]] == swapGifts[nameIndex[get]][nameIndex[give]])
            {
                if(presentIndex[give] > presentIndex[get])
                    nextGifts[nameIndex[give]]++;
            }
        }
    }
    return *max_element(nextGifts.begin(), nextGifts.end());
}

//선물지수 : 친구들에게 준 선물의 수 - 받은 설물의 수