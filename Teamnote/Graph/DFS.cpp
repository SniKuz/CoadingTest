//https://aj4941.tistory.com/17 에 dfs 아직 다 안함

#include <vector>

using namespace std;

vector<int> graph[20001];
int DFS_cnt = 1;
int DFS_num[20001];
int DFS_min[20001];
int cache[20001];
vector <int> stack;

vector<vector<int> > SCC;
int SCC_num[20001];

void DFS(int v)
{
    cache[v] = 1;
    DFS_num[v] = DFS_min[v] = DFS_cnt++;
    stack.push_back(v);
    for(int nv : graph[v])
    {
        if(!DFS_num[nv]) DFS(nv);
        if(cache[nv]) DFS_min[v] = min(DFS_min[v], DFS_min[nv]);
    }

    if(DFS_num[v] == DFS_min[v])
    {
        SCC.emplace_back();
        while(true)
        {
            int tv = stack.back();
            SCC.back().push_back(tv);
            cache[tv] = 0;
            stack.pop_back();

            SCC_num[tv] = SCC.size() - 1;
            if(tv == v) break;
        }
    }
}