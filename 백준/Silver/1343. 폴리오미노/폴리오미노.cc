#include <bits/stdc++.h>

using namespace std;

string input;
string res = "";

int main() 
{
    cin >> input;
    int inputSize = input.size();
    int idx = 0;
    while(idx < inputSize)
    {
        if(input[idx] == '.')
        {
            res.push_back('.');
            idx++;
        }
        else
        {
            int type = 0; 
            for(int i = 0; i < 2; i++)
            {
                if(input[idx+i] == 'X')
                    type++;
                else
                    type = 0;
            }
            bool B = (type == 2);
            for(int i = 2; i < 4; i++)
            {
                if(input[idx+i] == 'X')
                    type++;
                else
                    type = 0;
            }
            bool A = (type == 4);
            if(A)
            {
                for(int i = 0; i < 4; i++)
                {
                    res.push_back('A');
                    idx++;
                }
            }
            else if(B)
            {
                for(int i = 0; i < 2; i++)
                {
                    res.push_back('B');
                    idx++;
                }
            }
            else
            {
                cout << -1;
                return 0;
            }
        }
    }
    cout << res;
    return 0;
}