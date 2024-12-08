#include <bits/stdc++.h>

using namespace std;

string roma1, roma2;
int roma1Num = 0, roma2Num = 0;

map<char, int> dict = {
    {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
    {'C', 100}, {'D', 500}, {'M', 1000} 
};

map<char, int> keys= {
    {'I', 0}, {'V', 1}, {'X', 2}, {'L', 3},
    {'C', 4}, {'D', 5}, {'M', 6} 
};

int ChangeRoma2Decimal(string roma)
{
    int sum = 0;
    int cur = 0;
    int rSize = roma.size();
    while(cur < rSize)
    {
        if(cur+1 < rSize && dict[roma[cur]] < dict[roma[cur+1]])
        {
            sum += dict[roma[cur+1]] - dict[roma[cur]];
            cur += 2;
        }
        else
        {
            sum += dict[roma[cur]];
            cur += 1;
        }
    }
    return sum;
}

string ChangeDecimal2Roma(int decimal)
{
    string arabia; 
    set<string> history;
    vector<bool> used(7);
    
    while(decimal > 0)
    {
        if(decimal >= 1000)
        {
            decimal  -= 1000;
            arabia.push_back('M');
        }
        else if(1000 > decimal && decimal >= 900)
        {
            decimal -= 900;
            arabia += "CM";
            history.insert("CM");
        }
        else if(900 > decimal && decimal >= 500 && used[keys['D']] == false)
        {
            decimal -= 500;
            arabia.push_back('D');
            used[keys['D']] = true;
        }
        else if( 500 > decimal && decimal >= 400 && used[keys['D']] == false && (history.find("CM") == history.end()) )
        {
            decimal -= 400;
            arabia += "CD";
            used[keys['D']] = true;
        }
        else if(400 > decimal && decimal >= 100)
        {
            decimal -= 100;
            arabia.push_back('C');
        }
        else if(100 > decimal && decimal >= 90)
        {
            decimal -= 90;
            arabia += "XC";
            history.insert("XC");
        }
        else if(90 > decimal && decimal >= 50 && used[keys['L']] == false)
        {
            decimal -= 50;
            arabia.push_back('L');
            used[keys['L']] = true;
        }
        else if(50 > decimal && decimal >= 40 && used[keys['L']] == false && (history.find("XC") == history.end()))
        {
            decimal -= 40;
            arabia += "XL";
            used[keys['L']] = true;
        }
        else if(40 > decimal && decimal >= 10)
        {
            decimal -= 10;
            arabia.push_back('X');
        }
        else if(decimal == 9)
        {
            decimal -= 9;
            arabia += "IX";
            history.insert("IX");
        }
        else if(9 > decimal && decimal >= 5 && used[keys['V']] == false)
        {
            decimal -= 5;
            arabia.push_back('V');
            used[keys['V']] = true;
        }
        else if(decimal == 4 && used[keys['V']] == false &&  (history.find("IX") == history.end()))
        {
            decimal -= 4;
            arabia += "IV";
            used[keys['V']] = true;
        }
        else
        {
            decimal -= 1;
            arabia.push_back('I');
        }
    }
    return arabia;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> roma1 >> roma2;
    roma1Num = ChangeRoma2Decimal(roma1);
    roma2Num = ChangeRoma2Decimal(roma2);
    
    int sumRoma = roma1Num + roma2Num;
    cout << sumRoma << '\n' << ChangeDecimal2Roma(sumRoma);
    return 0;
}
