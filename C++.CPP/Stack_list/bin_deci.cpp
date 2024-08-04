#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node *next;
};

struct stack1{
    node *top;
};

void khoitaostack(stack1 &s){
    s.top=NULL;
}

node *makenode(int x){
    node *newnode=new node();
    newnode->data=x;
    newnode->next=NULL;
}
bool IsEmpty(stack1 s){
    if(s.top==NULL)
        return true;
    return false;
}
bool push(stack1 &s,node *p){
    if(p==NULL)
        return false;
    if(IsEmpty(s)==true){
        s.top=p;
    }
    else{
        p->next=s.top;
        s.top=p;
    }
    return true;
}
bool pop(stack1 &s,int &x){
    if(IsEmpty(s)==true){
        return false;
    }
    else{
        node *k=s.top;
        x=k->data;
        s.top=s.top->next;
        delete k;
    }
    return true;
}
void chuyendoi(stack1 &s,int n){
    while(n!=0){
        int r=n%2;
        node *p=makenode(r);
        push(s,p);
        n/=2;
    }
}
void xuatdanhsach(stack1 s){
    while(IsEmpty(s)==false){
        int x;
        pop(s,x);
        cout<<x<<" ";
    }
}
int main(){
    stack1 s;
    khoitaostack(s);
    int n;
    cout<<"nhap so thap phan co 3 chu so: ";
    cin>>n;
    chuyendoi(s,n);
    cout<<"so nhi phan duoc doi la: "<<endl;
    xuatdanhsach(s);
}