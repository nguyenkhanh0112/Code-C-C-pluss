#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//nhap vao cay nhi phan cac so nguyen 
//xuat ra man hinh cac phan tu cua cay nhij phan


// khai bao cau truc 1 node 
struct node{
    int data;//du lieu cua node ==>du lieu ma node se luu tru 
    struct node *left;
    struct node *right;
};
typedef node* tree;
//khoi tao cay
void khoitaocay(tree &t){
    t = NULL;// cay rong ;
}
// ham them phan tu x vao cay nhi phan 

void themnodevaocay(tree &t,int x){
    //neu cay rong
    if(t==NULL){
        node *p=new node();// khoi tao 1 cai node de them vao cay
        p->data=x;
        p->left=NULL;
        p->right=NULL;
        t=p;// node p chinh la node goc 
    }
    // cay co ton tai phan tu 
    else{
        // neu phan tu them vao nho hon node goc ==>them no vao ben trai
        if(t->data>x){
            themnodevaocay(t->left,x);// duyet qua trai de them phan tu x
        }
        else if(t->data<x){
            themnodevaocay(t->right,x);// duyet qua phair de them phan tu x
        }
    }
}
//ham xuat cya nhi phan theo NLR
void duyet_NLR(tree t){
    if(t!=NULL){
        cout<<t->data<<" ";
        duyet_NLR(t->left);
        duyet_NLR(t->right);
    }
}
void duyet_NRL(tree t){
    if(t!=NULL){
        cout<<t->data<<" ";
        duyet_NRL(t->right);
        duyet_NRL(t->left);
    }
}
void duyet_LRN(tree t){
    if(t!=NULL){
        duyet_LRN(t->left);
        duyet_LRN(t->right);
        cout<<t->data<<" ";
    }
}
// ham nhap du lieu 
void menu(tree &t){
    while(1){
        system("cls");
        cout<<"\n\n\t\t============menu============";
        cout<<"\n1.nhap du lieu";
        cout<<"\n2.xuat du lieu NLR";
        cout<<"\n3.xuat du lieu NRL";
        cout<<"\n4.xuat du lieu LRN";
        cout<<"\n0.ket thuc";
        cout<<"\n\n\t\t=============End============";
        int luachon;
        cout<<"\nnhap lua chon: ";
        cin>>luachon;
        if(luachon<0||luachon>4){
        cout<<"\nlua chon ko hop le";
        system("pause");
        }
        else if(luachon==1){
            int x;
            cout<<"\nnhap so nguyen x: ";
            cin>>x;
            themnodevaocay(t,x);
        }else if(luachon==2){
            cout<<"\n\t\t DUYET CAY THEO NLR ";
            duyet_NLR(t);
            system("pause");
        }else if(luachon==3){
            cout<<"\n\t\t DUYET CAY THEO NRL ";
            duyet_NRL(t);
            system("pause");
        }else if(luachon==4){
            cout<<"\n\t\t DUYET CAY THEO LRN ";
            duyet_LRN(t);
            system("pause");
        }else{
            break;
        }
    }
}


int main(){
    tree t;
    khoitaocay(t);
    menu(t);
    system("pause");
    return 0;
}