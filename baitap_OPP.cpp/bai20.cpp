/*Câu 20: Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp SP1 cho các đối tượng là số phức với các thuộc tính: phần thực, phần ảo.
Xây dựng hàm tạo, phương thức nhập số phức, in số phức, tính module số phức.
2.	Xây dựng lớp SP2 kế thừa từ lớp SP1 và bổ sung:
Nạp chồng các toán tử: = (gán), > (so sánh lớn hơn theo module).
3.	Viết chương trình chính ứng dụng lớp SP2 để nhập một danh sách các đối tượng là các số phức (tối đa 10 phần tử). 
Sắp xếp lại danh sách đã nhập theo trật tự giảm dần của module.*/

#include<bits/stdc++.h>

using namespace std;

class SP1{
    protected:
        float phanthuc,phanao;
    public:
        SP1(){
            this->phanao=this->phanthuc=0;
        }
        SP1(float phanthuc,float phanao){
            this->phanao=phanao;
            this->phanthuc=phanthuc;
        }
        friend istream& operator>>(istream &is,SP1 &sp);
        friend ostream& operator<<(ostream &os,SP1 &sp);
        float module();
};

istream& operator>>(istream &is,SP1 &sp){
    cout<<"IMPORT PHAN THUC: ";is>>sp.phanthuc;
    cout<<"IMPORT PHAN AO: ";is>>sp.phanao;
    return is;
}
ostream& operator<<(ostream& os,SP1 &sp){
    if(sp.phanao==0)
        os<<sp.phanthuc<<endl;
    else if(sp.phanthuc==0)
        os<<sp.phanao<<"i"<<endl;
    else if(sp.phanao<0)
        os<<sp.phanthuc<<sp.phanao<<"i"<<endl;
    else 
        os<<sp.phanthuc<<"+"<<sp.phanao<<"i"<<endl;
        return os;
}
float SP1::module(){
    return sqrt(1.0*pow(this->phanao,2)+1.0*pow(this->phanthuc,2));
}
class SP2:public SP1{
    public:
        SP2 operator=(const SP2&);
        bool operator>(const SP2&);
        void sapxep(SP2 *,int);
        bool operator<(const SP2&);
};
SP2 SP2:: operator=(const SP2 &sp){
    this->phanao=sp.phanao;
    this->phanthuc=sp.phanthuc;
}
bool SP2::operator<(const SP2 &sp){
    return sqrt(1.0*pow(this->phanao,2)+1.0*pow(this->phanthuc,2))<sqrt(1.0*pow(sp.phanao,2)+1.0*pow(sp.phanthuc,2));
}
bool SP2::operator>(const SP2 &sp){
    return sqrt(1.0*pow(this->phanao,2)+1.0*pow(this->phanthuc,2))<sqrt(1.0*pow(sp.phanao,2)+1.0*pow(sp.phanthuc,2));
}
void SP2::sapxep(SP2 *sp,int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(sp[i]<sp[j]){
            SP2 temp=sp[i];
            sp[i]=sp[j];
            sp[j]=temp;
            }
        }
    }
}


int main(){
    int n;
    do{
        cout<<"NHAP SO LUONG SO PHUC: ";cin>>n;
        if(n>10&&n<=0)
            cout<<"nhap lai"<<endl;
    }while(n>10&&n<=0);
    SP2 sp[n];
    for(int i=0;i<n;i++){
        cout<<"NHAP SO PHUC THU "<<i+1<<endl;
        cin>>sp[i];
    }
    cout<<"DANH SACH SAU KHI NHAP"<<endl;
    for(int i=0;i<n;i++){
        cout<<sp[i]<<endl;
    }
    cout<<"DANH SACH SAU KHI SAP XEP GIAM GIAN"<<endl;
    sp->sapxep(sp,n);
    for(int i=0;i<n;i++){
        cout<<sp[i]<<endl;
    }
    return 0;
}
