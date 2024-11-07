#include <bits/stdc++.h>

using namespace std;

vector<int> v(9);
vector<int> dwarf = {0,0,1,1,1,1,1,1,1};

int main() 
{
    for(int i = 0; i < 9; i++)
    {
        cin >> v[i];
    }
    do
    {
        int sum = 0;
        for(int i = 0; i < 9; i++)
        {
            if(dwarf[i] != 0)
            {
                sum += v[i];
            }
        }
        if(sum == 100)
        {
            vector<int> tall;
            for(int i = 0; i < 9; i++)
            {
                if(dwarf[i] != 0)
                    tall.push_back(v[i]);
            }
            sort(tall.begin(), tall.end());
            for(const auto& e: tall)
                cout << e << '\n';
            break;
        }
    } while(next_permutation(dwarf.begin(), dwarf.end()));
    return 0;
}
