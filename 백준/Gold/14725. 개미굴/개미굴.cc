#include <bits/stdc++.h>

using namespace std;

struct Node 
{
    map<string, Node*> children;  
    string data;
    
    Node(string str = "") : data(str) {}  
    
    ~Node() 
    {
        for(auto& child : children) 
        {
            delete child.second;
        }
    }
};

Node* root = new Node();  

void Print(Node* cur, int cnt) {
    for(int i = 0; i < cnt; i++)
        cout << "--";
    cout << cur->data << '\n';
    
    for(const auto& next : cur->children) {
        Print(next.second, cnt+1);
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) 
    {
        int k;
        cin >> k;
        Node* prev = root;
        
        for(int j = 0; j < k; j++) 
        {
            string str;
            cin >> str;
            if(prev->children.find(str) == prev->children.end()) 
            {
                prev->children[str] = new Node(str);
            }
            prev = prev->children[str];
        }
    }
    
    for(const auto& start : root->children) 
    {
        Print(start.second, 0);
    }
    
    delete root;
    return 0;
}