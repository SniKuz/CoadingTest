#include <bits/stdc++.h>

#define like first
#define life second

using namespace std;

int N, M;
map<int, pair<int, int>> m; // like, cnt

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < M; ++i)
    {
        int vote;
        cin >> vote;
        if(m.find(vote) == m.end())
        {
            if(m.size() >= N)
            {
                int k;
                pair<int, int> val = {2e9, 0};
                for(auto& [key, value] : m)
                {
                    if(val.like > value.like)
                    {
                        k = key;
                        val = value;
                    }
                    else if(val.like == value.like)
                    {
                        if(val.life < value.life)
                        {
                            k = key;
                            val = value;
                        }
                    }
                }
                m.erase(k);
            }
            m[vote] = {1, 0};
        }
        else
        {
            m[vote].like += 1;
        }
        for(auto& [key, value] : m)
        {
            value.life += 1;
        }
    }

    vector<int> pictures;
    for(const auto& [key, value] : m)
    {
        pictures.push_back(key);
    }
    sort(pictures.begin(), pictures.end());
    for(const auto& cur : pictures)
    {
        cout << cur << ' ';
    }
    return 0;
}