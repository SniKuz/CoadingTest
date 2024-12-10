#include <iostream>
using namespace std;

int arr[100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	int X, Y; cin >> X >> Y;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i] >= Y) cnt++;
	}

	cout << N * X / 100 << ' ' << cnt;
}