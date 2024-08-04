/*Câu 19: Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp PS1 cho các đối tượng là phân số với các thuộc tính: tử số, mẫu số.
Xây dựng phương thức nhập phân số (mẫu số khác 0), in phân số, tối giản phân số.
2.	Xây dựng lớp PS2 kế thừa từ lớp PS1 và bổ sung:
Nạp chồng các toán tử: = (gán), < (nhỏ hơn).
3.	Viết chương trình chính ứng dụng lớp PS2 để nhập một danh sách các đối tượng là các phân số (tối đa 10 phần tử). 
Tìm phân số có giá trị lớn nhất, nhỏ nhất.*/


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class PS1{
    protected:
        int tuso,mauso;
    public:
        PS1(){
            this->tuso=0;
            this->mauso=1;
        }
        PS2(int tuso,int mauso){
            this->tuso=tuso;
            this->mauso=mauso;
        }
        void importps(PS1 &);
        void exportps(PS1);
        PS1 rutgon(PS1&);
};

void PS1::importps(PS1 &ps){
    cout<<"import tu so: ";cin>>ps.tuso;
    cout<<"import mau so: ";cin>>ps.mauso;
}
void PS1::exportps(PS1 ps){
    if(ps.mauso==1)
        cout << ps.tuso<<" "<<endl;
    else 
        cout << ps.tuso <<"/"<<ps.mauso<<endl;
}
int gcd(int a,int b){
    if(a==0||b==0)
        return a+b;
    return gcd(b,a%b);
}
PS1 PS1::rutgon(PS1 &ps){
    int x=gcd(ps.tuso,ps.mauso);
    ps.tuso/=x;
    ps.mauso/=x;
    return ps;
}
class PS2 :public PS1{
    public:
        void operator=(const PS2&);
        bool operator<(const PS2&);
        void psmax(PS2 [],int);
        void psmin(PS2 [],int);
        bool operator>(const PS2 &ps);
};
void PS2::operator=(const PS2 &ps){
    this->tuso=ps.tuso;
    this->mauso=ps.mauso;
}
bool PS2::operator<(const PS2 &ps){
    return (1.0*this->tuso/this->mauso)<(1.0*ps.tuso/ps.mauso);
}
bool PS2::operator>(const PS2 &ps){
    return (1.0*this->tuso/this->mauso)>(1.0*ps.tuso/ps.mauso);
}
void PS2::psmax(PS2 ps[],int n){
    float max=-1e9;
    int count;
    for(int i=0;i<n;i++){
        float ans=(ps[i].tuso/ps[i].mauso);
        if(ans>max){
            max=ans;
            count=i;
        }
    }
     ps[count].exportps(ps[count]);
}
void PS2::psmin(PS2 ps[],int n){
    float min=1e9;
    int dem;
    for(int i=0;i<n;i++){
        float ans=(ps[i].tuso/ps[i].mauso);
        if(min>ans){
        min=ans;
        dem=i;
        }
    }
    ps[dem].exportps(ps[dem]);
}
int main(){
    int n;
    do{
        cout<<"IMPORT SO LUONG PHAN SO: ";cin>>n;
        if(n<=0&&n>10)
            cout<<"ERROR,SO LUONG TOI DA DC 10 PHAN SO XIN VUI LONG NHAP LAI,CAM ON!\n";
    }while(n<=0&&n>10);
    PS2 ps[n];
    for(int i=0;i<n;i++){
        cout<<"PHAN SO THU: "<<i+1<<endl;
        ps[i].importps(ps[i]);
    }
        cout<<"DANH SACH PHAN SO VUA NHAP"<<endl;
    for(int i=0;i<n;i++){
        ps[i].exportps(ps[i]);
    }
    for(int i=0;i<n;i++){
        ps[i].rutgon(ps[i]);
    }
    cout<<"DANH SACH PHAN SO SAU GHI RUT GON\n";
    for(int i=0;i<n;i++){
        ps[i].exportps(ps[i]);
    }
    cout<<"MAX MIN TRONG PS: ";
    ps->psmax(ps,n);
    ps->psmin(ps,n);
    return 0;
}