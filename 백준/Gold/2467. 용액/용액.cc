#include <bits/stdc++.h>
using namespace std;

int n;
int a[100'005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    int ans=2*1e9+1;

    int st=0;
    int en=n-1;
    int ans1, ans2;
    while(st<en){
        int cur=a[st]+a[en];
        int num=abs(cur);
        if(num<ans){
            ans=num;
            ans1=a[st];
            ans2=a[en];
        }
        if(cur>0) en--;
        else st++;
    }
    cout<<ans1<<' '<<ans2;
}