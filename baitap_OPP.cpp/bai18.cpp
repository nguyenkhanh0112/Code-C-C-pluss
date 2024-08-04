/*Câu 18: Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp PS1 cho các đối tượng là phân số với các thuộc tính: tử số, mẫu số.
Xây dựng phương thức nhập phân số (mẫu số khác 0), in phân số, tối giản phân số.
2.	Xây dựng lớp PS2 kế thừa từ lớp PS1 và bổ sung:
Nạp chồng các toán tử: = (gán), > (lớn hơn).
3.	Viết chương trình chính ứng dụng lớp PS2 để nhập một danh sách các đối tượng là phân số (tối đa 10 phần tử). 
Sắp xếp lại danh sách đã nhập theo trật tự giảm dần.
*/

#include<iostream>
#include<bits/stdc++.h>
#include<math.h>


using namespace std;

class PS1{
    protected:
        int tuso,mauso;
    public:
        PS1(){
            this->mauso=1;
            this->tuso=0;
        }
        PS1(float tuso,float mauso){
            this->tuso=tuso;
            this->mauso=mauso;
        }
    void importPhanSo(PS1&);
    void exportPhanSo(PS1);
    PS1 rutgonPS(PS1&);
};

void PS1::importPhanSo(PS1 &ps){
    cout<<"import tu so: ";cin>>ps.tuso;
    cout<<"import mau so: ";cin>>ps.mauso;
}
void PS1::exportPhanSo(PS1 ps){
    if(ps.mauso==1)
        cout << ps.tuso<<endl;
    else 
        cout << ps.tuso <<"/"<<ps.mauso<<endl;
}
int gcd(int a,int b){
    a=abs(a);
    b=abs(b);
    if(a==0||b==0)
        return a+b;
    return gcd(b,a%b);
}
PS1 PS1::rutgonPS(PS1 &ps){
    int x=gcd(ps.tuso,ps.mauso);
        ps.tuso/=x;
        ps.mauso/=x;
    return ps;
}
class PS2:public PS1{
    public:
        void sapxep(PS2 ps[],int n);
        bool operator>(const PS2&);
        PS2 operator=(const PS2&);
        void InDanhSachPhanSoDaSapXep(PS2 [], int );
};
PS2 PS2::operator=(const PS2 &ps){
    this->mauso=ps.mauso;
    this->tuso=ps.tuso;
}
bool PS2::operator>(const PS2 &ps){
    return (1.0*this->tuso/this->mauso)>(1.0*ps.tuso/ps.mauso);
}
void PS2::sapxep(PS2 ps[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(ps[i]>ps[j]){
             PS2 temp=ps[i];
                ps[i]=ps[j];
                ps[j]=temp;
            }
        }
    }
}
void PS2::InDanhSachPhanSoDaSapXep(PS2 ps[], int n) {
    cout << "\n===> DANH SACH PHAN SO DA DUOC SAP XEP <===" << endl;
    for(int i = 0; i < n; i++) {
        cout << "\tPhan so " << i + 1 << ":  ";
        ps[i].exportPhanSo(ps[i]);
    }
}
int main(){
    int n;
    do{
        cout<<"IMPORT SO LUONG PHAN SO: ";cin>>n;
        if(n<=0&&n>10)
            cout<<"ERROR,SO LUONG TOI DA DC 10 PHAN SO XIN VUI LONG NHAP LAI,CAM ON!\n";
    }while(n<=0&&n>10);
    PS2 ps[n];
    cout<<"--------------------------------\n";
    cout<<"IMPORT PHAN SO \n";
    for(int i=0;i<n;i++){
        cout<<"PHAN SO THU: "<<i+1<<endl;
        ps[i].importPhanSo(ps[i]);
    }
            cout<<"DANH SACH PHAN SO VUA NHAP"<<endl;
    for(int i=0;i<n;i++){
        ps[i].exportPhanSo(ps[i]);
    }
    for(int i=0;i<n;i++){
        ps[i].rutgonPS(ps[i]);
    }
    cout<<"DANH SACH PHAN SO SAU GHI RUT GON\n";
    for(int i=0;i<n;i++){
        ps[i].exportPhanSo(ps[i]);
    }
    ps->sapxep(ps,n);
    ps->InDanhSachPhanSoDaSapXep(ps,n);
    return 0;
}