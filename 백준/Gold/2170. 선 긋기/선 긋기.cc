#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;

    vector<pair<int,int>> arr(n,{0,0});
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }

    sort(arr.begin(),arr.end()); // first의 증가순으로, 같으면 second로 정렬

    int result=0; // 전체 길이 (최대 2*10^9)
    int start=arr[0].first;
    int end=arr[0].second;
    for(int i=1;i<n;i++){
        if(end>=arr[i].first){ //선분이 겹치거나 이어지면
            end=max(end, arr[i].second); //선분 연장
            
        }else{ // 겹치지 않는 경우 (end<arr[i].first)
            result+=(end-start);
            start=arr[i].first;
            end=arr[i].second;
        }
    }
    result+=(end-start);
    
    cout<<result;
}