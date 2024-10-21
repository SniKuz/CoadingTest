#include <bits/stdc++.h>
#define l first
#define r second
#define pii pair<int, int>

using namespace std;

int n;
vector<pii> v;
vector<int> maps;
vector<int> leaflet(20010, 0);
int res = 0;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int left, right;
        cin >> left >> right;
        v.push_back({left, right});
        maps.push_back(left);
        maps.push_back(right);
    }
    sort(maps.begin(), maps.end());
    maps.erase(unique(maps.begin(), maps.end()), maps.end());
    for(auto &e : v)
    {
        e.l = distance(maps.begin(), lower_bound(maps.begin(), maps.end(), e.l));
        e.r = distance(maps.begin(), lower_bound(maps.begin(), maps.end(), e.r));
    } 
    
    while(!v.empty())
    {
        auto cur = v.back(); v.pop_back();
        bool isHide = true;
        for(int i = cur.l; i <= cur.r; i++)
        {
            if(leaflet[i] == 0)
                isHide = false;
            leaflet[i]++;
        }
        if(isHide == false)
            res++;
    }
    
    cout << res;
    return 0;
}
/*
93% 실패. 이유가 뭐지
*/