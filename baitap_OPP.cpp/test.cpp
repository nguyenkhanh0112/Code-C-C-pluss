/*
1.	Khai báo lớp ma trận với các thuộc tính: số hàng, số cột, các phần tử của ma trận.
2.	Xây dựng các phương thức: nhập, xuất một đối tượng ma trận.
3.	Nhập vào hai ma trận đồng cấp. Thực hiện cộng hai ma trận vừa nhập (dùng hàm bạn). In ra màn hình hai ma trận ban đầu và ma trận kết quả.
3.	Nhập vào 1 ma trận. 
In ra màn hình ma trận vừa nhập. 
Tính tổng các phần tử nằm trên 4 đường viền của ma trận.

Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp đa thức với các thuộc tính: bậc đa thức, các hệ số tương ứng.
2.	Xây dựng các phương thức: nhập, xuất một đối tượng đa thức.
3.	Định nghĩa toán tử +, - hai đa thức. Thực hiện cộng, trừ hai đa thức và in kết quả ra màn hình.

*/
#include<iostream>
#include<iomanip>
#include<math.h>

using namespace std;

class DaThuc{
    private:
        int n;
        int *heso;
    public:
        DaThuc(){
            this->n=0;
            this->heso=NULL;
        }
        DaThuc(int n){
            this->n=n;
            this->heso=new int[n];
        }
        friend istream& operator>>(istream& is, DaThuc &dt);
        friend ostream& operator<<(ostream& os, DaThuc &dt);
        DaThuc operator+(const DaThuc &dt);
        DaThuc operator-(const DaThuc &dt);
};

istream& operator>>(istream& is, DaThuc &dt){
    do{
        cout<<"nhap bac cua da thuc: "<<endl;
        is>>dt.n;
        if(dt.n<1)
            cout<<"bac cua da thuc >1,nhap lai "<<endl;   
    }while(dt.n<1);
    dt.heso =new int[dt.n];
    for(int i=0;i<=dt.n;i++){
        cout<<"n["<<i<<"] = ";
        is>>dt.heso[i];
    }
    return is;
}
ostream& operator<<(ostream& os, DaThuc &dt){
    if(dt.n==1&&dt.heso[1]>0){
        os<<dt.heso[0]<<" + "<<dt.heso[1]<<"x "<<endl;
    }else if(dt.n==1&&dt.heso[1]<0)
        os<<dt.heso[0]<<dt.heso[1]<<"x "<<endl;
    else{
        if(dt.heso[1]>0)
            os<<dt.heso[0]<<" + "<<dt.heso[1]<<"x + ";
        else if(dt.heso[1]<0)
            os<<dt.heso[0]<<dt.heso[1]<<"x + ";
        for(int i=2;i<=dt.n;i++){
            os<<dt.heso[i]<<"x^"<<i;
            if(i!=dt.n){
                os<<" + ";
            }
        }
    }
    cout<<"\n";
    return os;
}

DaThuc DaThuc::operator+(const DaThuc &dt){
    int max = (this->n > dt.n) ? this->n : dt.n;
    int min = (this->n < dt.n) ? this->n : dt.n;
    DaThuc sum=max;
    for(int i=0;i<=min;i++){
        sum.heso[i] = heso[i] + dt.heso[i];
    }
    for(int i=min+1;i<=max;i++){
        sum.heso[i] = (this->n == max) ? heso[i]:((n < dt.n) ? dt.heso[i] : heso[i]);
    }
    return sum;
}
DaThuc DaThuc::operator-(const DaThuc &dt){
    int max = (this->n > dt.n) ? this->n : dt.n;
    int min = (this->n < dt.n) ? this->n : dt.n;
    DaThuc sub=max;
    for(int i=0;i<=min;i++){
        sub.heso[i] = heso[i] - dt.heso[i];
    }
    for(int i=min+1;i<=max;i++){
        sub.heso[i] = (n == max) ? heso[i]:((n < dt.n) ? dt.heso[i] : heso[i]);
    }
    return sub;
}
int main(){
    DaThuc a,b;
    cout<<"nhap 2 da thuc: "<<endl;
    cin>>a>>b;
    cout<<"2 da thuc da nhap: \n";
    cout<<a<<b;
    DaThuc sum=a+b;
    DaThuc sub=a-b;
    cout<<"\ntong 2 da thuc: "<<endl;
    cout<<sum;
    cout<<"\nhieu 2 da thuc: \n ";
    cout<<sub;
    return 0;
}