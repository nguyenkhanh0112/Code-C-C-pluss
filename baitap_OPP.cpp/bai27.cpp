/*Câu 27: Nhân viên trong một cơ quan được lĩnh lương theo các dạng khác nhau. 
Dạng người lao động hưởng lương từ ngân sách Nhà nước gọi là cán bộ, công chức (dạng biên chế). 
Dạng người lao động lĩnh lương từ ngân sách của cơ quan gọi là người làm hợp đồng. 
Như vậy, trong hệ thống cấp phát lương có 2 dạng: biên chế và hợp đồng. 
Hai loại đối tượng này có đặc tính chung là viên chức làm việc cho cơ quan. 
Trong bảng lương với mỗi viên chức, cần quản lý các thông tin: Mã số, họ tên, chức vụ. 
Ngoài ra với viên chức là biên chế cần biết thêm thông tin: Hệ số lương, với mỗi viên chức là hợp đồng cần biết thêm thông tin: số ngày làm việc trong tháng.
Anh (Chị) hãy viết chương trình hướng đối tượng, trong đó xây dựng lớp cơ sở và các lớp dẫn xuất với các dữ liệu thành viên và các hàm cần thiết để thực hiện các yêu cầu sau: 
1.	Nhập dữ liệu cho cán bộ, nhân viên trong biên chế và nhân viên hợp đồng. 
Dữ liệu được lưu trong mảng các đối tượng.
2.	In ra màn hình bảng lương theo mẫu:
     BẢNG DANH SÁCH TIỀN LƯƠNG CÁN BỘ BIÊN CHẾ 
      STT              Họ tên              Hệ số lương                 Tiền lương
     BẢNG DANH SÁCH TIỀN LƯƠNG CÁN BỘ HỢP ĐỒNG
       STT              Họ tên            Số ngày làm việc            Tiền lương
Biết rằng:  Tiền lương (cán bộ biên chế) = Hệ số lương x 830000 + PCCV - BHXH
                         Tiền lương (cán bộ hợp đồng) = 1500000 + tiền tăng giờ - BHXH
		      BHXH = 5% * Tiền lương	
		      PCCV (phụ cấp chức vụ) được tính theo quy định: Giám đốc: 150000, Phó giám đốc: 100000, các chức vụ khác không có PCCV.
		     Tiền tăng giờ: Nếu cán bộ hợp đồng làm việc trên 26 ngày /tháng thì mỗi ngày dôi ra được tính bồi dưỡng 100000 đ/ngày, làm việc dưới 26 ngày/tháng thì mỗi ngày nghỉ bị trừ 50000đ.
*/
#include<iostream>
#include<bits/stdc++.h>
#include<iomanip>

using namespace std;

class Nguoi{
  protected:
    int maso;
    int luong;
    string hoten;
  public:
    void nhap(){
      cout<<"nhap maso: ";cin>>maso;
      cout<<"nhap luong: ";cin>>luong;
      cin.ignore();
      cout<<"nhap hoten: ";getline(cin,hoten);
    }
};

class bienche:public Nguoi{
  private:
    int hesoluong;
    int PCCV;
    int tienluong;
    string chucvu;
  public:
    void nhapbienche(bienche [],int );
    void xuatbienche(bienche [],int);
};
void bienche::nhapbienche(bienche vienchuc[],int n){
  cout<<"NHAP DANH SACH VIEN CHUC BIEN CHE"<<endl;
    for(int i=0;i<n;i++){
      vienchuc[i].nhap();
      cout<<"nhap he so luong: ";cin>>vienchuc[i].hesoluong;
      cin.ignore();
      cout<<"nhap chuc vu: ";getline(cin,vienchuc[i].chucvu);
    }
}
void bienche::xuatbienche(bienche vienchuc[], int n){
    cout<<"\nBANG DANH SACH TIEN LUONG CAN BO BIEN CHE\n";
      cout<<setw(5)<<left<<"STT";
      cout<<setw(30)<<left<<"Ho Ten";
      cout<<setw(20)<<left<<"He So Luong";
      cout<<setw(20)<<right<<"Tien Luong"<<endl;
    for(int i=0;i<n;i++){
      if(vienchuc[i].chucvu=="giam doc")
        vienchuc[i].PCCV=150000;
      else if(vienchuc[i].chucvu=="pho giam doc")
        vienchuc[i].PCCV=100000;
      else 
        vienchuc[i].PCCV=0;
      vienchuc[i].tienluong=vienchuc[i].hesoluong*vienchuc[i].luong+vienchuc[i].PCCV-(0.05*(vienchuc[i].hesoluong*vienchuc[i].luong+vienchuc[i].PCCV));
      cout<<setw(5)<<left<<i+1;
      cout<<setw(30)<<left<<vienchuc[i].hoten;
      cout<<setw(20)<<left<<vienchuc[i].hesoluong;
      cout<<setw(20)<<right<<vienchuc[i].tienluong;
  }
}
class hopdong:public Nguoi{
  private:
    int songaylam;
    int tientanggio;
    int tienluong;
  public:
    void nhaphopdong(hopdong [], int );
    void xuathopdong(hopdong [],int );
};
void hopdong::nhaphopdong(hopdong vienchuc[],int n){
  cout<<"\nNHAP DANH SACH VIEN CHUC HOP DONG"<<endl;
    for(int i=0;i<n;i++){
      vienchuc[i].nhap();
      cout<<"nhap so ngay lam: ";cin>>vienchuc[i].songaylam;
      if(vienchuc[i].songaylam>26)
        vienchuc[i].tientanggio=vienchuc[i].songaylam*100000;
      else 
        vienchuc[i].tientanggio=(26-vienchuc[i].songaylam)*50000;
      vienchuc[i].tienluong=vienchuc[i].luong+vienchuc[i].tientanggio-(0.05*1.0*(vienchuc[i].luong+vienchuc[i].tientanggio));
    }
}
void hopdong::xuathopdong(hopdong vienchuc[],int n){
  cout<<"\nBANG DANH SACH TIEN LUONG CAN BO HOP DONG\n";
      cout<<setw(5)<<left<<"STT";
      cout<<setw(30)<<left<<"Ho Ten";
      cout<<setw(20)<<left<<"So Ngay Lam Viec";
      cout<<setw(20)<<right<<"Tien Luong"<<endl;
  for(int i=0;i<n;i++){
    cout<<setw(5)<<left<<i+1;
    cout<<setw(30)<<left<<vienchuc[i].hoten;
    cout<<setw(20)<<left<<vienchuc[i].songaylam;
    cout<<setw(20)<<right<<vienchuc[i].tienluong<<endl;
  }
}
int main(){
  int n;
  cout<<"nhap so luong vien chuc hop dong va bien che: ";
  cin>>n;
  bienche vienchuc[n];
  hopdong vienchuc1[n];
  vienchuc->nhapbienche(vienchuc,n);
  vienchuc1->nhaphopdong(vienchuc1,n);
  vienchuc->xuatbienche(vienchuc,n);
  vienchuc1->xuathopdong(vienchuc1,n);
  return 0;
}



