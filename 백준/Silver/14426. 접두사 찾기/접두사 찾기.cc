#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
int n, m;
vector<string> v;
void input() {
    cin >> n >> m;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        v.push_back(s);
    }
}
void solve() {
    int res = 0;
    sort(v.begin(), v.end());
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (s < v[mid]) {
                r = mid - 1;
            }
            else if (s > v[mid]) {
                l = mid + 1;
            }
            if (v[mid].substr(0,s.size()) == s) {
                res++;
                break;
            }
 
        }
    }
    cout << res << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
}