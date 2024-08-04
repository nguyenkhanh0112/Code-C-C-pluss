/*Câu 29: Khởi động C++, tạo tập tin có tên D:\Bai1.CPP, 
sau đó viết chương trình thực hiện yêu cầu: Xây dựng lớp ps (phân số) có các thành phần:
   - Các thuộc tính: tu, mau.
   - Hàm tạo để thiết lập giá trị ban đầu cho các thuộc tính.
   - Hàm nhap để nhập dữ liệu vào cho 2 dữ liệu thuộc tính.
   - Hàm hienthi để in kết quả của 2 thuộc tính lên màn hình.
   - Quá tải các toán tử ==, >  để so sánh 2 phân số, + để cộng hai phân số.
   Sau đó xử lý thực hiện các công việc :
   a) Nhập n phân số từ bàn phím.
   b) In ra màn hình n phân số vừa nhập.
   c) In ra màn hình tổng của n phân số đã nhập (sau khi rút gọn phân số tổng).
   d) In ra màn hình phân số có giá trị lớn nhất.
   e) Nhập một phân số từ bàn phím và tìm xem phân số đó đã có trong n phân số đã nhập ở trên không ?
*/
#include<iostream>
#include<bits/stdc++.h>
#include<iomanip>

using namespace std;

class PS{
    private:
        int tu,mau;
    public:
        PS(){
            this->tu=0;
            this->mau=1;
        }
        PS(int tu,int mau){
            this->tu=tu;
            this->mau=mau;
        }
        friend istream& operator>>(istream &is,PS &ps);
        friend ostream& operator<<(ostream &os,PS &ps);
        bool operator>(const PS &ps);
        PS operator+(const PS &ps);
        void MAX(PS *,int);
        void timkiem(PS *,int);
        PS rutgon(PS&);
        void operator=(const PS &ps);
        bool operator==(const PS &ps);
        PS tongnps(PS *,int );

};
istream& operator>>(istream &is,PS &ps){
    cout<<"nhap tu so: ";is>>ps.tu;
    cout<<"nhap mau so: ";is>>ps.mau;
    return is;
}
ostream& operator<<(ostream &os,PS &ps){
    if(ps.tu==0)
        os<<0<<endl;
    else if(ps.mau==1)
        os<<ps.tu<<endl;
    else 
        os<<ps.tu<<"/"<<ps.mau<<endl;
    return os;
}
bool PS::operator>(const PS &ps){
    return (1.0*this->tu/this->mau)>(1.0*ps.tu/ps.mau);
}
void PS::operator=(const PS &ps){
    this->mau=ps.mau;
    this->tu=ps.tu;
}
bool PS::operator==(const PS &ps){
    return ((this->mau==ps.mau)&&(this->tu==ps.tu));
}
PS PS::operator+(const PS &ps){
    PS sum;
    sum.tu=(this->tu*ps.mau)+(ps.tu*this->mau);
    sum.mau=this->mau*ps.mau;
    return sum;
}
int gcd(int a,int b){
    a=abs(a);
    b=abs(b);
    if(a==0||b==0)
        return a+b;
    return gcd(b,a%b);
}
PS PS::rutgon(PS &ps){
    int x=gcd(ps.tu,ps.mau);
    ps.tu/=x;
    ps.mau/=x;
    return ps;
}
void rutgonnps(PS *ps,int n){
    cout<<"DANH SACH PHAN SO SAU KHI RUT GON\n";
    for(int i=0;i<n;i++){
        ps[i].rutgon(ps[i]);
    }
}
void nhapnps(PS *ps,int n){
    for(int i=0;i<n;i++){
        cout<<"PHAN SO THU: "<<i+1<<endl;
        cin>>ps[i];
    }
}
void xuatnps(PS *ps,int n){
    for(int i=0;i<n;i++){
        cout<<ps[i];
    }
}
void PS::MAX(PS *ps,int n){
    PS max;
    for(int i=0;i<n;i++){
        if(max>ps[i]){
            max=ps[i];
        }
    }
    cout<<"PHAN SO MAX: ";
    cout<<max.tu<<"/"<<max.mau<<endl;
}
void PS::timkiem(PS *ps,int n){
    PS x;
    cout<<"NHAP PHAN SO CAN TIM KIEM \n";
    cin>>x;
    for(int i=0;i<n;i++){
        if(x==ps[i]){
            cout<<ps[i];
            break;
        }
    }
    cout<<"KO CO PHAN SO TRONG MANG TREN\n";
}
PS PS::tongnps(PS *ps,int n){
    PS SUM;
    for(int i=0;i<n;i++){
        SUM=SUM+ps[i];
    }
    cout<<"TONG CAC PHAN SO: ";
    cout<<SUM<<endl;
    return SUM;
}
int main(){
    int n;
    cout<<"NHAP SO LUONG PHAN TU : ";
    cin>>n;
    PS *ps=new PS[n];
    nhapnps(ps,n);
    cout<<"\n==>> DANH SACH PHAN SO VUA NHAP <<==\n";
    xuatnps(ps,n);
    rutgonnps(ps,n);
    xuatnps(ps,n);
    ps->tongnps(ps,n);
    ps->timkiem(ps,n);
    return 0;
}