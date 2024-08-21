#include <string>
#include <vector>

using namespace std;

int LCD(int a, int b)
{
    if(a == 0)
        return b;
    if(b == 0)
        return a;
    return LCD(b, a%b);
}

int LCM(int a, int b)
{
    int ab = a * b;
    int lcd = LCD(a, b);
    if(lcd == 0)
        lcd = 1;
    return ab / lcd;
}

int solution(vector<int> arr) {
    int a = arr.back(); arr.pop_back();
    while(!arr.empty())
    {
        int b = arr.back(); arr.pop_back();
        a = LCM(a, b);
    }
    return a;
}