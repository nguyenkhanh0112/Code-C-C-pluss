#include<bits/stdc++.h>
#include<iostream>
#include<vector>

using namespace std;


//pair<datatype1,datatype2> v;
int main(){
    // pair<string,int> v;
   tuple<int ,int ,int> t{1,2,3};
   cout<<get<1>(t)<<endl;
    return 0;
}