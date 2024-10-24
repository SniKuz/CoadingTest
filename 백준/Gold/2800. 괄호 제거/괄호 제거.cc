#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

string input;
int inputSize;
set<string> words;
vector<pii> bracketPos;
vector<int> bracket;

void DFS(vector<bool> visited, string text)
{
    int bSize = bracketPos.size();
    for(int i = 0; i < bSize ; i++)
    {
        if(visited[i] == false)
        {
            visited[i] = true;
            text[bracketPos[i].first] = '_';
            text[bracketPos[i].second] = '_';
            string word = "";
            for(const auto& e : text)
            {
                if(e != '_')
                    word += e;
            }
            if(words.find(word) == words.end())
            {
                words.insert(word);
                DFS(visited, text);
            }
            text[bracketPos[i].first] = '(';
            text[bracketPos[i].second] = ')';
            visited[i] = false;
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> input;
    inputSize = input.size();
    for(int i = 0; i < inputSize; i++)
    {
        if(input[i] == '(')
        {
            bracket.push_back(i);
        }
        else if(input[i] == ')')
        {
            bracketPos.push_back({bracket.back(), i});
            bracket.pop_back();
        }
    }
    vector<bool> visited(bracketPos.size());
    DFS(visited, input);
    for(const auto& e : words)
    {
        cout << e << '\n';
    }
    return 0;
}