#include <string>
#include <vector>

using namespace std;

int CheckBitOne(int n)
{
    int countOne = 0;
    while(n > 0)
    {
        if(n%2 != 0)
            countOne++;
        n /= 2;    
    }
    return countOne;
}

int solution(int n) {
    int target = CheckBitOne(n);
    while(1)
    {
        ++n;
        int tmp = CheckBitOne(n);
        if(target == tmp)
            break;
    }
    return n;
}