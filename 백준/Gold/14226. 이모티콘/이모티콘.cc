#include <bits/stdc++.h>
#define pii pair<int, int>
#define Data first
#define Time first
#define Emoticons second
#define CopyInfo second
#define SaveClips first
#define Clipboard second


using namespace std;

int n;
bool visited[2025][2025][2];

int main() 
{
    cin >> n;
    queue<pair<pii, pii>> q; 
    q.push({{0, 1}, {true, 0}});
    
    while (q.front().Data.Emoticons != n)
    {
        auto cur = q.front(); q.pop();

        if(cur.Data.Emoticons > 2024) continue;
        
        int clipFlag = cur.CopyInfo.SaveClips == true ? 0 : 1;
        if (visited[cur.Data.Emoticons][cur.CopyInfo.Clipboard][clipFlag]) continue;
        visited[cur.Data.Emoticons][cur.CopyInfo.Clipboard][clipFlag] = true;
    
        if (cur.CopyInfo.SaveClips)
        {
            q.push({{cur.Data.Time+1, cur.Data.Emoticons}, {false, cur.Data.Emoticons}});
        }
        else // copied Clipboard
        {
            q.push({{cur.Data.Time+1, cur.Data.Emoticons + cur.CopyInfo.Clipboard}, {true, cur.CopyInfo.Clipboard}});
            q.push({{cur.Data.Time+1, cur.Data.Emoticons + cur.CopyInfo.Clipboard}, {false, cur.CopyInfo.Clipboard}});
        }
        if (cur.Data.Emoticons > 1)
        {
            q.push({{cur.Data.Time+1, cur.Data.Emoticons-1}, {true, cur.CopyInfo.Clipboard}});
            q.push({{cur.Data.Time+1, cur.Data.Emoticons-1}, {false, cur.CopyInfo.Clipboard}});
        }
    }
    cout << q.front().Data.Time;
    return 0;
}
