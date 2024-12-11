#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string str;
    while(getline(cin, str))
    {
        int upper = 0, lower = 0, num = 0, space = 0;
        for(const auto& c : str)
        {
            if(c == ' ')
                space++;
            else if(c >= '0' && c <= '9')
                num++;
            else if(c >= 'A' && c <= 'Z')
                upper++;
            else
                lower++;
        }
        cout << lower << ' ' << upper << ' ' << num << ' ' << space << '\n';
    }
    return 0;
}
