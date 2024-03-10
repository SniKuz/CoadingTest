#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> cache{100001, vector<int>{0,0}};

int solution(int n, vector<int> tops) {
    if(tops[0] > 0)
    {
        cache[0][0] = 3; cache[0][1] = 1;
    }
    else
    {
        cache[0][0] = 2; cache[0][1] = 1;
    }

    for(int i = 1; i < n; i++)
    {
        if(tops[i] > 0)
        {
            cache[i][0] = (cache[i-1][0] * 3 + cache[i-1][1] * 2) % 10007;
            cache[i][1] = (cache[i-1][0]  + cache[i-1][1]) % 10007;
        }
        else
        {
            cache[i][0] = (cache[i-1][0] * 2 + cache[i-1][1] ) % 10007;
            cache[i][1] = (cache[i-1][0] + cache[i-1][1]) % 10007;
        }
    }

    return (cache[n-1][0] + cache[n-1][1])%10007;;
}