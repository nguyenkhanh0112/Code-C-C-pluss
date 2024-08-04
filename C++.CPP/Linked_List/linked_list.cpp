#include<iostream>
#include<bits/stdc++.h>

using namespace std;
// nhap danh sach lien ket don cac so nguyen.
//tim gia chi lon nhat trong danh sach lien ket don 

//khai bao cau truc danh sach lien ket don 

struct node{
    int data;
    node *Next;
};

struct list1{
    node *Head;// node quan li dau danh sach
    node *Tail;// quan li cuoi danh sach
};
void khoitao(list1 &l){
    l.Head=NULL;
    l.Tail=NULL;
}
// ham khoi tao 1 cai node 
node *khoitaonode(int x){
    node *p=new node();// cap phat vung nho cho node p
    if(p==NULL){
        cout<<"\nkhong du bo nho de cap phat !"<<endl;
        return NULL;
    }
    p->data=x;// truyen gia tri x vao cho data
    p->Next=NULL;
    return p;// tra ve node p vua khoi tao 
}
// ham them node vao linked list
void themvaodau(list1 &l,node *p){
// danh sach dang rong
    if(l.Head==NULL)
        l.Head=l.Tail=p;
    else{
        p->Next=l.Head;
        l.Head=p;
    }
}
// ham them node vao cuoi danh sach
void themvaocuoi(list1 &l,node *p){
    // danh sach rong 
    if(l.Head==NULL)
        l.Head=l.Tail=p;
    else{
        l.Tail->Next=p;
        l.Tail=p;
    }
}
// ham xuat danh sach linked list
void xuatdanhsach(list1 l){
    // while(l.Head!=NULL){
    //     cout<<l.Head->data<<" ";
    //     l.Head=l.Head->Next;
    // }
    for(node *k=l.Head;k!=NULL;k=k->Next){
        cout<<k->data<<" ";
    }
}
// ham tim gia tri lon nhat trong danh sach
int timmax(list1 l){
    int max=l.Head->data;
    for(node *k=l.Head->Next;k!=NULL;k=k->Next){
        if(max<k->data){
            max=k->data;
        }
    }
    return max;
}
// them 1 node p vao sau node q
void themnode_p_vaosaunodeq(list1 &l,node *p){
    int x;
    cout<<"\nnhap gia tri node q: ";
    cin>>x;
    node *q=khoitaonode(x);
    if(q->data==l.Head->data&&l.Head->Next==NULL){
        themvaocuoi(l,p);
    }
    node *k=l.Head;
    while(k!=NULL){
        if(k->data==q->data){
            node *h=khoitaonode(p->data);
            node *g=k->Next;
            //p->Next=g;
            h->Next=g;
            k->Next=h;
            //return;
        }
        k=k->Next;
    }
}
// xoa node dau danh sach
void xoadau(list1 &l){
    //neu danh sach rong
    if(l.Head==NULL){
        return;
    }
    node *p=l.Head;//node se xoa;
    l.Head=l.Head->Next;
    delete p;
}
// xoa node cuoi danh sach 
void xoacuoi(list1 &l){
    //neu danh sach rong 
    if(l.Head==NULL){
        return ;
    }
    if(l.Head->Next==NULL){
        xoadau(l);
        return ;
    }
    //duyet tu dau danh sach den thang ke cuoi 
    node *k=l.Head;
    while(k!=NULL){
        if(k->Next==l.Tail){
            delete l.Tail;
            k->Next=NULL;
            l.Tail=k;
        }
        k=k->Next;
    }
    node *p=l.Tail;
}
// xoa 1 node nam sau node q trong danh sach lien ket 
void xoanodenamsaunode(list1 &l,node *q){
    node *k=l.Head;
    while(k!=NULL){
        if(k->data==q->data){
            node *g=k->Next;
            k->Next=g->Next;
            delete g;
            return;
        }
        k=k->Next;
    }
}
// ham xoa 1 cai node co khoa k bat ki
void xoanodecokhoak(list1 &l,int x){
    // neu danh sach rong
    if(l.Head==NULL){
        return;
    }
    // neu node can xoa nam dau danh sach
    if(l.Head->data==x){
        xoadau(l);
        return;
    }
    // neu node cna xoa nam o cuoi danh sach
    if(l.Tail->data==x){
        xoacuoi(l);
        return;
    }
    //duyet danh sach lien ket don tim
    node *k=l.Head;
    node *g;
    while(k!=NULL){
        if(k->data==x){
            g->Next=k->Next;
            delete k;
            return;
        }
        g=k;
        k=k->Next;
    }
}
void gia_phong_danh_sach(list1 &l){
    
    while(l.Head!=NULL){
        node *k=l.Head;
        l.Head=l.Head->Next;
        delete k;
    }
}
//menu
void menu(list1 &l){
    int luachon;
    while(1){
        
        cout<<"\n\n\t\t==============menu=============";
        cout<<"\n\t1. them node vao dau danh sach";
        cout<<"\n\t2. them node vao cuoi danh sach";
        cout<<"\n\t3. xuat danh sach lien ket don";
        cout<<"\n\t4. them node p vao sau node q trong danh sach";
        cout<<"\n\t5. xoa node dau danh sach";
        cout<<"\n\t6. xoa node cuoi danh sach";
        cout<<"\n\t7. xoa node nam sau node q";
        cout<<"\n\t8. xoa node co khoa k bat ki";
        cout<<"\n\t0. thoat";
        cout<<"\n\n\t\t==============End==============";
        cout<<"\nnhap lua chon: ";
        cin>>luachon;
        if(luachon < 0||luachon > 8){
            cout<<"\nlua chon khong hop le. in kiem tra lai!";
            system("pause");/// dung man hinh
        }
        else if(luachon==1){
            int x;
            cout<<"\nnhap gia tri so nguyen: ";
            cin>>x;
            node *p=khoitaonode(x);
            themvaodau(l,p);
        }
        else if(luachon==2){
            int x;
            cout<<"\nnhap gia tri so nguyen: ";
            cin>>x;
            node *p=khoitaonode(x);
            themvaocuoi(l,p);
        }
        else if(luachon==3){
            xuatdanhsach(l);
        }
        else if(luachon==4){
            int x;
            cout<<"\nnhap gia tri node p can them vao sau: ";
            cin>>x;
            node *p=khoitaonode(x);
            themnode_p_vaosaunodeq(l,p);
        }
        else if(luachon==5){
            xoadau(l);
        }
        else if(luachon==6){
            xoacuoi(l);
        }
        else if(luachon==7){
            int x;
            cout<<"\nnhap gia tri node p: ";
            cin>>x;
            node *q=khoitaonode(x);
            xoanodenamsaunode(l,q);
        }
        else if(luachon==8){
            int x;
            cout<<"\nnhap node can xoa: ";
            cin>>x;
            xoanodecokhoak(l,x);
        }
        else{
            break;
        }
    }
}
int main(){
    list1 l;
    khoitao(l);//khoi tao danh sach lien ket don
    menu(l);
    cout<<"\nGIA TRI MAX: "<<timmax(l)<<endl;
    return 0;
}