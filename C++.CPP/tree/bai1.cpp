//  Đếm số lượng số nguyên tố trong cây nhị phân tìm kiếm
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};

void maketree(node* &t){
    t=NULL;
}

void khoitaotree(node* &t,int x){
    if(t==NULL){
        node *p=new node();
        p->data=x;
        p->left=NULL;
        p->right=NULL;
        t=p;
    }else{
        if(t->data>x){
            khoitaotree(t->left,x);
        }
        else if(t->data<x){
            khoitaotree(t->right,x);
        }
    }
}

bool Kiemtrasonguyento(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)
            return 0;
    }
    return n>1;
}
void demsl(node* t,int &dem){
    if(t!=NULL){
        if(Kiemtrasonguyento(t->data)==1){
            dem++;
        }
        demsl(t->right,dem);
        demsl(t->left,dem);
    }
        
}
void duyet_LRN(node* t){
    if(t!=NULL){
        duyet_LRN(t->left);
        duyet_LRN(t->right);
        cout<<t->data<<" ";
    }
}
// tim kiem node 
node* TimKiem(node* t,int x){
    if(t==NULL){
        return NULL;
    }
    else{
        if(x<t->data){
            TimKiem(t->left,x);
        }else if(x>t->data)
            TimKiem(t->right,x);
        else{
            return t;
        }
    }
}
// xuat cac node co 2 con 
void node_2_con(node* t){
    if(t!=NULL){
        if(t->left!=NULL&&t->right!=NULL){
            cout<<t->data<<" ";
        }
        node_2_con(t->left);
        node_2_con(t->right);
    }
}
// xuat cac node co 1 con 
void node_1_con(node* t){
    if(t!=NULL){
        if((t->left!=NULL&&t->right==NULL)||(t->left==NULL&&t->right!=NULL)){
            cout<<t->data<<" ";
        }
        node_1_con(t->left);
        node_1_con(t->right);
    }
}
// xuat cac node la 
void node_la(node* t){
    if(t!=NULL){
        if(t->left==NULL&&t->right==NULL){
            cout<<t->data<<" ";
        }
        node_la(t->left);
        node_la(t->right);
    }
}
// tim min, max;
int node_min(node* t){
    if(t->left==NULL)
        return t->data;
    return node_min(t->left);
}
int node_max(node* t){
    if(t->right==NULL)
        return t->data;
    return node_max(t->right);
}
void tim_node_themang(node* &X,node* &Y){
    if(Y->right!=NULL){
        tim_node_themang(X,Y->right);
    }else{
        X->data=Y->data;
        X=Y;
        Y=Y->left;
    }
    /* if(Y!=NULL){
        tim_node_themang(X,Y->left);
    }else{
        X->data=Y->data;
        X=Y;
        Y=Y->right;
    }*/
}
// xoa nut bat ki
void xoa_node_batki(node* &t,int data){
    if(t==NULL){
        return;
    }
    else{
        // xoa nut co 1 con va nut na 
        if(t->data>data){
            xoa_node_batki(t->left,data);
        }
        else if(t->data<data){
            xoa_node_batki(t->right,data);
        }
        // xoa nut co 2 con ==> ta di tim nut the mang 
        else{
            node* X=t;
            if(t->right==NULL){
                t=t->left;
            }
            else if(t->left==NULL){
                t=t->right;
            }else{
                tim_node_themang(X,t->left);
                //tim_node_themang(X,t->right);
            }
            delete X;
        }
    }
}
void menu(node* t){
    while(1){

        cout<<"\n\n\t\t============menu============";
        cout<<"\n1.nhap du lieu";
        cout<<"\n2.duyet cay thep lrn";
        cout<<"\n3.so luong nguytnto ";
        cout<<"\n4.tim kiem ";
        cout<<"\n5.xuat cac node co 2 con ";
        cout<<"\n6.xuat cac node co 1 con ";
        cout<<"\n7.xuat cac nut la ";
        cout<<"\n8.tim min ";
        cout<<"\n9. tim max ";
        cout<<"\n10. xoa 1 node  bat ky ";
        cout<<"\n0.thoat";
        cout<<"\n\n\t\t=============End============";
        int luachon;
        cout<<"\nnhap lua chon: ";
        cin>>luachon;
        if(luachon<0||luachon>10){
            cout<<"\nlua chon ko hop le";
            system("pause");
        }
        else if(luachon==1){
            int x;
            cout<<"\nnhap so nguyen x: ";
            cin>>x;
            khoitaotree(t,x);
        }
        else if(luachon==2){
            cout<<"\n\t\t DUYET CAY THEO LRN ";
            duyet_LRN(t);
            system("pause");
        }else if(luachon==3){
            int dem=0;
            demsl(t,dem);
            cout<<"\n\t\t SO LUONG SO NGUYEN TO "<<dem<<endl;
            system("pause");
        }else if(luachon==4){
            int x;
            cout<<"nhap phan tu can tim kiem: ";
            cin>>x;
            node* p=TimKiem(t,x);
            if(p==NULL)
                cout<<"\nphan tu "<<x<<" khong ton tai trong tree ";
            else 
                cout<<"\nphan tu "<<x<<" co ton tai trong tree ";
            system("pause");
        }else if(luachon==5){
            cout<<"\n\t node co 2 con: ";
            node_2_con(t);
            system("pause");
        }else if(luachon==6){
            cout<<"\n\t node co 1 con: ";
            node_1_con(t);
            system("pause");
        }else if(luachon==7){
            cout<<"\n\t node la: ";
            node_la(t);
            system("pause");
        }else if(luachon==8){
            cout<<"\n\t node min: "<<node_min(t);
            system("pause");
        }else if(luachon==9){
            cout<<"\n\t node max: "<< node_max(t);
            system("pause");
        }else if(luachon==10){
            cout<<"nhap value can xoa: ";
            int x;
            cin>>x;
            xoa_node_batki(t,x);
            system("pause");
        }
        else if(luachon==0){
            break;
        }
    }
}
int main(){
    node* t;
    maketree(t);
    menu(t);
    return 0;
}