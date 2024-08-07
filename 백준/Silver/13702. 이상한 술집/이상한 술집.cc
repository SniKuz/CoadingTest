#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll arr[10000];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)cin >> arr[i];
	sort(arr, arr + n);
	ll l = 0, r = (ll)10e9;
	ll ans = 0;
	while (l <= r)
	{
		ll cnt = 0;
		ll mid = (l + r) / 2;
		for (int i = 0; i < n; i++)
			cnt += (arr[i] / mid);
		if (cnt < m)
			r = mid - 1;
		else {
			ans = mid;
			l = mid + 1;
		}
	}
	cout << ans;
	return 0;
}