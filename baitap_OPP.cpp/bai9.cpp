/*Câu 9: Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp nhân viên với các thuộc tính: họ tên, chức vụ, giới tính, năm sinh, quê quán, năm vào làm.
2.	Xây dựng các toán tử >>, << để nhập, xuất một đối tượng nhân viên.
3.	Nhập vào n nhân viên. 
    In ra màn hình danh sách các nhân viên làm việc trên 20 năm (số năm làm việc bằng năm hiện tại trừ năm vào làm).*/

#include<iostream>

using namespace std;


class NhanVien{
    private:
        string hoten;
        string chucvu,gioitinh;
        int namsinh,namvaolam;
        string quequan;
    public:
        friend istream& operator >> (istream &in,NhanVien &nv);
        friend ostream& operator << (ostream &out,NhanVien nv);
        bool check(NhanVien);
};
istream& operator >>(istream &in,NhanVien &nv){
        cout<<"import hoten: ";getline(in,nv.hoten);
        cout<<"import gioi tinh: ";getline(in,nv.gioitinh);
        cout<<"import que quan: ";getline(in,nv.quequan);
        cout<<"import nam sinh: ";in>>nv.namsinh;
        cout<<"import nam vao lam: ";in>>nv.namvaolam;
    return in;
}
ostream& operator <<(ostream &out,NhanVien nv){
        out << "export hoten: " << nv.hoten << endl;
        out << "export gioi tinh: " << nv.gioitinh<< endl;
        out << "export que quan: " << nv.quequan<< endl;
        out << "export nam sinh: " << nv.namsinh<< endl;
        out << "export nam vao lam: "<< nv.namvaolam << endl;
    return out;
}
bool NhanVien::check(NhanVien nv){
    return (2022-nv.namvaolam) > 20 ? true : false;
}

int main(){
    int n;
    cout<<"NHAP SO LUONG NHAN VIEN: ";
    cin>>n;
    NhanVien *nv = new NhanVien[n];
    for(int i=0;i<n;i++){
        cout<<"NHAP THONG TIN NHAN VIEN THU: "<<i+1<<endl;
        cin.ignore();
        cin>>nv[i];
    }
    for(int i=0;i<n;i++){
        cout<<"THONG TIN NHAN VIEN THU: "<<i+1<<endl;
        cout<<nv[i];
    }
    cout<<"\n==>>DANH SACH NHAN VIEN LAM VIEC TREN 20 NAM<<==\n";
    for(int i=0;i<n;i++){
        if(nv->check(nv[i]))
            cout<<nv[i];
    }
    delete nv;
    return 0;
}
