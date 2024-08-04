#include<iostream>

using namespace std;


void HCN(int n,int m){
    cout<<"Hinh Chu Nhat: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((i>0&&i<n-1)&&(j>0&&j<m-1))
                cout<<"~";
            else
                cout<<"*";
        }
        cout<<"\n";
    }
}
void HTAMGIAC1(int n){
    cout<<"Hinh tam giac1: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            cout<<"*";
        }
        printf("\n");
    }
}
void HTAMGIAC2(int n){
    cout<<"Hinh tam giac2: "<<endl;
    for(int i=n;i>0;i--){
        for(int j=i;j>0;j--){
            cout<<"*";
        }
        printf("\n");
    }
}
void HTAMGIAC3(int n){
    cout<<"Hinh tam giac3: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j>n-1-i)
                cout<<"*";
            else cout<<" ";
        }
        cout<<"\n";
    } 
}

void HTAMGIAC4(int n){
    cout<<"Hinh tam giac 4:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i>j)
                cout<<" ";
            else cout<<"*";
        }
        cout<<"\n";
    }
}
void HTAMGIAC5(int n){
    cout<<"Hinh tam giac 5:"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==i||j==0)
                    cout<<"*";
                else
                    cout<<" ";
            }
            cout<<"\n";
        }
}
void HTAMGIAC6(int n){
    cout<<"Hinh tam giac 5: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    HCN(n,m);
    return 0;
   
}
