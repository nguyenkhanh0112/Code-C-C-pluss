#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int count[1000];
        int a[n];
        for(int &x:a){
            cin>>x;
        }
        count[0]=a[0];
        int s=1;
        for(int i=1;i<n;i++){
            int cnt=0;
            for(int j=0;j<s;j++){
                if(a[i]==count[j])
                    cnt++;
            }
            if(cnt==0){
                count[s]=a[i];
                s++;
            }
        }
        cout<<s<<endl;
    }
    return 0;
}