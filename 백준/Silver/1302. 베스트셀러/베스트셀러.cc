#include <bits/stdc++.h>
#define Title first
#define Count second

using namespace std;

int n;
map<string, int> books;
pair<string, int> bestSeller= {"", 0};

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string book;
        cin >> book;
        books[book]++;
    }
    
    for(const auto& b : books)
    {
        if(b.Count > bestSeller.Count)
        {
            bestSeller.Count = b.Count;
            bestSeller.Title = b.Title;
        }
    }
    cout << bestSeller.Title;
    return 0;
}
