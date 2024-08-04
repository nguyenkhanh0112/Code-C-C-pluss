/*Câu 15: Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp cán bộ với các thuộc tính: mã cán bộ, mã đơn vị, họ tên, năm sinh.
Khai báo lớp lương kế thừa từ lớp cán bộ và thêm các thuộc tính: phụ cấp, hệ số lương, bảo hiểm.
2.	Xây dựng các phương thức: nhập, xuất cho các đối tượng cán bộ, lương.
Nhập vào n cán bộ. 
    Tính lương cho cán bộ theo công thức: lương = hệ số lương * 290.000 + phụ cấp – bảo hiểm. 
    In kết quả ra màn hình*/
#include<iostream>

using namespace std;

class CanBo{
    protected:
        string macb,madv,hoten,namsinh;
};

class Luong:public CanBo{
    private:
        int phucap,hesoluong;
        int baohiem;
    public:
        Luong(){}
        Luong(string macb,string madv,string hoten,string namsinh,int phucap,int hesoluong,int baohiem){
            this->macb=macb;
            this->madv=madv;
            this->hoten=hoten;
            this->namsinh=namsinh;
            this->phucap=phucap;
            this->hesoluong=hesoluong;
            this->baohiem=baohiem;
        }
        friend istream& operator >> (istream& is,Luong &CB);
        friend ostream& operator << (ostream& os,Luong &CB);
        long long  LuongCanBo(Luong);
};

istream& operator >> (istream& is,Luong &CB){
    cout<<"import macb: ";getline(is,CB.macb);
    cout<<"import madv: ";getline(is,CB.madv);
    cout<<"import hoten: ";getline(is,CB.hoten);
    cout<<"import namsinh: ";is>>CB.namsinh;
    cout<<"import phucap: ";is>>CB.phucap;
    cout<<"import hesoluong: ";is>>CB.hesoluong;
    cout<<"import baohiem: ";is>>CB.baohiem;
    return is;
}
long long Luong::LuongCanBo(Luong CB){
    return CB.hesoluong*290.000+CB.phucap-CB.baohiem;
}
ostream& operator << (ostream& os,Luong &CB){
    os<<"\tmacb: "<<CB.macb<<endl;
    os<<"\tmadv: "<<CB.madv<<endl;
    os<<"\thoten: "<<CB.hoten<<endl;
    os<<"\tnamsinh: "<<CB.namsinh<<endl;
    os<<"\tphucap: "<<CB.phucap<<endl;
    os<<"\thesoluong: "<<CB.hesoluong<<endl;
    os<<"\tbaohiem: "<<CB.baohiem<<endl;
    os<<"\tluong: "<<CB.LuongCanBo(CB)<<endl;
    return os;
} 
int main(){
    int n;
    cout<<"\tNHAP SO LUONG CAN BO VA LUONG: ";cin>>n;
    Luong CB[n];
    cout<<"\t-----------------------------\n";
    for(int i=0;i<n;i++){
        cout<<"\tIMPORT CB VA LUONG THU: "<<i+1<<endl;
        cin.ignore();
        cin>>CB[i];
    }
    cout<<"\t----------------------------------\n";
    cout<<"\tDANH SACH CAC CB VA LUONG DA NHAP\n";
    for(int i=0;i<n;i++){
        cout<<"\tCB VA LUONG THU: "<<i+1<<endl;
        cout<<CB[i];
    }
    return 0;
}

