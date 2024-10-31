#include <bits/stdc++.h>
#define taste first
#define idx second
#define pii pair<int, int>

using namespace std;

int n, q;

vector<pii> kickMenus;
vector<pii> sweetMenus;

bool compare(const pii &a, const pii &b)
{
    return a.taste < b.taste;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> q;
    for(int i = 0; i < n; i++)
    {
        int kick, sweet;
        cin >> kick >> sweet;
        kickMenus.push_back({kick, i});
        sweetMenus.push_back({sweet, i});
    }
    sort(kickMenus.begin(), kickMenus.end());
    sort(sweetMenus.begin(), sweetMenus.end());
    
    for(int i = 0; i < q; i++)
    {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        vector<bool> selectMenu(n);
        
        int sameMenu = 0;
        unordered_set<int> kicks;
        auto kickStart = lower_bound(kickMenus.begin(), kickMenus.end(), pii(u,0), compare);
        auto kickEnd = upper_bound(kickMenus.begin(), kickMenus.end(), pii(v,0), compare);
        for(; kickStart != kickEnd; kickStart++)
        {
            selectMenu[(*kickStart).idx] = true;
        }
        
        auto sweetStart = lower_bound(sweetMenus.begin(), sweetMenus.end(), pii(x,0), compare);
        auto sweetEnd = upper_bound(sweetMenus.begin(), sweetMenus.end(), pii(y, 0), compare);
        for(; sweetStart != sweetEnd; sweetStart++)
        {
            if(selectMenu[(*sweetStart).idx])
            {
                sameMenu++;
            }
         }
        cout << sameMenu << '\n';
    }
    
    return 0;
}
/*
1. 좌표압축함
2. lower, upper bound로 각각 매운맛, 단맛 대상 찾음 (logn)
3. 같은 음식이면 체크함?
1차시도 13% 시간초과 > unorederd_set으로 변경
2차시도 13% 시간초과 > n길이 배열로 그냥 toggle
*/