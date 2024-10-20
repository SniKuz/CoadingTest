#include <bits/stdc++.h>

using namespace std;

vector<deque<int>> wheels(5);
int k;
int res = 0;

void Rotate(int idx, int dir)
{
    if(dir > 0)
    {
        wheels[idx].push_front(wheels[idx].back());
        wheels[idx].pop_back();
    }
    else
    {
        wheels[idx].push_back(wheels[idx].front());
        wheels[idx].pop_front();
    }
}

int main() 
{
    for(int i = 1; i <= 4; i++)
    {
        string wheel;
        cin >> wheel;
        for(int j = 0; j < 8; j++)
        {
            if(wheel[j] == '1')
                wheels[i].push_back(1);
            else
                wheels[i].push_back(0);
        }
    }
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        int cmd, dir;
        cin >> cmd >> dir;

        bool one = wheels[1][2] != wheels[2][6];
        bool two = wheels[2][2] != wheels[3][6];
        bool three = wheels[3][2] != wheels[4][6];
        switch(cmd)
        {
            case 1:
                {
                    Rotate(1, dir);
                    if(one) 
                    {
                        Rotate(2, -dir);
                        if(two)
                        {
                            Rotate(3, dir);
                            if(three)
                            {
                                Rotate(4, -dir);
                            }
                        }
                    }
                }
                break;
            case 2:
                {
                    if(one) Rotate(1, -dir);
                    Rotate(2, dir);
                    if(two)
                    {
                        Rotate(3, -dir);
                        if(three)
                        {
                            Rotate(4, dir);
                        }
                    }
                }
                break;
            case 3:
                {
                    if(two) 
                    {
                        Rotate(2, -dir);
                        if(one)
                        {
                            Rotate(1, dir);
                        }
                    }
                    Rotate(3, dir);
                    if(three) Rotate(4, -dir);
                }
                break;
            case 4:
                {
                    if(three) 
                    {
                        Rotate(3, -dir);
                        if(two)
                        {
                            Rotate(2, dir);
                            if(one)
                            {
                                Rotate(1, -dir);
                            }
                        }
                    }
                    Rotate(4, dir);
                }
                break;
        }
    }
    
    if(wheels[1].front() == 1) res += 1;
    if(wheels[2].front() == 1) res += 2;
    if(wheels[3].front() == 1) res += 4;
    if(wheels[4].front() == 1) res += 8;
    cout << res;
    return 0;
}