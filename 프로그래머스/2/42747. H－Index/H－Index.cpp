#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    int answer = 0;
    int n = citations.size();
    
    for (int i=0; i<n; i++) {
        int hIndex = n-i;
        
        if (citations[i] >= hIndex) {
            answer = hIndex;
            break;
        }
    }
    
    return answer;
}