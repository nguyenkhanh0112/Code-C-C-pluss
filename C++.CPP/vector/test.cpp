#include<bits/stdc++.h>

using namespace std;


string catAndMouse(int x, int y, int z) {
    int d1=z-x;
    int d2=z-y;
    string s;
    d1=abs(d1);
    d2=abs(d2);
    cout<<d1<<" "<<d2<<endl;
    if(d1<d2)
        s="Cat A";
    if(d2<d1)
        s="Cat B";
    if(d2==d1)
        s="Mouse C";
    return s;
}
int main(){
    int x,y,z;
    int p;
    cin>>p;
    for(int i=0;i<p;i++){
         cin>>x>>y>>z;
        cout<<catAndMouse(x,y,z)<<endl;
    }
}














