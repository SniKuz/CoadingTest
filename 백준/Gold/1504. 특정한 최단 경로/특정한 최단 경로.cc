#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 801

int grap[MAX][MAX];
int N, E, a, b, c, num1, num2, INF = 987654321;
bool answer = true;

void floid() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int a = 1; a <= N; a++) {
				if (grap[j][a] > grap[j][i] + grap[i][a])
					grap[j][a] = grap[j][i] + grap[i][a];
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		grap[a][b] = c;
		grap[b][a] = c;
	}
	cin >> num1 >> num2;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			if (grap[i][j] == 0) grap[i][j] = 987654321;
		}
	}
	floid();
	if (grap[1][num1] == INF || grap[num1][num2] == INF || grap[num2][N] == INF) answer = false;
	if(answer)
		cout << min((grap[1][num1] + grap[num1][num2] + grap[num2][N]), (grap[1][num2] + grap[num2][num1] + grap[num1][N])) << "\n";
	else cout << -1 << "\n";
}