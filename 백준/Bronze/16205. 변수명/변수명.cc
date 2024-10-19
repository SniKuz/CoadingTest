#include <bits/stdc++.h>

using namespace std;

int n;
string input;

string Camel2Snake(string camel)
{
    string ret = "";
    for(const auto& c : camel)
    {
        if(c < 'a')
        {
            ret.push_back('_');
        }
        ret.push_back(tolower(c));
    }
    return ret;
}
string Camel2Pascal(string camel)
{
    string ret = camel;
    ret[0] = toupper(ret[0]);
    return ret;
}

string Snake2Camel(string snake)
{
    string ret = "";
    int sSize = snake.size();
    bool nextUpper = false;
    for(int i = 0; i < sSize; i++)
    {
        if(snake[i] == '_')
        {
            nextUpper = true;
        }
        else
        {
            if(nextUpper)
            {
                ret.push_back(toupper(snake[i]));
                nextUpper = false;
            }
            else
            {
                ret.push_back(snake[i]);
            }
        }
    }
    return ret;
}
string Pascal2Snake(string pascal)
{
    string ret = "";
    pascal[0] = tolower(pascal[0]);
    int pSize = pascal.size();
    for(int i = 0; i < pSize; i++)
    {
        if(pascal[i] < 'a')
        {
            ret.push_back('_');
        }
        ret.push_back(tolower(pascal[i]));
    }
    return ret;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> input;
    if(n == 1) //Camel
    {
        cout << input << '\n';
        cout << Camel2Snake(input) << '\n';
        cout << Camel2Pascal(input);
    }
    else if(n == 2) // snake
    {
        cout << Snake2Camel(input)<< '\n';
        cout << input << '\n';
        cout << Camel2Pascal(Snake2Camel(input));
    }
    else
    {
        input[0] = tolower(input[0]);
        cout << input << '\n';
        input[0] = toupper(input[0]);
        cout << Pascal2Snake(input) << '\n';
        cout << input;
    }
    return 0;
}
