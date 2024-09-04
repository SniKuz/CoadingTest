#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less_equal<>, rb_tree_tag, tree_order_statistics_node_update>

int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    ordered_set os;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        os.insert(num);
        cout << *os.find_by_order((os.size()-1)/2) << '\n';
    }
}