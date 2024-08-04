#include<iostream>
#include<bits/stdc++.h>
#include<set>
#include<map>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,cnt=0;
        cin>>n;
        set<int>s;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            s.insert(x);
        }
       for(auto it: s){
            cnt++;
       }
       cout<<cnt<<endl;
    }
    return 0;
}