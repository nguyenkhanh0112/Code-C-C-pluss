#include<iostream>
#include<bits/stdc++.h>

using namespace std;

//isempty: kiem tra xem stack co rong hay khong 
//push: them 1 đối tượng vào đầu stack <=> teo cơ chế LIFO
//pop: lấy phần tử đầu stack và trả về đối tượng đầu stack đồng thời phải hủy nó đi 
//top: xem thông tin của stack đầu danh sách và ko hủy nó đi 

// nhap danh sach stack chua các so nguyen, xuat ra man hinh cac so vua nhap
// khai báo cấu trúc của 1 cái node trong stack
struct node{
    int data;
    node *next;// con trỏ liên kết giữa các node vs nhau
};

// khai bao cau truc stack
struct stack1{
    node *top;// dùng con trỏ đầu để quản lí stack
};

// hàm khởi tạo stack

void khoitaostack(stack1 &s){
    s.top=NULL;
}
// == kiem tra stack co rong hay khong 
bool IsEmpty(stack1 s){
    // neu danh sach rong 
    if(s.top==NULL)
        return true;
    return false;// danh sach co phan tu 
}
// khoi tao node
node *khoitaonode(int x){
    node *makenode=new node();
    if(makenode==NULL){
        cout<<"\nkhong du bo nho de cap phat";
        return NULL;
    }
    makenode->data=x;
    makenode->next=NULL;
}
// them mot phan tu vao dau stack theo co che LIFO
bool Push(stack1 &s,node *p){
    if(p==NULL)
        return false;
    /// neu danh sach rong 
    if(IsEmpty(s)==true){
        s.top=p;
    }
    else{// danh sach da co phan tu 
        p->next=s.top;
        s.top=p;
    }
    return true;
}
// lay phan tu dau stack-huy di 
bool pop(stack1 &s,int &x){
    if(IsEmpty(s)==true){
        return false;
    }
    else{
        node *k=s.top;
        x=k->data;
        s.top=s.top->next;
        delete(k);
    }
    return true;
}
bool top(stack1 &s,int &x){
    if(IsEmpty(s)==true){
        return false;
    }
    x=s.top->data;
    return true;
}
// ham xuat danh sahc ra man hinh
void xuatstack(stack1 s){
    while(IsEmpty(s)==false){
        int x;
        pop(s,x);
        cout<<x<<" ";
    }
    if(IsEmpty(s)==true){
        cout<<"\nDANH SACH DANG RONG KIA";
    }
    else{
        cout<<"\nDANH SAHC DANG TON TAI PHAN TU ";
    }
}
// ham nhap danh sach cac so nguyen trong stack
void nhapstack(stack1 &s){
    int luachon;
    while(1){
        cout<<"\n\n\t\t===================Menu ===================";
        cout<<"\n\t1. them phan tu vao stack";
        cout<<"\n\t2. xua danh sach stack ra man hinh";
        cout<<"\n\t3. xem thong tin dau stack";
        cout<<"\n\t0. ket thuc";
        cout<<"\n\n\t\t===================End ====================";
        cout<<"\nnhap lua chon: ";
        cin>>luachon;
        if(luachon==1){
            int x;
            cout<<"\nnhap phan tu can them: ";
            cin>>x;
            node *p=khoitaonode(x);
            Push(s,p);
        }
        else if(luachon==2){
            xuatstack(s);
            system("pause");
        }
        else if(luachon==3){
            int x;
            top(s,x);
            cout<<"\nphan tu dau stack la: "<<x;
        }
        else{
            break;
        }
    }
}
int main(){
    stack1 s;
    khoitaostack(s);
    nhapstack(s);
    return 0;
}