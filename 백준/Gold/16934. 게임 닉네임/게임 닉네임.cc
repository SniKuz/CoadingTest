#include <bits/stdc++.h>

using namespace std;

struct Node
{
    map<char, Node*> children;
    char _c;
    
    Node(char c = ' ') 
    {
        _c = c;
    }
    ~Node()
    {
        for(auto& child : children)
            delete child.second;
    }
};

int n;
map<string, int> dict;
Node* root = new Node();

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        dict[str]++;
        bool prefix = false;
        Node* prev = root;
        for(int i = 0; i < str.size(); i++)
        {
            if(prev->children.find(str[i]) != prev->children.end())
            {
                prev = prev->children[str[i]];
            }
            else
            {
                if(prefix == false)
                {
                    prefix = true;
                    cout << str.substr(0, i+1) << '\n';
                }
                Node* n = new Node(str[i]);
                prev->children[str[i]] = n;
                prev = prev->children[str[i]];
            }
        }
        if(prefix == false)
        {
            cout << str;
            if(dict[str] > 1) 
                cout << dict[str] << '\n';
            else
                cout << '\n';
        }
    }

    delete root;
    return 0;
}