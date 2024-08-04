/*Câu 11: Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp nhân sự với các thuộc tính: mã nhân viên, họ tên, năm sinh.
Khai báo lớp công nhân kế thừa từ lớp nhân sự và thêm thuộc tính: ngày công.
2.	Xây dựng các phương thức: nhập, xuất cho các đối tượng nhân sự, công nhân.
Nhập vào n công nhân. 
    Thực hiện tính tiền thưởng cho công nhân 100.000 với mỗi ngày công làm thêm nếu ngày công lớn hơn 26. 
    In ra màn hình danh sách các công nhân được thưởng và số tiền thưởng tương ứng.
*/

#include<iostream>
#include<iomanip>
#include<string.h>
#include<string>

using namespace std;


class NhanSu{
    protected:
        string manv,hoten;
        int namsinh;
};

class CongNhan :public NhanSu{
    private:
        int ngaycong;
    public:
        void importCongNhan(CongNhan&);
        void exportCongNhan(CongNhan);
        void importNCongNhan(CongNhan *,int);
        void exportNCongNhan(CongNhan *,int);
        void KiemtraCongNhan(CongNhan *,int);
        int TienThuong(CongNhan&);
};
void CongNhan::importCongNhan(CongNhan &CN){
    cout<<"\nImprot manv: ";getline(cin,CN.manv);
    cout<<"\nImport ho ten: ";getline(cin,CN.hoten);
    cout<<"\nImport nam sinh: ";cin>>CN.namsinh;
    cout<<"\nImport ngay cong: ";cin>>CN.ngaycong;
}
void CongNhan::exportCongNhan(CongNhan CN){
    cout<<"export manv: "<<CN.manv<<endl;
    cout<<"export ho ten: "<<CN.hoten<<endl;  
    cout<<"export nam sinh: "<<CN.namsinh<<endl;
    cout<<"export ngay cong: "<<CN.ngaycong<<endl;
}
void CongNhan::importNCongNhan(CongNhan *CN,int n){
    cout<<"IMPORT DANH SACH CONG NHAN\n";
    cout<<"----------------------------------\n";
    for(int i=0;i<n;i++){
        cout<<"IMPORT CONG NHAN THU: "<<i+1<<endl;
        cin.ignore();
        CN[i].importCongNhan(CN[i]);
    }
}
void CongNhan::exportNCongNhan(CongNhan *CN,int n){
    cout<<"DANH SACH CONG NHAN DA NHAP\n";
    cout<<"-----------------------------------\n";
    for(int i=0;i<n;i++){
        cout<<"CONG NHAN THU: "<<i+1<<endl;
        CN[i].exportCongNhan(CN[i]);
    }
}
int CongNhan::TienThuong(CongNhan &CN){
    return CN.ngaycong*100000;
}
void CongNhan::KiemtraCongNhan(CongNhan *CN,int n){
    cout<<"DANH SACH CONG NHAN DUOC THUONG\n";
    cout<<"---------------------------------\n";
    for(int i=0;i<n;i++){
        if(CN[i].ngaycong>26){
            cout<<"CONG NHAN THU: "<<i+1<<endl;
            CN[i].exportCongNhan(CN[i]);
            cout<<"SO TIEN THUONG: "<<CN[i].TienThuong(CN[i])<<endl;
        }
    }
}
int main(){
    int n;
    cout<<"NHAP SO LUONG CONG NHAN: ";cin>>n;
    CongNhan *CN=new CongNhan[n];
    CN->importNCongNhan(CN,n);
    CN->exportNCongNhan(CN,n);
    CN->KiemtraCongNhan(CN,n);
    delete CN;
    return 0;
}