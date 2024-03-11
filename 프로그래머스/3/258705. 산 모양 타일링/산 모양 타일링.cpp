#include <string>
#include <vector>

using namespace std;

int dp1[200001];
int dp2[200001];

int solution(int n, vector<int> tops) {
    if (tops[0] == 0){
        dp1[0] = 1;
        dp2[0] = 2;
    } else {
        dp1[0] = 1;
        dp2[0] = 3;
    }

    for (int i = 1; i < tops.size(); ++i){
        if (tops[i] == 1){
            dp1[i] = (dp1[i - 1] + dp2[i - 1]) % 10007;
            dp2[i] = (dp1[i - 1] * 2 + dp2[i - 1] * 3) % 10007;
        } else {
            dp1[i] = (dp1[i - 1] + dp2[i - 1]) % 10007;
            dp2[i] = (dp1[i - 1] + dp2[i - 1] * 2) % 10007;
        }
    }

    return (dp1[tops.size() - 1] + dp2[tops.size() - 1]) % 10007;
}