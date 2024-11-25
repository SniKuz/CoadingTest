#include <bits/stdc++.h>

using namespace std;

struct Node
{
    map<string, Node*> children;
    string _data;
    
    Node(string data = "")
    {
        _data = data;
    }  
    ~Node()
    {
        for(auto& child : children)
        {
            delete child.second;
        }
    }
};

vector<string> split(string str, char target = ' ')
{
    istringstream iss(str);
    string buf;
    vector<string> ret;
    
    while(getline(iss, buf, target))
    {
        ret.push_back(buf);
    }
    return ret;
}

int d;
Node* root = new Node("root");

void Print(Node* cur, int cnt)
{
    for(int c = 0; c < cnt; c++)
    {
        cout << ' ';
    }
    cout << cur->_data << '\n';
    for(const auto& child : cur->children)
    {
        Print(child.second, cnt+1);
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> d;
    for(int i = 0; i < d; i++)
    {
        string str;
        cin >> str;
        auto splitStr = split(str, '\\');
        
        auto prev = root;
        for(const auto& dir : splitStr)
        {
            if(prev->children[dir] == nullptr)
            {
                Node* child = new Node(dir);
                prev->children[dir] = child;
            }
            prev = prev->children[dir];
        } 
    }
    
    for(const auto& child : root->children)
    {
        Print(child.second, 0);
    }
    
    delete root;
    return 0;
}
