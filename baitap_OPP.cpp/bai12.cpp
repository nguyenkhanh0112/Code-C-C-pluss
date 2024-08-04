/*Câu 12: Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp môn học với các thuộc tính: tên môn học, điểm chuyên cần (CC), điểm kiểm tra (KT), điểm thi (DT).
Khai báo lớp sinh viên kế thừa từ lớp môn học và thêm các thuộc tính: họ tên, lớp, mã sinh viên.
2.	Xây dựng các phương thức: nhập, xuất, tính điểm học phần cho một sinh viên.
3.	Nhập vào n sinh viên. 
In ra màn hình thông tin các sinh viên bị cấm thi (điểm chuyên cần dưới 5 hoặc điểm kiểm tra bằng 0).*/


#include<iostream>

using namespace std;

class MonHoc{
    protected:
        string tenmonhoc;
        int CC;
        float KT,DT;
}; 
class SinhVien:public MonHoc{
    private:
        string hoten,lop,masv;
    public:
        void importSinhvien(SinhVien&);
        void exportSinhvien(SinhVien);
        void importNSinhvien(SinhVien [],int );
        void exportNSinhvien(SinhVien [],int );
        void KiemTraSinhvien(SinhVien [],int );
};
void SinhVien::importSinhvien(SinhVien &sv){
    cout<<"import hoten: ";getline(cin,sv.hoten);
    cout<<"import masv: ";getline(cin,sv.masv);
    cout<<"import lop: ";getline(cin,sv.lop);
    cout<<"import tenmonhoc: ";getline(cin,sv.tenmonhoc);
    cout<<"import DiemChuyenCan: ";cin>>sv.CC;
    cout<<"import diemkiemtra: ";cin>>sv.KT;
    cout<<"import diemthi: ";cin>>sv.DT;
}
void SinhVien::importNSinhvien(SinhVien sv[],int n){
    cout<<"IMPORT DANH SACH SINH VIEN\n";
    cout<<"----------------------------\n";
    for(int i=0;i<n;i++){
        cout<<"IMPORT SV THU: "<<i+1<<endl;
        cin.ignore();
        sv[i].importSinhvien(sv[i]);
    }
}
void SinhVien::exportSinhvien(SinhVien sv){
    cout<<"hoten: "<<sv.hoten<<"\n";
    cout<<"masv: "<<sv.masv<<"\n";
    cout<<"lop: "<<sv.lop<<"\n";
    cout<<"tenmonhoc: "<<sv.tenmonhoc<<"\n";
    cout<<"diemchuyencan: "<<sv.CC<<"\n";
    cout<<"diemkiemtra: "<<sv.KT<<"\n";
    cout<<"diemthi: "<<sv.DT<<endl;
}
void SinhVien::exportNSinhvien(SinhVien sv[],int n){
    cout<<"\n==>>DANH SACH SINH VIEN DA NHAP<<==\n";
    cout<<"---------------------------------\n";
    for(int i=0;i<n;i++){
        cout<<"THONG TIN SV THU: "<<i+1<<endl;
        sv[i].exportSinhvien(sv[i]);
    }
}
void SinhVien::KiemTraSinhvien(SinhVien sv[],int n){
    cout<<"\nDANH SACH SINH VIEN BI CAM THI\n";
    cout<<"-----------------------------------\n";
    for(int i=0;i<n;i++){
        if(sv[i].CC<5||sv[i].KT==0){
            sv[i].exportSinhvien(sv[i]);
        }
    }
}
int main(){
    int n;
    cout<<"NHAP SO LUONG SV: ";cin>>n;
    SinhVien sv[n];
    sv->importNSinhvien(sv,n);
    sv->exportNSinhvien(sv,n);
    sv->KiemTraSinhvien(sv,n);
    return 0;
}
