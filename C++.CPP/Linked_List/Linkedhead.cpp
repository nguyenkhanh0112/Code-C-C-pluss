#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *makenode(int x){
    Node *temp=new Node();
    temp->data=x;
    temp->next=NULL;
    return temp;
}

void AddHead(Node *&head,int x){
    Node *newnode=makenode(x);
    if(head==NULL){
        head=newnode;
    }
    else {
        newnode->next=head;
        head=newnode;
    }
}
void AddTail(Node *&head,int x){
     Node *newnode=makenode(x);
     if(head==NULL){
        head=newnode;
        return ;
    }
    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    temp=newnode;
}
int  size(Node *head){
    int dem=0;
    while(head!=NULL){
        dem++;
        head=head->next;
    }
    return dem;
}
void trenvaogiua(Node *&head,int x,int pos){
    Node *newnode= makenode(x);
    int n=size(head);
    if(pos<1&&pos>n+1){
        cout<<"\nloi lap lai";
        return ;
    }
    if(pos==1){
        AddHead(head,x);
        return ;
    }else if(pos==n){
        AddTail(head,x);
        return ;
    }
    Node *temp=head;
    for(int i=1;i<=pos-2;i++){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
void duyet(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
void popFront(Node *&head){
    if(head==NULL)
        return;
    Node *temp=head;
    head=head->next;
    delete temp;
}
void popBack(Node *&head){
    if(head==NULL)
        return ;
    Node *temp=head;
    if(temp->next==NULL){
        head=NULL;
        delete temp;
        return ;
    }
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    Node *last = temp->next;
    temp->next=NULL;
    delete last;
}
void xoanodegiua(Node *&head,int k){
    int n=size(head);
    if(k<1||k>n)
        return ;
    if(k==1){
        popFront(head);
    }else{
        Node *temp=head;
        for(int i=1;i<=k-2;i++){
            temp=temp->next;
        }
        Node *nodek=temp->next;
        temp->next=nodek->next;
        delete nodek;
    }
}
void sapxep(Node *&head){
    for(Node *i=head;i!=NULL;i=i->next){
        Node *minnode=i;
        for(Node *j=i->next;j!=NULL;j=j->next){
            if(minnode->data>j->data){
                minnode=j;
            }
        }
        int temp=minnode->data;
        minnode->data=i->data;
        i->data=temp;
    }
}
int main(){   
    Node *head=NULL;
    while(1){
        cout<<"\n1.them vao dau ";
        cout<<"\n2.them vao cuoi ";
        cout<<"\n3.them vao giua ";
        cout<<"\n4.xoa node khoi dau DSLK ";
        cout<<"\n5.xoa node khoi cuoi DSLK ";
        cout<<"\n6.xoa node o giua danh sach ";
        cout<<"\n7.sap xep ";
        cout<<"\n8.duyet ";
        cout<<"\n0.thoat ";
        cout<<"\n-------------------------\n";
        int lc;
        cout<<"\nnhap lc: ";
        cin>>lc;
        cout<<"\n-------------------------\n";
        if(lc==1){
            int x;cin>>x;
            AddHead(head,x);
        }else if(lc==2){
            int x;cin>>x;
            AddTail(head,x);
        }else if(lc==3){
            int x,pos;
            cin>>x>>pos;
            trenvaogiua(head,x,pos);
        }
        else if(lc==4){
            int x;cin>>x;
            popFront(head);
        }else if(lc==5){
            int x;cin>>x;
            popBack(head);
        }else if(lc==6){
            int k;
            cout<<"\nnhap vi tri can xoa: ";
            cin>>k;
            xoanodegiua(head,k);
        }else if(lc==7){
            sapxep(head);
        }else if(lc==8){
            duyet(head);
        }
        else 
            break;
    }
    return 0;
}