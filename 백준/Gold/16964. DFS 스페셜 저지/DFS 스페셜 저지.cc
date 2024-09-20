#include <bits/stdc++.h>
using namespace std;

vector<int> ad[100001]; 
int order[100001], given_path[100001], DFS_path[100001], L=1;
bool ch[100001];

bool comp(int a, int b){
	return order[a] < order[b];
}

void DFS(int x){
	ch[x] = 1;
	DFS_path[L++] = x;
	
	for(int i=0; i<ad[x].size();i++){
		int nx = ad[x][i];
		if(ch[nx]==0) DFS(nx);
	}
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	
	for(int i=1; i<n; i++){
		int node1, node2;
		cin >> node1 >> node2;
		ad[node1].push_back(node2);
		ad[node2].push_back(node1);
	}
	
	for(int i=1; i<=n; i++){
		int node;
		cin >> node; 
		given_path[i] = node;
		order[node] = i;
	}
	
	for(int i=1; i<=n; i++){
		sort(ad[i].begin(), ad[i].end(), comp);
	}

	DFS(1);
	for(int i=1; i<=n; i++){
		if(given_path[i]!=DFS_path[i]){
			cout << 0;
			return 0;
		}
	}
	cout << 1;
}