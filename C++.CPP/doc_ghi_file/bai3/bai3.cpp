/*bai 3: doc cac so nguyen tu file input.txt biet 
+ chi co 1 dong duy nhat chua cac so nguyen va moi so nguyen 
cach nhau boi du cham phay
vd: 1,3,6,9
=== yeu cau ===
- file UCLN.txt luu 1 so nguyen la uoc chung lon nhat cua tat ca cac phantu cua mang
- file BCNN.txt luu 1 so nguyen la boi chung nho nhat cua tat ca cac thanh tu cua mang 
*/
#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

// ham doc du lieu tu file
void doc_file(int arr[],int &n,ifstream &filein){
    while(filein.eof()==false){
        filein>>arr[n];
        char x;
        filein>>x;
        n++;
    }
}
int gcd(int a,int b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int lcm(int a,int b){
    return (a*b)/gcd(a,b);
}
void check(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int UCLN(int arr[],int n){
    int x=arr[0];
    for(int i=1;i<n;i++){
        x=gcd(x,arr[i]);
    }
    return x;
}
int BCNN(int arr[],int n){
    int x=arr[0];
    for(int i=1;i<n;i++){
        x=lcm(x,arr[i]);
    }
    return x;
}
int main(){
    ifstream filein;
    ofstream fileout;
    filein.open("INPUT.txt",ios_base::in);
    int n=0;
    int arr[100];
    doc_file(arr,n,filein);
    check(arr,n);
    fileout.open("UCLN.txt",ios_base::out);
    fileout<<UCLN(arr,n);
    fileout.close();


    fileout.open("BCNN.txt",ios_base::out);
    fileout<<BCNN(arr,n);
    fileout.close();
    filein.close();
    system("pause");
    return 0;
}