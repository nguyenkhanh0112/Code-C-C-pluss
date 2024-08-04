#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};
struct list{
    Node *head;
    Node *tail;
};

void khoitaostruct(list *l){
    l->head=NULL;
    l->tail=NULL;
}
Node* makenode(int x){
    Node *newnode=new Node;
    newnode->data=x;
    newnode->next=NULL;
}
void AddHead(list *l,Node *p){
    if(l->head==NULL){
        l->head=p;
        l->tail=p;
    }else{
        p->next=l->head;
        l->head=p;
    }
}
void AddTail(list *l,Node *p){
    if(l->head==NULL){
        l->head=p;
        l->tail=p;
    }else{
       l->tail->next=p;
       l->tail=p;
    }
}
void AddTail(list *l,Node *p,Node *q){
    Node *k =l->head;
    while(k!=NULL){
        if(k->data==p->data){
            q->next=k->next;
            k->next=p;
        }
        k=k->next;
    }
}
void duyet(Node *p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
}
int main(){
    list *l;
    khoitaostruct(l);
    Node *p;
    for(int i=1;i<=10;i++){
        p=makenode(i);
        AddTail(l,p);
    }
    duyet(p);
}