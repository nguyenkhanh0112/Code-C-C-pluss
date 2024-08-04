/*Câu 28: Khởi động C++, 
tạo tập tin có tên D:\Bai1.CPP, sau đó viiết chương trình quản lý thi chứng chỉ tin học, theo yêu cầu:
- Chương trình có 3 lớp:
   + Lớp cơ sở Hoso lưu Ma (mã học sinh), Hodem (họ đệm), Ten (tên).
   + Lớp dẫn xuất Diem kế thừa lớp Hoso lưu dlt (điểm lý thuyết), dth (điểm thực hành).
   + Lớp dẫn xuất Ketqua kế thừa lớp Diem.
- Trong lớp Hoso có các hàm thành viên: Nhap_HS() và Hienthi_HS() để nhập và hiển thị các dữ liệu thành viên của lớp Hoso.
- Trong lớp Diem có các hàm thành viên: Nhap_d() để nhâp dữ liệu thành viên của lớp Diem và hàm Hienthi_d() để hiển thị dữ liệu thành viên của lớp Diem().
- Trong lớp Ketqua chỉ có hàm Hienthi_KQ()  cho phép hiển thị danh sách thí sinh đậu (các thí sinh có điểm lý thuyết >= 5 và điểm thực hành >= 5)
Trong hàm main() khới tạo các đối tượng cần thiết và tiến hành cho nhập thông tin của n thí sinh từ bàn phím. 
Sau đó, chương trình cho phép hiển thị lên màn hình danh sách thí sinh đậu kỳ thi chứng chỉ.
*/
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Hoso{
   protected:
      string mahocsinh,hodem,ten;
   public:
      void nhap_hs(){
         cout<<"nhap ma hoc sinh: ";
         getline(cin,mahocsinh);
         cout<<"nhap ho dem: ";
         getline(cin,hodem);
         cout<<"nhap ten: ";
         getline(cin,ten);
      }
      void xuat_hs(){
         cout<<mahocsinh<<endl;
         cout<<hodem<<" ";
         cout<<ten<<"\n";
      }
};
class diem:public Hoso{
   protected:
      float diemlt,dth;
   public:
      void nhap_diem(){
         cout<<"nhap diem ly thuyet: ";cin>>diemlt;
         cout<<"nhap diem thuc hanh: ";cin>>dth;
      }
      void xuat_diem(){
         cout<<"diemlt: "<<diemlt<<endl;
         cout<<"diemth: "<<dth<<endl;
      }
};
class ketqua:public diem{
   public:
      void hienthi_ketqua(){
         if(diemlt>=5&&dth>=5){
            xuat_hs();
            xuat_diem();
         }
      }
};
int main(){
   int n;
   cout<<"nhap so luong thi sinh: ";
   cin>>n;
   ketqua thisinh[n];
   cout<<"\nnhap thi sinh trong ki thi chung chi\n";
   for(int i=0;i<n;i++){
      cout<<"thi sinh thu: "<<i+1<<endl;
      cin.ignore();
      thisinh[i].nhap_hs();
      thisinh[i].nhap_diem();
   }
   cout<<"\ndanh sach thi sinh dau trong ki thi chung chi\n ";
   for(int i=0;i<n;i++){
      thisinh[i].hienthi_ketqua();
   }
   return 0;
}