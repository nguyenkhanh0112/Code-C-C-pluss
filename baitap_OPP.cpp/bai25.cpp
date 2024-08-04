/*Câu 25: Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp SP1 mô tả các đối tượng là số phức với các thuộc tính: phần thực, phần ảo.
Xây dựng hàm tạo, phương thức nhập số phức, in số phức, tính module số phức
2.	Xây dựng lớp SP2 kế thừa từ lớp SP1 và bổ sung:
Nạp chồng các toán tử: = (gán), < (nhỏ hơn), + (cộng)
3.	Viết chương trình chính ứng dụng lớp SP2 để nhập một danh sách các đối tượng là các số phức (tối đa 10 phần tử). 
Tìm số phức có giá trị nhỏ nhất (theo module) và tính tổng các số phức trong dãy số.*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class SP1{
    protected:
        float phanthuc,phanao;
    public:
        SP1(){
            this->phanao=0;
            this->phanthuc=0;
        }
        SP1(int phanthuc,int phanao){
            this->phanao=phanao;
            this->phanthuc=phanthuc;
        }
        float modulesp();
        friend istream& operator>>(istream& is,SP1 &sp);
        friend ostream& operator<<(ostream& os,SP1 &sp);
};

istream& operator >>(istream &is,SP1 &sp){
    cout<<"IMPORT phanthuc: ";is>>sp.phanthuc;
    cout<<"IMPORT phanao: ";is>>sp.phanao;
    return is;
}
ostream& operator <<(ostream &os,SP1 &sp){
    if(sp.phanao==0)
        os<<sp.phanthuc<<endl;
    else if(sp.phanthuc<0)
        os<<sp.phanthuc<<sp.phanao<<"i"<<endl;
    else 
        os<<sp.phanthuc<<"+"<<sp.phanao<<"i"<<endl;
    return os;
}
float SP1::modulesp(){
    return sqrt(1.0*pow(this->phanthuc,2)+1.0*pow(this->phanao,2));
}
class SP2:public SP1{
    public:
        SP2(){
        this->phanao=0;
        this->phanthuc=0;
        }
        SP2(int phanthuc,int phanao){
        this->phanao=phanao;
        this->phanthuc=phanthuc;
        }
        SP2 operator+(const SP2 &sp);
        void operator=(const SP2 &sp);
        bool operator<(const SP2 &sp);
        bool operator>(const SP2 &sp);
        void seachMIN(SP2*,int);
        void SUM(SP2*,int);
};
void SP2::operator=(const SP2 &sp){
    this->phanthuc=sp.phanthuc;
    this->phanao=sp.phanao;
}
SP2 SP2::operator+(const SP2 &sp){
    SP2 a;
    a.phanthuc=this->phanthuc+sp.phanthuc;
    a.phanao=this->phanao+sp.phanao;
    return a;
}
bool SP2::operator<(const SP2 &sp){
    return sqrt(1.0*pow(this->phanthuc,2)+1.0*pow(this->phanao,2))<sqrt(1.0*pow(sp.phanthuc,2)+1.0*pow(sp.phanao,2));
}
bool SP2::operator>(const SP2 &sp){
    return sqrt(1.0*pow(this->phanthuc,2)+1.0*pow(this->phanao,2))>sqrt(1.0*pow(sp.phanthuc,2)+1.0*pow(sp.phanao,2));
}
void SP2::seachMIN(SP2 *sp,int n){
    SP2 min(99,99);
    int dem;
    for(int i=0;i<n;i++){
        if(min>sp[i]){
            min=sp[i];
            dem=i;
        }
    }
    cout<<min;
}
void SP2::SUM(SP2 *sp,int n){
    SP2 sum;
    for(int i=0;i<n;i++){
        sum=sum+sp[i];
    }
    cout<<sum;
}
int main(){
    int n;
	do{
		cout<<"NHAP SO LUONG PHAN SO: ";
		cin>>n;
		if(n<=0&&n>10)
			cout<<"yeu cau lap lai"<<endl;
	}while(n<=0&&n>10);
    SP2 *sp=new SP2[n];
    cout<<"IMPORT SO PHUC\n";
    cout<<"---------------------\n";
    for(int i=0;i<n;i++){
        cout<<"nhap so phuc thu: "<<i+1<<endl;
        cin>>sp[i];
        cout<<endl;
    }
    cout<<"\nDANH SACH SO PHUC VUA NHAP\n";
    cout<<"------------------------------\n";
    for(int i=0;i<n;i++){
        cout<<sp[i]<<endl;
    }
    cout<<"SO PHUC CO GIA TRI NHO NHAT: ";sp->seachMIN(sp,n);
    cout<<"TONG CAC SO TRONG DANH SACH: ";sp->SUM(sp,n);
    return 0;
}
