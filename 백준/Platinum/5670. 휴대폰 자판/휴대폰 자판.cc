#include <bits/stdc++.h>

using namespace std;

struct Node{
    map<char, Node*> children;
    bool isWord;
    
    Node()
    {
        isWord = false;
    }  
    ~Node()
    {
        for(auto& child : children)
        {
            delete child.second;
        }
    }
};

int n;

void solution(const Node* cur, float& sum, int cnt)
{
    while(cur->isWord == false && cur->children.size() == 1)
    {
        auto begin = cur->children.begin();
        cur = (*begin).second;
    }
    if(cur->isWord)
    {
        sum += cnt;
    }
    
    for(const auto& child : cur->children)
    {
        solution(child.second, sum, cnt+1);
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(2);
    
    while(cin >> n)
    {
        Node* root = new Node();
        float sum = 0;
        vector<string> words(n);
        for(int i = 0; i < n; i++)
        {
            cin >> words[i];
            auto cur = root;
            for(const auto& e : words[i])
            {
                if(cur->children.find(e) != cur->children.end())
                    cur = cur->children[e];
                else
                {
                    Node* newNode = new Node();
                    cur->children[e] = newNode;
                    cur = newNode;
                }
            }
            cur->isWord = true;
        }
        for(int i = 0; i < 26; i++)
        {
            if(root->children.find('a'+ i) != root->children.end())
            {
                solution(root->children['a'+ i], sum, 1);
            }
        }
        cout << (sum / n) << '\n';
        delete root;
    }
    return 0;
}