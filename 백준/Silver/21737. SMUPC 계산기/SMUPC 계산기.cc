#include <bits/stdc++.h>
#define TARGET "SMUPC"

using namespace std;

int n;
string input;
vector<string> expression;
string buf;
bool output = false;
int val;

void PushSign(char sign)
{
    buf.push_back(sign);
    expression.push_back(buf);
    buf.pop_back();
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> input;
    
    auto cur = input.find_first_of(TARGET);
    expression.push_back(input.substr(0, cur));
    PushSign(input[cur]);
    auto prev = cur + 1;
    
    while((cur = input.find_first_of(TARGET, prev)) != string::npos)
    {
        expression.push_back(input.substr(prev, (cur-prev)));
        PushSign(input[cur]);
        prev = cur + 1;
    }

    val = stoi(expression.front());
    int expressSize = expression.size();
    for(int i = 1; i < expressSize; i+=2)
    {
        switch (expression[i].front()) {
            case 'S':
                {
                    if(i+1 >= expressSize)
                        break;
                    val -= stoi(expression[i+1]);
                }
                break;
            case 'M':
                {
                    if(i+1 >= expressSize)
                        break;
                    val *= stoi(expression[i+1]);
                }
                break;
            case 'U':
                {
                    if(i+1 >= expressSize)
                        break;
                    val /= stoi(expression[i+1]);
                }
                break;
            case 'P':
                {
                    if(i+1 >= expressSize)
                        break;
                    val += stoi(expression[i+1]);
                }
                break;
            case 'C':
                output = true;
                cout << val << ' ';
                break;
        }
    }

    if(output == false)
    {
        cout << "NO OUTPUT";
    }
    return 0;
}
