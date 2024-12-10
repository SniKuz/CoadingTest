#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

struct Node{
    map<int, Node*> children;
    int _data;
    
    Node(int data)
    {
        _data = data;
    }  
    ~Node()
    {
        for(auto& child : children)
            delete child.second;
    }
};

int n, r, q;
vector<vector<int>> board(MAX);
vector<bool> used(MAX);
vector<int> treeSize(MAX);

void MakeTree(Node* cur)
{
    for(const auto& e : board[cur->_data])
    {
        if(used[e] == false)
        {
            used[e] = true;
            Node* newNode = new Node(e);
            cur->children[e] = newNode;
            MakeTree(newNode);
        }
    }
}

void CheckSize(Node* cur)
{
    treeSize[cur->_data] = 1;
    for(const auto& next : cur->children)
    {
        CheckSize(next.second);
        treeSize[cur->_data] += treeSize[next.first];
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> r >> q;
    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        board[u].push_back(v);
        board[v].push_back(u);
    }
    
    Node* root = new Node(r);
    used[r] = true;
    MakeTree(root);
    CheckSize(root);

    for(int i = 0; i < q; i++)
    {
        int Q;
        cin >> Q;
        cout << treeSize[Q] << '\n';
    }
    
    delete root;
    return 0;
}