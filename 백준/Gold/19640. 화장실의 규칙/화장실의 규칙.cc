#include <cstdio>
#include <deque>
#include <queue>
using namespace std;
const int MAX = 100005;

struct info {
	int idx, d, h, deca;
};

struct compare {
	bool operator()(info a, info b) {
		if (a.d > b.d) return false;
		else if (a.d == b.d) {
			if (a.h > b.h) return false;
			else if (a.h == b.h) {
				if (a.idx < b.idx) return false;
			}
		}
		return true;
	}
};

int n, m, k;
deque <info> dq[MAX];
priority_queue <info, vector<info>, compare> first_person;

int main() {
	scanf("%d %d %d", &n, &m, &k);

	int idx = 0;
	for (int i = 0; i < n; i++) {
		int d, h;
		scanf("%d %d", &d, &h);
		if (i == k) dq[idx].push_back({ idx, d, h, 1 });
		else dq[idx].push_back({ idx, d, h, 0 });
		idx++;
		if (idx == m) idx = 0;
	}

	for (int i = 0; i < m; i++) {
		if (dq[i].empty()) continue;
		first_person.push(dq[i][0]);
	}
	
	int cnt = 0;
	while (1) {
		int idx = first_person.top().idx;
		first_person.pop();

		if (dq[idx][0].deca == 1) break;
		dq[idx].pop_front();

		if (!dq[idx].empty()) first_person.push(dq[idx][0]);
		cnt++;
	}

	printf("%d\n", cnt);
	return 0;
}