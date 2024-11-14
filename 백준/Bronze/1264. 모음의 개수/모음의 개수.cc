#include <bits/stdc++.h>

using namespace std;


int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string input;
    while(getline(cin, input))
    {
        int res = 0;
        if(input.size() == 1 && input.front() == '#')
            break;
        for(const auto& c : input)
        {
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                res++;
            else if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
                res++;
        }
        cout << res << '\n';
    }
    return 0;
}
