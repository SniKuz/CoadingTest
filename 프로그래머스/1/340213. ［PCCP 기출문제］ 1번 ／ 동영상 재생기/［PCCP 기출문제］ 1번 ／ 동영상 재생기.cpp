#include <bits/stdc++.h>

using namespace std;

int Time2Sec(string time)
{
    int sec = 0;
    sec += stoi(time.substr(0, 2)) * 60;
    sec += stoi(time.substr(3, 2));
    return sec;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int vLen = Time2Sec(video_len);
    int cur = Time2Sec(pos);
    int opS = Time2Sec(op_start);
    int opE = Time2Sec(op_end);

    for(const auto& cmd : commands)
    {
        if(opS <= cur && cur <= opE)
        {
            cur = opE;
        }
        
        if(cmd.compare("next") == 0)
        {
            cur += 10;
            if(cur > vLen) cur = vLen;
        }
        else
        {
            if(cur < 10)
                cur = 0;
            else
                cur -= 10;
        }
    }
    if(opS <= cur && cur <= opE)
    {
        cur = opE;
    }

    string ans = "";
    int minute = cur / 60;
    int second = cur % 60;
    if(minute < 10)
        ans += '0' + to_string(minute) + ':';
    else
        ans += to_string(minute) + ':';
    if(second < 10)
        if(second == 0)
            ans += "00";
        else
            ans += '0' + to_string(second);
    else
        ans += to_string(second);
    return ans;
}