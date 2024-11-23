#include <bits/stdc++.h>

using namespace std;

struct Node
{
    unordered_map<string, Node*> children;
    string _data;
    bool used = false;
    
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

int n;

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

int Check(Node* cur)
{
    if(cur->children.size() == 0)
    {
        cur->used = true;
        return 1;
    }
    
    int cnt = 0;
    for(auto& child : cur->children)
    {
        if(child.second->used == false)
        {
            child.second->used = true;
            cnt += Check(child.second);
        }
    }
    return cnt;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    while(n != 0)
    {
        unordered_map<string, Node*> hashs;
        bool isFirst = true;
        string firstGroup;
        for(int i = 0; i < n; i++)
        {
            string str;
            cin >> str;
            auto splitStr = split(str, ':');
            splitStr.back().pop_back();
            auto childs = split(splitStr.back(), ',');
            if(isFirst)
            {
                isFirst = false;
                firstGroup = splitStr.front();
            }
            Node* group = hashs[splitStr.front()];
            if(group == nullptr)
            {
                group = new Node(splitStr.front());
                hashs[splitStr.front()] = group;
            }
            for(const auto& e : childs)
            {
                Node* child = hashs[e];
                if(child == nullptr)
                {
                    child = new Node(e);
                    hashs[e] = child;
                }
                group->children[e] = hashs[e];
            }
        }
        cout << Check(hashs[firstGroup]) << '\n';
        cin >> n;
    }
    
    return 0;
}

/*
1차시도 : 25% 시간초과
2차시도 : unordered_map으로 변경. 25% 시간초과
3차시도 : bool값 체크
4차시도 : 할당 줄이기
*/

