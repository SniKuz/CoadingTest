#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> world;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> currentPos(2);
    int maxRow = park[0].size(), maxCol = park.size();
    for(int i = 0; i < park.size(); i++)
    {
        vector<int> tmpRoad;
        for(int j = 0; j < park[0].size(); j++)
        {
            auto tile = park[i][j];
            if(tile == 'O')
            {
                tmpRoad.push_back(1);
            }
            else if(tile == 'X')
            {
                tmpRoad.push_back(0);
            }
            else
            {
                tmpRoad.push_back(1);
                currentPos[0] = i, currentPos[1] = j;
            }
        }
        world.push_back(tmpRoad);
    }
    
    // for(auto x : world)
    // {
    //     for(auto y : x)
    //         cout << y << ' ';
    //     cout <<'\n';
    // }
    
    for(auto route : routes)
    {
        auto dir = route[0];
        int t = int(route[2]) - 48;
       
        if(dir == 'E' && currentPos[1] + t < maxRow)
        {
            bool obstacle = false;
            for(int i = 0; i <= t; i++)
                if(!world[currentPos[0]][currentPos[1]+i])
                    obstacle = true;
            if(!obstacle) currentPos[1] += t;
        }
        if(dir == 'W' && currentPos[1] - t >= 0)
        {
            bool obstacle = false;
            for(int i = 0; i <= t; i++)
                if(!world[currentPos[0]][currentPos[1]-i])
                    obstacle = true;
            if(!obstacle) currentPos[1] -= t;
        }
        if(dir == 'N' && currentPos[0] - t >= 0)
        {
            bool obstacle = false;
            for(int i = 0; i <= t; i++)
                if(!world[currentPos[0]-i][currentPos[1]])
                    obstacle = true;
            if(!obstacle) currentPos[0] -= t;
        }
        if(dir == 'S' && currentPos[0] + t < maxCol)
        {
            bool obstacle = false;
            for(int i = 0; i <= t; i++)
                if(!world[currentPos[0]+i][currentPos[1]])
                    obstacle = true;
            if(!obstacle) currentPos[0] += t;
        }
        
    }
    
    return currentPos;
}