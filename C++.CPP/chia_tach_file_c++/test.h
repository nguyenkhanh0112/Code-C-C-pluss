#include<iostream>// khai bao thu vien co san ho tro viec nhap xuat 
#include<math.h>

using namespace std;

// khai bao ham kiem tra so nguyto

int kiem_tra_so_nguyen_to(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)
            return 0;
    }
    return n>1;
}















