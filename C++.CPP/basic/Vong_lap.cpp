#include<iostream>
#include<math.h>

using namespace std;
int bai1(int n){
    int sum=0;
    for(int i=0;i<=n;i++){
        sum+=i;
    }
    return sum;
}
int bai2(int n){
    int sum2=0;
    for(int i=0;i<n;i++){
        sum2+=pow(i,2);
    }
    return sum2;
}
int bai3(int n){
    int sum3=0;
    for(int i=0;i<=n;i+=3){
        if(i%3==0){
            sum3+=i;
        }
    }
    return sum3;
}

double bai4(int n){
    double sum4=1;
    for(int i=0;i<n;i++){
        sum4+=1.0/n;
    }
    return sum4 ;

}
int main(){
    int n;
    cin>>n;
    cout<< bai1(n)<<" "<<bai2(n)<<" "<<bai3(n)<<" "<<bai4(n);
    return 0;
}