#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

typedef struct Node node;
node* makenode(int x){
    node *newnode=new node();
    newnode->data=x;
    newnode->next=NULL;
}

void push(node *&queue,int x){
    node *newnode=makenode(x);
    if(queue==NULL){
        queue=newnode;
        return;
    }
    node *temp=queue;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}
void pop(node *&queue){
    if(queue==NULL)
        return;
    node *temp=queue;
    queue=temp->next;
    delete temp;
}
bool empty(node *queue){
    return queue==NULL;
}
int size(node *queue){
    int cnt=0;
    while(queue!=NULL){
        cnt++;
        queue=queue->next;
    }
    return cnt;
}
int front(node *queue){
    return queue->data;
}
void display(node *queue){
    while(queue!=NULL){
        cout<<queue->data<<" ";
        queue=queue->next;
    }
}
int main(){
    node *queue=NULL;
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
            push(queue,x);
        }else if(lc==2){
            pop(queue);
        }else if(lc==3){
            cout<<size(queue)<<endl;
        }else if(lc==4){
            if(empty(queue))
                cout<<"empty!\n";
            else   
                cout<<"Not empty\n";
        }else if(lc==5){
           cout<< front(queue)<<endl;;
        }else if(lc==6){
            display(queue);
            cout<<endl;
        }else if(lc==0)
            break;
    }
	return 0;
}