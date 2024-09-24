#include <bits/stdc++.h>

using namespace std;

string sequence;
int n;
bool solve = false;
vector<int> nums(51);

void solution(int pos, vector<int> v)
{
    if(solve) return;
    if(pos >= sequence.size())
    {
        if(pos == sequence.size())
        {
            for(const auto& e : v)
                cout << e << ' ';
            solve = true;
        }
        return;
    }
    auto n1 = stoi(sequence.substr(pos, 1));
    if(n1 > 0 && n1 <= n && nums[n1] < 1)
    {
        nums[n1]++;
        v.push_back(n1);
        solution(pos+1, v);
        v.pop_back();
        nums[n1]--;
    }
    auto n2 = stoi(sequence.substr(pos, 2));
    if(n2 > 0 && n2 <= n && nums[n2] < 1)
    {
        nums[n2]++;
        v.push_back(n2);
        solution(pos+2, v);
        v.pop_back();
        nums[n2]--;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> sequence;
    if(sequence.size() < 10)
    {
        n = sequence.size();
    }
    else
    {
        n = (sequence.size() - 9) / 2 + 9;
    }
    solution(0, { });
}