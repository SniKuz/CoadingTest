#include <bits/stdc++.h>
#define ll long long

using namespace std;

int sizes;

bool IsPossible(vector<int> &diffs, vector<int> &times, int level, ll limit)
{
    ll t = 0;
    for(int i = 0; i < sizes; i++)
    {
        if(diffs[i] <= level) t += times[i];
        else if(i == 0)
        {
            t += times[i] * (diffs[i] - level + 1);
        }
        else
        {
            t += (times[i-1] + times[i]) * (diffs[i] - level);
            t += times[i];
        }
        if(t > limit) return false;
    }
    return true;
}


int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = INT_MAX;
    sizes = times.size();
    int s = 0, e = 0;
    for(int i = 0; i < sizes; i++)
    {
        if(diffs[i] > e)
            e = diffs[i];
    }
    
    while(s < e)
    {
        int m = (s+e+1) / 2;
        if(IsPossible(diffs, times, m, limit))
        {
            answer = min(answer, m);
            e = m-1;
        }
        else
        {
            s = m;
        }
    }
    
    return answer;
}