#include <bits/stdc++.h>

using namespace std;

int n;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string word;
        cin >> word;
        sort(word.begin(), word.end());
        do
        {
            cout << word << '\n';
        }while(next_permutation(word.begin(), word.end()));
    }
}
