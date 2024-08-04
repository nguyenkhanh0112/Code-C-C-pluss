/*Câu 21: Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp SP1 cho các đối tượng là số phức với các thuộc tính: phần thực, phần ảo.
Xây dựng hàm tạo, phương thức nhập số phức, in số phức, tính module số phức.
2.	Xây dựng lớp SP2 kế thừa từ lớp SP1 và bổ sung:
Nạp chồng các toán tử: = (gán), < (so sánh nhỏ hơn theo module).
3.	Viết chương trình chính ứng dụng lớp SP2 để nhập một danh sách các đối tượng là các số phức (tối đa 10 phần tử).
     Sắp xếp lại danh sách đã nhập theo trật tự tăng dần của module.
*/

#include<iostream>
#include<iomanip>
#include<math.h>

using namespace std;

class SP1{
    protected:
        double thuc;
        double ao;
    public:
        SP1(){
            thuc=0;
            ao=0;
        }
        SP1(double thuc,double ao){
            this->thuc=thuc;
            this->ao=ao;
        }
       void nhapsophuc(SP1&);
       void xuatsophuc(SP1);
       double module();
};

class SP2:public SP1{
    public:
        void operator=(const SP2 &);
        bool operator<(SP2 &);
};

void SP1::nhapsophuc(SP1 &sp){
    cout<<"nhap phan thuc: "; cin >> sp.thuc;
    cout<<"nhap phan ao: "; cin >> sp.ao;
}

void SP1::xuatsophuc(SP1 sp){
    cout<<"So phuc la: ";
    if(this->ao==0)
        cout<< sp.thuc << " "<< endl;
    else if(this->ao<0)
        cout<<sp.thuc<<" "<<sp.ao<<"i"<<endl;
    else 
        cout<<sp.thuc<<"+"<<sp.ao<<"i"<<endl;
}

double SP1::module(){
        double sp;
        sp=sqrt(pow(this->thuc,2)+pow(this->ao,2));
    return sp;
}

void SP2::operator=(const SP2 &temp){
    this->thuc=temp.thuc;
    this->ao=temp.thuc;
}

bool SP2::operator<(SP2 &temp){
    return module()<temp.module();
}

void Nhapdssophuc(SP2 sophuc[],int n){
    for(int i=0;i<n;i++){
        cout<<"\nnhap so phuc thu: "<<i+1<<endl;
        sophuc[i].nhapsophuc(sophuc[i]);
    }
}

void xuatdssophuc(SP2 sophuc[],int n){
    for(int i=0;i<n;i++){
        cout<<"so phuc thu: "<<i+1<<endl;
        sophuc[i].xuatsophuc(sophuc[i]);
    }
}

void sapxep(SP2 sophuc[],int n){
    SP2 temp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(sophuc[i].module()>sophuc[j].module()){
                temp =sophuc[i];
                sophuc[i]=sophuc[j];
                sophuc[j]=temp;
            }
        }
    }
}

int main(){
    int n;
    do{
        cout<<"nhap so luong so phuc: ";
        cin>>n;
        if(n>10&&n<0)
            cout<<"\nnhap lai!";
    }while(n<0 or n>10);
    SP1 sophuc1[n];
    SP2 sophuc[n];
    Nhapdssophuc(sophuc,n);
    sapxep(sophuc,n);
    cout<<"so phuc sau khi dc sap xep ";
    xuatdssophuc(sophuc,n);

    return 0;
}