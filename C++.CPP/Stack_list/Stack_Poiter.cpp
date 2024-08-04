#include<iostream>

using namespace std;

struct node{
    int data;
    struct node *next;
};

node *makeNode(int x){
    node *newnode  = new node();
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}
void push(node *&top,int x){
    node *newnode=makeNode(x);
    if(top==NULL){
        top=newnode;
        return;
    }
    newnode->next=top;
    top=newnode;

}
void pop(node *&top){
    if(top!=NULL){
        node *temp=top;
        top=temp->next;
        delete temp;
    }
}
void top(node *top){
    if(top!=NULL){
        cout<<top->data<<endl;
    }
}
int size(node *top){
    int cnt=0;
    while(top!=NULL){
        cnt++;
        top=top->next;
    }
    return cnt;
}
void display(node *top){
    node *temp=top;
    if(top==NULL){
        return;
    }
    while(temp!=NULL){
        cout<<temp->data;
            if(temp!=NULL)
                cout<<"->";
        temp=temp->next;
    }
}
int main(){
    node *st=NULL;
    while(1){
        cout<<"\n-------------------\n";
        cout<<"1.push\n";
        cout<<"2.pop\n";
        cout<<"3.top\n";
        cout<<"4.size\n";
        cout<<"5.duyet\n";
        cout<<"0.thoat\n";
        cout<<"-------------------\n";
        cout<<"nhap lc: ";int lc;
        cin>>lc;
        if(lc==1){
			int x;cout<<"nhap x: ";cin>>x;
			push(st, x);
		}
		else if(lc==2){
			pop(st);
		}else if(lc==3){
			if(st==NULL)
			    cout<<"EMPTY\n";
            else
			    top(st);
		}else if(lc==4){
			cout<< size(st) <<endl;
		}else if(lc==5){
            display(st);
        }
        else
			break;
	}
	return 0;
}