#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> hash;
    for(auto clothe : clothes)
    {
        if(hash.find(clothe[1]) != hash.end())
        {
            hash[clothe[1]]+=1;
        }
        else
        {
            hash.insert({clothe[1], 1});
        }
    }
    vector<int> hashNum;
    for(auto h : hash)
    {
        answer *= (h.second+1);
    }

    return answer-1;
}
/*
clothe = [의상 이름, 의상 종류]
의상 수는 30개 이하
씨발 ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ
모든 상태에는 "안입음"이라는 상태를 추가하고, 모든 종류를 안입는건 불가능하니 -1하는거면 됨. 조합은 무슨 그냥 빡대가리짓했다
*/