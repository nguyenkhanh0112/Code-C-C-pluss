/*Câu 23: 
Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp PS1 cho các đối tượng là phân số với các thuộc tính: tử số, mẫu số.
Xây dựng phương thức nhập phân số (mẫu số khác 0), in phân số, tối giản phân số.
2.	Xây dựng lớp PS2 kế thừa từ lớp PS1 và bổ sung:
Nạp chồng các toán tử: = (gán), < (nhỏ hơn), + (cộng).
3.	Viết chương trình chính ứng dụng lớp PS2 để nhập một danh sách các đối tượng là các phân số (tối đa 10 phần tử). 
Tìm phân số có giá trị lớn nhất, tính tổng các phân số trong danh sách có giá trị nhỏ hơn 1/2.
*/

#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>

using namespace std;

class PS1{
    protected:
        int tuso,mauso;
    public:
        PS1(){
            this->mauso=1;
            this->tuso=0;
        }
        PS1(int tuso,int mauso){
            this->mauso=1.0*mauso;
            this->tuso=1.0*tuso;
        }
        friend istream& operator>>(istream &is,PS1 &ps);
        friend ostream& operator<<(ostream &os,PS1 &ps);
        PS1 rutgon(PS1&);
};

istream& operator>>(istream &is, PS1 &ps){
    cout<<"IMPORT tuso: ";is>>ps.tuso;
    cout<<"IMPORT mauso: ";is>>ps.mauso;
    return is;
}
ostream& operator<<(ostream &os,PS1 &ps){
    if(ps.mauso==1)
        cout<<ps.tuso<<endl;
    else 
        cout<<ps.tuso<<"/"<<ps.mauso<<"\n";
    return os;
}
int gcd(int a,int b){
    a=abs(a);
    b=abs(b);
    if(a==0||b==0)
        return a+b;
    return gcd(b,a%b);
}
PS1 PS1::rutgon(PS1 &ps){
    int x=gcd(ps.tuso,ps.mauso);
    ps.mauso/=x;
    ps.tuso/=x;
    return ps;
}
class PS2 : public PS1{
    public:
     PS2(){
        this->mauso=1;
        this->tuso=0;
    }
    PS2(int tuso,int mauso){
        this->mauso=1.0*mauso;
        this->tuso=1.0*tuso;
    }
        void operator=(const PS2 &ps);
        PS2 operator+(const PS2 &ps);
        bool operator<(const PS2 &ps);
        void MAX(PS2 *,int);
        PS2 sumnhohon1phan2(PS2*,int);
};
void PS2::operator=(const PS2 &ps){
    this->mauso=1.0*ps.mauso;
    this->tuso=1.0*ps.tuso;
}
PS2 PS2::operator+(const PS2 &ps){
    PS2 sum;
    sum.tuso=1.0*this->tuso*ps.mauso+this->mauso*ps.tuso;
    sum.mauso=1.0*this->mauso*ps.mauso;
    return sum;
}
bool PS2::operator<(const PS2 &ps){
    return (1.0*this->tuso/this->mauso)<(1.0*ps.tuso/ps.mauso);
}
void PS2::MAX(PS2 *ps,int n){
    PS2 max;
    int dem;
    for(int i=0;i<n;i++){
        if(max<ps[i]){
            max=ps[i];
        }
    }
    cout<<max;
}
PS2 PS2::sumnhohon1phan2(PS2 *ps,int n){
    PS2 sum;
    PS2 x(1,2);
    for(int i=0;i<n;i++){
        if(ps[i]<x)
            sum = sum + ps[i];
    }
    cout<<sum;
    return sum;
} 
int main(){
    int n;
    do{
        cout<<"NHAP SO LUONG PHAN SO: ";cin>>n;
        if(n>10&&n<=0)
            cout<<"nhap lai dieu kien n>10&&n<=0"<<endl;
    }while(n>10&&n<=0);
    PS2 *ps=new PS2[n];
    cout<<"NHAP PHAN SO:"<<endl;
    cout<<"-----------------------\n";
    for(int i=0;i<n;i++){
        cout<<"nhap phan so thu "<<i+1<<endl;
        cin>>ps[i];
    }
    cout<<"--------------------"<<endl;
    cout<<"DANH SACH PHAN SO VUA NHAP: "<<endl;
    for(int i=0;i<n;i++){
        cout<<ps[i];
    }
    cout<<"DANH SACH SAU KHI RUT GON: "<<endl;
    for(int i=0;i<n;i++){
        ps[i].rutgon(ps[i]);
    }
    for(int i=0;i<n;i++){
        cout<<ps[i];
    }
    cout<<"PHAN TU LON NHAT TRONG DANH SACH: ";ps->MAX(ps,n);
    cout<<"Tong phan tu nho hon 1/2: ";ps->sumnhohon1phan2(ps,n);
    return 0;
}