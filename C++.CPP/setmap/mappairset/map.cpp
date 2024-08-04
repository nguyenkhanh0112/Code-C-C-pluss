#include<iostream>
#include<bits/stdc++.h>
#include<set>
#include<map>
#include<unordered_map>

using namespace std;

//(key,value);
//insert
//count
//find
//ordered
// dem so lan xuat hien cua cac phan tu trong mang, sau in ra man hinh kem theo tan xuat cua no 
int main(){
    multimap<int,int>mp;
    mp.insert({1,200});
    mp.insert({2,200});
    mp.insert({1,200});
    for(auto it:mp){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}