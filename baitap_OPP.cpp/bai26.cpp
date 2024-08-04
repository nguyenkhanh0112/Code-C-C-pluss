/*Câu 26: Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp SP1 mô tả các đối tượng là số phức với các thuộc tính: phần thực, phần ảo.
Xây dựng hàm tạo, phương thức nhập số phức, in số phức, tính module số phức
2.	Xây dựng lớp SP2 kế thừa từ lớp SP1 và bổ sung:
Nạp chồng các toán tử: = (gán), > (nhỏ hơn), == (so sánh bằng)
3.	Viết chương trình chính ứng dụng lớp SP2 để nhập một danh sách các đối tượng là các số phức (tối đa 10 phần tử). 
Tìm số phức có giá trị lớn nhất và đếm xem có bao nhiêu số phức trong danh sách có giá trị bằng 3+4i.

Số phức : a+b*i: trong a số thực b là số ảoz1
Module z=sqrt(a*a+b*b)
Z1=a1+b1*i
Z2=a2+b2*i
Z1=z2: a1==a2 và b1==b2
Z1>z2: khi module z1>module z2
*/

#include<bits/stdc++.h>

using namespace std;


class SP1{
    protected:
        int phanthuc,phanao;
    public:
        friend istream& operator>>(istream&is,SP1 &sp);
        friend ostream& operator<<(ostream&os,SP1 &sp);
        float module(SP1);
};

istream& operator>>(istream &is,SP1 &sp){
    cout<<"import phanthuc: ";is>>sp.phanthuc;
    cout<<"import phanao: ";is>>sp.phanao;
    return is;
}
ostream& operator<<(ostream &os,SP1 &sp){
    if(sp.phanao==0)
        os<<sp.phanthuc<<endl;
    else if(sp.phanao<0)
        os<<sp.phanthuc<<sp.phanao<<"i"<<endl;
    else 
        os<<sp.phanthuc<<"+"<<sp.phanao<<"i"<<endl;
        return os;
}
float SP1::module(SP1 sp){
    return sqrt(1.0*pow(sp.phanthuc,2)+1.0*pow(sp.phanao,2));
}
class SP2:public SP1{
    public:
        SP2(){
            this->phanthuc=0;
            this->phanao=1.0;
        }
        SP2(int phanthuc,int phanao){
            this->phanao=1.0*phanao;
            this->phanthuc=1.0*phanthuc;
        }
            void operator=(const SP2 &sp);
            bool operator>(const SP2 &sp);
            bool operator==(const SP2 &sp);
            void MAx(SP2 *,int);
            void giongnhau(SP2 *,int);
};
void SP2::operator=(const SP2 &sp){
    this->phanthuc=1.0*sp.phanthuc;
    this->phanao=1.0*sp.phanao;
}
bool SP2::operator>(const SP2 &sp){
    return sqrt(1.0*pow(this->phanthuc,2)+pow(this->phanao,2))>sqrt(1.0*pow(sp.phanthuc,2)+pow(sp.phanao,2));
}
bool SP2::operator==(const SP2 &sp){
    return ((this->phanthuc==sp.phanthuc)&&(this->phanao==sp.phanao));
}
void SP2::MAx(SP2 *sp,int n){
    SP2 max;
    for(int i=0;i<n;i++){
        if(sp[i]>max)
            max=sp[i];
    }
    cout<<"MAX: "<<max;
}
void SP2::giongnhau(SP2 *sp,int n){
    cout<<"DANH SACH CAC SO GIONG 3+4I: "<<endl;
    SP2 check1(3,4);
    for(int i=0;i<n;i++){
        if(sp[i]==check1){
            cout<<"So phuc thu: "<<i+1<<endl;
            cout<<sp[i];
        }
    }
}
int main(){
    int n;
    do{
        cout<<"nhap n: ";cin>>n;
        if(n<=0&&n>10)
            cout<<"loi nhap lai;"<<endl;
    }while(n<=0&&n>10);
    SP2 *sp=new SP2[n];
    cout<<"------------------------------\n";
    for(int i=0;i<n;i++){
        cout<<"nhap sp thu: "<<i+1<<endl;
        cin>>sp[i];
        cout<<endl;
    }
    cout<<"==>DANH SACH SAU KHI NHAP<==\n";
    for(int i=0;i<n;i++){
        cout<<"so phuc thu: "<<i+1<<endl;
        cout<<sp[i];
    }
    sp->MAx(sp,n);
    sp->giongnhau(sp,n);
    return 0;
}