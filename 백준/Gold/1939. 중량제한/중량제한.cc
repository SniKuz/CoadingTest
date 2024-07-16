#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 10001
#define INF 1000000000
using namespace std;

vector<pair<int, pair<int,int>>> edge;
int parent[MAX];

int getParent(int x) {
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);

    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int findParent(int a, int b){
    a = getParent(a);
    b = getParent(b);

    if(a == b) return true;
    else return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> weight;
    int n, m;
    int a, b, c;
    int start, end;
    cin >> n >> m;

    for(int i = 1 ; i <= n ; i++) parent[i] = i;

    for(int i = 0 ; i < m ; i++) {
        cin >> a >> b >> c;
        edge.push_back({c, {a, b}}); 
        edge.push_back({c, {b, a}});
    }

    cin >> start >> end;
    sort(edge.begin(), edge.end(), greater<>());

    for(int i = 0 ; i < edge.size() ; i++) {
        int a = edge[i].second.first;
        int b = edge[i].second.second;
        int c = edge[i].first;

        if(findParent(a, b)) continue;
        unionParent(a, b);
        weight.push_back(c);

        if(findParent(start, end)) {
            cout << *min_element(weight.begin(), weight.end());
            break;
        }
    }

    return 0;
}