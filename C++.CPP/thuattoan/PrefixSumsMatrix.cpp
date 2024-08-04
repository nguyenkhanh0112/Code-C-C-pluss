#include<iostream>


using namespace std;
// void sum(int arr[][100],int n,int m){
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             cin>>arr[i][j];
//         }
//     }
//     int q;
//     cin>>q;
//     while(q--){
//         int sum1=0;
//         int h1,h2,c1,c2;
//         cin>>h1>>h2>>c1>>c2;
//         for(int i=h1;i<=h2;i++){
//             for(int j=c1;j<=c2;j++){
//                 sum1+=arr[i][j];
//             }
//         }
//         cout<< sum1;
//     }
// }
int main(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
             cin>>arr[i][j];
        }
    }
    int prefix[n+1][m+1]={0};
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+arr[i][j];
        }
    }
    int q;cin>>q;
    while(q--){
        int h1,h2,c1,c2;
        cin>>h1>>h2>>c1>>c2;
        cout<<(prefix[h2][c2]-prefix[h1-1][c2]-prefix[h2][c1-1]+prefix[h1-1][c1-1])<<endl;
    }
    return 0;
}