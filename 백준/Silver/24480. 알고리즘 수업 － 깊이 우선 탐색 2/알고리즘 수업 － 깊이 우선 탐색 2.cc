#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
/*
24480_알고리즘 수업 - 깊이 우선 탐색 2
10004KB	112ms
*/
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int LM = 100001;
vector<int> graph[LM];
int visited[LM], seq = 1;

void dfs(int r) {
	visited[r] = seq++;

	for (int i = 0; i < graph[r].size(); i++) {
		if (!visited[graph[r][i]]) dfs(graph[r][i]);
	}
}

int main() {
#ifdef _WIN32
	freopen("input.txt", "r", stdin);
#endif // _WIN32
	int n, m, s, u, v;
	scanf("%d %d %d", &n, &m, &s);

	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		if (u != s) graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) sort(graph[i].rbegin(), graph[i].rend());
	dfs(s);

	for (int i = 1; i <= n; i++) printf("%d\n", visited[i]);
	return 0;
}