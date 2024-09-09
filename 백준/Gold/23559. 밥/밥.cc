#include <bits/stdc++.h>

using namespace std;

int n, x;
vector<pair<int, int>> meals;
int res = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;
    for(int i = 0; i < n; i++)
    {
        int five, one;
        cin >> five >> one;
        meals.push_back({five, one});
        res += one;
        x -= 1000;
    }
    sort(meals.begin(), meals.end(), [](const pair<int,int> &a, const pair<int, int> &b){
        return abs((a.first - a.second)) > abs((b.first - b.second));
    });

    for(const auto& meal : meals)
    {
        if(x >= 4000 && meal.first - meal.second >= 0)
        {
            x -= 4000;
            res += meal.first - meal.second;
        }
    }
    cout << res;
}