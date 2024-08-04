/*Câu 16: Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp hình vuông với thuộc tính: độ dài cạnh.
Khai báo lớp hình chữ nhật kế thừa từ lớp hình vuông và thêm thuộc tính: độ dài cạnh thứ 2.
2.	Xây dựng các phương thức: nhập, xuất, tính chu vi, diện tích hình vuông, hình chữ nhật.
3.	Nhập vào n hình vuông. 
    In ra màn hình hình vuông có diện tích lớn nhất và vị trí của hình vuông đó trong danh sách vừa nhập.*/

#include<iostream>
#include<math.h>

using namespace std;

class hinhvuong{
    protected:
        float n;
};
class hinhchunhat : public hinhvuong{
    private:
        float m;
    public:
        friend istream& operator >> (istream& is,hinhchunhat& hinh);
        friend ostream& operator << (ostream& os,hinhchunhat& hinh);
        void timmaxcuahinhvuong(hinhchunhat [],int);
        float dientichhinhvuong(hinhchunhat);
        float chuvihinhvuong(hinhchunhat);
        float dientichhinhchunhat(hinhchunhat);
        float chuvihinhchunhat(hinhchunhat);
        bool check(hinhchunhat);
};

istream& operator >>(istream& is,hinhchunhat& hinh){
    cout<<"import canh1: ";is>>hinh.n;
    cout<<"import canh2: ";is>>hinh.m;
    return is;
}
ostream& operator << (ostream& os,hinhchunhat& hinh){
    os<<"canh1: "<<hinh.n<<endl;
    os<<"canh2: "<<hinh.m<<endl;
    return os;
}
float hinhchunhat::dientichhinhvuong(hinhchunhat hinh){
        return hinh.n*hinh.n;
}
float hinhchunhat::chuvihinhvuong(hinhchunhat hinh){
    return pow(hinh.n,4);
} 
float hinhchunhat::dientichhinhchunhat(hinhchunhat hinh){
    return hinh.m*hinh.n;
}
float hinhchunhat::chuvihinhchunhat(hinhchunhat hinh){
    return 2*(hinh.n+hinh.m);
}
bool hinhchunhat::check(hinhchunhat hinh){
    if(hinh.n!=hinh.m)
        return 0;
    return 1;
}
void hinhchunhat::timmaxcuahinhvuong(hinhchunhat hinh[],int x){
    float max=-1e9;
    int index;
    for(int i=0;i<x;i++){
        if(check(hinh[i])){
            if(max<hinh[i].dientichhinhvuong(hinh[i])){
                max=hinh[i].dientichhinhvuong(hinh[i]);
                index=i;
            }
        }
    }
    cout<<"\nHINH VUONG CO DIEN TICH LON NHAT\n";
    cout<<hinh[index];
    cout<<"VI TRI KHI CO DIEN TICH LON NHAT LA\n";
    cout<<index+1<<endl;
}

int main(){
    int x;
    cout<<"IMPORT SO LUONG HINH: ";cin>>x;
    cout<<"-------------------------------\n";
    hinhchunhat hinh[x];
    for(int i=0;i<x;i++){
        cout<<"import 2 canh cua hinh: "<<i+1<<endl;
        cin>>hinh[i];
    }
    cout<<"DANH SACH CAC CANH CUA CAC HINH SAU KHI NHAP\n";
    cout<<"-----------------------------------------------\n";
    for(int i=0;i<x;i++){
        cout<<"cac canh cua hinh: "<<i+1<<endl;
        cout<<hinh[i];
    }
    cout<<"HINH VUONG CO CANH LA DIEN TICH MAX and VI TRI\n";
    cout<<"-----------------------------------------------\n";
    hinh->timmaxcuahinhvuong(hinh,x);
    return 0;
}

