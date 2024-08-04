#include<iostream>

using namespace std;
int a[100000],maxN=100000;
int n=0;

int size(){
    return n;
}
void push(int x){
    if(n==maxN)
        cout<<"stack overflow"<<endl;
    a[n]=x;
    n++;
}
void pop(){
    if(n==0) 
        return;
    for(int i=0;i<n-1;i++){
        a[i]=a[i+1];
    }
    --n;
}
bool empty(){
    return n==0;
}
int front(){
    return a[0];
}
void display(){
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
}
int main(){
    while(1){
        cout<<"\n-------------------------\n";
        cout<<"1.push\n";
        cout<<"2.pop\n";
        cout<<"3.size\n";
        cout<<"4.empty\n";
        cout<<"5.front\n";
        cout<<"6.display\n";
        cout<<"0.thoat\n";
        cout<<"\n-------------------------\n";
        cout<<"nhap lc: ";int lc;
        cin>>lc;
        if(lc==1){
            int x;cin>>x;
            push(x);
        }else if(lc==2){
            pop();
        }else if(lc==3){
            cout<<size()<<endl;
        }else if(lc==4){
            if(empty())
                cout<<"empty!\n";
            else   
                cout<<"Not empty\n";
        }else if(lc==5){
            front();
        }else if(lc==6){
            display();
        }else if(lc==0)
            break;
    }
    return 0;
}