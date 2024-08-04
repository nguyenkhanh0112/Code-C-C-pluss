/*Câu 14: Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp người với các thuộc tính: họ tên, năm sinh.
Khai báo lớp giảng viên kế thừa từ lớp người và thêm các thuộc tính: bộ môn công tác, môn đang giảng dạy.
2.	Xây dựng các phương thức: nhập, xuất cho các đối tượng người, giảng viên.
3.	Nhập vào n giảng  viên. Sắp xếp lại và in ra màn hình danh sách giảng viên theo từng bộ môn công tác*/

#include<iostream>
#include<math.h>
#include<string.h>
#include<string>

using namespace std;

class nguoi{
    protected:
        string hoten,namsinh;
};
class GiangVien :public nguoi{
    private:
        string bomoncongtac,mondanggiangday;
    public:
        void importGiangvien(GiangVien &);
        void exportGiangvien(GiangVien);
        void importNGiangvien(GiangVien*,int);
        void exportNGiangvien(GiangVien*,int);
        void sapxepgiangvien(GiangVien*,int);
};
void GiangVien::importGiangvien(GiangVien &GV){
    cout<<"import hoten: ";getline(cin,GV.hoten);
    cout<<"import namsinh: ";getline(cin,GV.hoten);
    cout<<"import bomoncongtac: ";getline(cin,GV.bomoncongtac);
    cout<<"import mondanggiangday: ";getline(cin,GV.mondanggiangday);
}
void GiangVien::importNGiangvien(GiangVien *GV,int n){
    cout<<"----------------------------\n";
    for(int i=0;i<n;i++){
        cout<<"IMPORT INT NUMBER GIANGVIEN THU: "<<i+1<<endl;
        cin.ignore();
        GV[i].importGiangvien(GV[i]);
    }
}
void GiangVien::exportGiangvien(GiangVien GV){
    cout<<"\thoten: "<<GV.hoten<<"\n";
    cout<<"\tnamsinh: "<<GV.namsinh<<"\n";
    cout<<"\tbomoncongtac: "<<GV.bomoncongtac<<"\n";
    cout<<"\tmondanggiangday: "<<GV.mondanggiangday<<"\n";
}
void GiangVien::exportNGiangvien(GiangVien *GV,int n){
    cout<<"------------------------------\n";
    cout<<"DANH SACH GIANG VIEN CHUA SAPXEP\n";
    for(int i=0;i<n;i++){
        cout<<"EXPORT IN GIANG VIEN THU: "<<i+1<<"\n";
        GV[i].exportGiangvien(GV[i]);
    }
}
void GiangVien::sapxepgiangvien(GiangVien *GV,int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(GV[i].bomoncongtac.size()>GV[j].bomoncongtac.size()){
                GiangVien temp=GV[i];
                GV[i]=GV[j];
                GV[j]=temp;
            }
        }
    }
}
int main(){
    int n;
    cout<<"IMPORT SO LUONG GIANG VIEN: ";cin>>n;
    GiangVien *GV= new GiangVien[n];
    GV->importNGiangvien(GV,n);
    GV->exportNGiangvien(GV,n);
    GV->sapxepgiangvien(GV,n);
    cout<<"\nDANH SACH GIANG VIEN DA SAPXEP\n";
    GV->exportNGiangvien(GV,n);
    return 0;
}
