#include<iostream>

using namespace std;

class A{
    public:
        virtual void xuat(){// phuong thuc ao
            cout<<"Ai keu toi day.co A day !!!!";
        }
        virtual void tinh_toan()=0;// phuong thuc thuan ao 
};



class B :public A{
    public:
        void xuat(){
            cout<<"Ai keu toi day.co B day !!!!";
        }
        void tinh_toan(){
            cout<<"da tinh xong !!!";
        }
};



class C:public A{
    public:
        void xuat(){
            cout<<"Ai keu toi day.co C day !!!!";
        }
};

int main(){
    A *x = new C;
    x->tinh_toan();
    return 0;
}