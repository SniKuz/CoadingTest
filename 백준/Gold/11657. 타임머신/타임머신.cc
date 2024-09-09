#include<cstdio>
#include<climits>//INT_MAX
long long visited[500 + 1]; //cost 저장용 150억까지 커버할 수 있게끔 (간선 서로 같은 음수 가중치일때..?)
//시작점과 도착점을 연결하는 간선이 하나가 아니고, ~~한 경우가 있을수있으므로.. 이거 캐치가 포인트
int edgeList[3][6000 + 1]; //간선리스트
int N, M, A, B, C;

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++) { //간선리스트에 간선 정보저장
		scanf("%d %d %d", &A, &B, &C);
		edgeList[0][i] = A;
		edgeList[1][i] = B;
		edgeList[2][i] = C;
	}
	visited[1] = 0;
	for (int i = 2; i <= N; i++) {
		visited[i] = INT_MAX;
	}

	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= M; j++) {
			if (visited[edgeList[0][j]] != INT_MAX) {
				if (visited[edgeList[1][j]] > visited[edgeList[0][j]]+ edgeList[2][j]) {
					visited[edgeList[1][j]] = visited[edgeList[0][j]] + edgeList[2][j];
				}
			}
		}
	}
	
	for (int j = 1; j <= M; j++) {
		if (visited[edgeList[0][j]] != INT_MAX) {
			if (visited[edgeList[1][j]] > visited[edgeList[0][j]] + edgeList[2][j]) {
				visited[edgeList[1][j]] = visited[edgeList[0][j]] + edgeList[2][j];
				printf("-1\n");
				return 0;
			}
		}
	}
	for (int i = 2; i <= N; i++) {
		if (visited[i] == INT_MAX) {
			printf("-1\n");
		}
		else {
			printf("%lld\n", visited[i]);
		}
	}
}