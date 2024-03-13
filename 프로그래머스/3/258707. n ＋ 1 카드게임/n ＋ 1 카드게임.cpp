
/*
3, 8, 10 14
*/

#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int n, targetNum, turn = 0, i, _coin;
set<int> ad;
set<int> grave;
priority_queue<int> readyToUseCards;
vector<int> cardNotUsed(1001, 1);


bool UseCard()
{
    if(readyToUseCards.empty()) return false;
    auto useCard = readyToUseCards.top(); readyToUseCards.pop();
    
    if(_coin < -useCard)
        return false;

    _coin += useCard;
    return true;
}

int solution(int coin, vector<int> cards) {
    int n = cards.size();
    int targetNum = n + 1;
    _coin = coin;

    for(i = 0; i < n / 3; ++i)
    {
        ad.insert(cards[i]);
        if(cardNotUsed[cards[i]] && ad.find(targetNum - cards[i]) != ad.end())
        {
            cardNotUsed[cards[i]] = 0;
            cardNotUsed[targetNum - cards[i]] = 0;
            readyToUseCards.push(0);
        }
    }
    
    
    for(; i < n; i = i + 2)
    {
        turn++;
        int first = cards[i];
        int second = cards[i+1];
        if(cardNotUsed[first] && ad.find(targetNum - first) != ad.end())
        {
            readyToUseCards.push(-1);
            cardNotUsed[first] = 0;
            cardNotUsed[targetNum - first] = 0;
        }
        else
        {
            grave.insert(first);
            if(cardNotUsed[first] && grave.find(targetNum - first) != grave.end())
            {
                readyToUseCards.push(-2);
                cardNotUsed[first] = 0;
                cardNotUsed[targetNum - first] = 0;
            }
        }
        if(cardNotUsed[second] && ad.find(targetNum - second) != ad.end())
        {
            readyToUseCards.push(-1);
            cardNotUsed[second] = 0;
            cardNotUsed[targetNum - second] = 0;
        }
        else
        {
            grave.insert(second);
            if(cardNotUsed[second] && grave.find(targetNum - second) != grave.end())
            {
                readyToUseCards.push(-2);
                cardNotUsed[second] = 0;
                cardNotUsed[targetNum - second] = 0;
            }
        }

        if(!UseCard())
            break;
    }
    
    if(i == n) turn++;
    return turn;
}