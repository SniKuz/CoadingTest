#include <bits/stdc++.h>

using namespace std;

int CreateStation(int betweenArea, int w)
{
    if(betweenArea <= 0) return 0;
    int ret = betweenArea / w ;
    if((betweenArea % w) != 0) ++ret;
    return ret;
}

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    for(int i = 1; i < stations.size(); ++i)
    {
        int prevStation = stations[i-1];
        int curStation = stations[i];
        int betweenArea = (curStation - w -(prevStation + w) - 1);
        answer += CreateStation(betweenArea, w*2+1);
    }
    answer += CreateStation((stations.front() - w - 1), w*2+1);
    answer += CreateStation(n - (stations.back() + w), w*2+1);
    return answer;
}