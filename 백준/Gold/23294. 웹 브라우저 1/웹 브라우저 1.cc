#include <bits/stdc++.h>
using namespace std;

int n, q, c;
map<int, int> capacity;
deque<int> backward;
vector<int> frontward;
int curPage = -1;
int curCap = 0;

void AccessPage()
{
    while(frontward.empty() == false)
    {
        auto cache = frontward.back(); frontward.pop_back();
        curCap -= capacity[cache];
    }
    if(curPage != -1)
    {
        backward.push_back(curPage);
    }
    cin >> curPage;
    curCap += capacity[curPage];
    
    while(curCap > c)
    {
        curCap -= capacity[backward.front()];
        backward.pop_front();
    }
}


int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> q >> c;
    for(int i = 1; i <= n; i++)
    {
        int cap;
        cin >> cap;
        capacity[i] = cap;
    }
    for(int i = 0; i < q; i++)
    {
        char cmd;
        cin >> cmd;
        switch(cmd)
        {
            case 'B':
                {
                    if(backward.empty())
                    {
                        // do nothing
                    }
                    else
                    {
                        frontward.push_back(curPage);
                        curPage = backward.back();
                        backward.pop_back();
                    }
                }
                break;
            case 'F':
                {
                    if(frontward.empty())
                    {
                        // do nothing
                    }
                    else
                    {
                        backward.push_back(curPage);
                        curPage = frontward.back();
                        frontward.pop_back();
                    }
                }
                break;
            case 'A':
                {
                    AccessPage();
                }
                break;
            case 'C':
                {
                    if(backward.empty() == false)
                    {
                        int backwardSize = backward.size() - 1;
                        backward.push_front(backward.back()); backward.pop_back();
                        for(int i = 0; i < backwardSize; i++)
                        {
                            if(backward.back() == backward.front())
                            {
                                curCap -= capacity[backward.back()];
                            }
                            else
                            {
                                backward.push_front(backward.back());
                            }
                            backward.pop_back();
                        }
                    }
                }
                break;
        }
    }
    cout << curPage << '\n';
    if(backward.empty())
    {
        cout << -1 << '\n';
    }
    else
    {
        for(auto itr = backward.rbegin(); itr != backward.rend(); itr++)
        {
            cout << *itr << ' ';
        }
        cout << '\n';
    }
    if(frontward.empty())
    {
        cout << -1;
    }
    else
    {
        for(auto itr = frontward.rbegin(); itr != frontward.rend(); itr++)
        {
            cout << *itr << ' ';
        }
    }
    return 0;
}

/*
같은 번호의 페이지가 연속해서 2개 이상 > 1, 1, 1이렇게 등장하는 경우라는 뜻인듯? 홀리 쉣
*/